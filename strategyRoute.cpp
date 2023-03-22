#include <iostream>

// Strategy is a behavioral design pattern that turns 
//a set of behaviors into objects and makes them 
//interchangeable inside original context object.


class RouteStrategy {
public: 
    virtual void builtRoute() = 0;
};

class Road : public RouteStrategy {
public:
    void builtRoute() override {
        std::cout << "Road Strategy" << std::endl;
    }
};

class Walking : public RouteStrategy {
public:
    void builtRoute() override {
        std::cout << "Walking Strategy" << std::endl;
    }
};

class PublicTransport : public RouteStrategy {
public:
    void builtRoute() override {
        std::cout << "Public transport strategy" << std::endl;
    }
};

class Navigator {
private:
    RouteStrategy* _rs;
public:
    Navigator(RouteStrategy* rs) : _rs{rs} {}

    void builtRoute() {
        _rs->builtRoute();
    }

    void changeRoute(RouteStrategy* rs) {
        _rs = rs;
    }
};


int main() {
    Road* r = new Road();
    Navigator nv(r);
    nv.builtRoute();

    Walking* w = new Walking();
    nv.changeRoute(w);
    nv.builtRoute();

    PublicTransport* p = new PublicTransport();
    nv.changeRoute(p);
    nv.builtRoute();

    delete r;
    delete w;
    delete p;
}