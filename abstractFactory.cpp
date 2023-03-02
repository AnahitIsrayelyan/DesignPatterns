#include <iostream>

// products -> chair, sofa, coffeeTable 
// factories -> modern, victorian, artDeco

// chairs

class Chair {
public:
    virtual ~Chair() = default;
    virtual std::string sitOn() const = 0;
};

class ModernChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sit on MODERN chair ";
    }
};

class VictorianChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sit on VICTORIAN chair ";
    }
};

class ArtDecoChair : public Chair {
public:
    std::string sitOn() const override {
        return "Sit on ARTDECO chair ";
    }
};

// sofas
// sofas collaborate with chairs of the same type

class Sofa {
public:
    ~Sofa() = default;
    virtual std::string layOn() const = 0;
    virtual std::string beLike(const Chair& chair) const {
        return "You can " + this->layOn() + chair.sitOn();
    }
};

class ModernSofa : public Sofa {
public:
    std::string layOn() const override {
        return "Lay on MODERN sofa ";
    }
};

class VictorianSofa : public Sofa {
public:
    std::string layOn() const override {
        return "Lay on VICTORIAN sofa ";
    }
};

class ArtDecoSofa : public Sofa {
public:
    std::string layOn() const override {
        return "Lay on ARTDECO sofa ";
    }
};

// coffeeTables

class CoffeeTable {
public:
    virtual ~CoffeeTable() = default;
    virtual std::string cofeeOnTable() const = 0;
    virtual std::string sitAside(const Chair&) const = 0;
};

class ModernCoffeeTable : public CoffeeTable {
public:
    std::string cofeeOnTable() const override {
        return "Coffee is on a MODERN coffee table ";
    }

    std::string sitAside(const Chair& chair) const override {
        return chair.sitOn() + ", " + this->cofeeOnTable(); 
    }
};

class VictorianCoffeeTable : public CoffeeTable {
public:
    std::string cofeeOnTable() const override {
        return "Coffee is on a VICTORIAN coffee table ";
    }

    std::string sitAside(const Chair& chair) const override {
        return chair.sitOn() + ", " + this->cofeeOnTable(); 
    }
};

class ArtDecoCoffeeTable : public CoffeeTable {
public:
    std::string cofeeOnTable() const override {
        return "Coffee is on a ARTDECO coffee table ";
    }

    std::string sitAside(const Chair& chair) const override {
        return chair.sitOn() + ", " + this->cofeeOnTable(); 
    }
};

// factories
// each factory guarantees that all products belong to the same type

class AbstractFactory {
public:
    virtual Chair* createChair() const = 0;
    virtual Sofa* createSofa() const = 0;
    virtual CoffeeTable* createCoffeeTable() const = 0;
};

class ModernFactory : public AbstractFactory {
public:
    Chair* createChair() const override {
        return new ModernChair();
    }
    Sofa* createSofa() const override {
        return new ModernSofa();
    }
    CoffeeTable* createCoffeeTable() const override {
        return new ModernCoffeeTable();
    }
};

class VictorianFactory : public AbstractFactory {
public:
    Chair* createChair() const override {
        return new VictorianChair();
    }
    Sofa* createSofa() const override {
        return new VictorianSofa();
    }
    CoffeeTable* createCoffeeTable() const override {
        return new VictorianCoffeeTable();
    }
};

class ArtDecoFactory : public AbstractFactory {
public:
    Chair* createChair() const override {
        return new ArtDecoChair();
    }
    Sofa* createSofa() const override {
        return new ArtDecoSofa();
    }
    CoffeeTable* createCoffeeTable() const override {
        return new ArtDecoCoffeeTable();
    }
};

void ClientCode(const AbstractFactory& factory) {
    const Chair* chair = factory.createChair();
    const Sofa* sofa = factory.createSofa();
    const CoffeeTable* table = factory.createCoffeeTable();
    std::cout << chair->sitOn() << std::endl;
    std::cout << sofa->layOn() << std::endl;
    std::cout << sofa->beLike(*chair) << std::endl;
    std::cout << table->cofeeOnTable() << std::endl;
    std::cout << table->sitAside(*chair) << std::endl;

    delete chair;
    delete sofa;
    delete table;
}

int main() {
    AbstractFactory* modern = new ModernFactory();
    ClientCode(*modern);

    std::cout << "_______________" << std::endl;

    AbstractFactory* vic = new VictorianFactory();
    ClientCode(*vic);

    std::cout << "_______________" << std::endl;

    AbstractFactory* ad = new ArtDecoFactory();
    ClientCode(*ad);

    delete modern;
    delete vic;
    delete ad;

    return 0;    
}