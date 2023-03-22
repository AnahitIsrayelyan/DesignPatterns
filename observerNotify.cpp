#include <iostream>
#include <vector>


class IObserver {
public:
    virtual void update(double) = 0;
};

class IObservable {
public:
    virtual void addObserver(IObserver*) = 0;
    // virtual void removeObserver(IObserver*) = 0;

    virtual void notify() = 0;
};

class Product : public IObservable {
private:
    std::vector<IObserver*> _observers;
    double _price;
public:
    Product(double p) : _price{p} {}

    void changePrice(double p) {
        _price = p;
        notify();
    }
    void notify() override {
        for (auto obs : _observers) {
            obs->update(_price);
        }
    }
    void addObserver(IObserver* obs) override {
        _observers.push_back(obs);
    }
    // void removeObserver(IObserver* obs) override {
    //     _observers.erase(std::remove(_observers.begin(), _observers.end(), obs), _observers.end());
    // }
};

class Wholesaler : public IObserver {
private:
    IObservable* _observable;
public:
    Wholesaler(IObservable* prod) : _observable{prod} {
        prod->addObserver(this);
    }
    void update(double p) {
        if (p < 300) {
            std::cout << "Discount for wholesaler." << std::endl;
        }
    }
};

class Buyer : public IObserver {
private: 
    IObservable* _observable;
public:
    Buyer(IObservable* prod) : _observable{prod} {
        prod->addObserver(this);
    }
    void update(double p) {
        if (p < 350) {
            std::cout << "Discount for buyer." << std::endl;
        }
    }
};


int main() {
    Product p(500);
    Buyer* buyer1 = new Buyer(&p);
    Wholesaler* wh = new Wholesaler(&p);

    p.changePrice(340);

    std::cout << "_____________" << std::endl;

    p.changePrice(250);

    delete buyer1;
    delete wh;
}