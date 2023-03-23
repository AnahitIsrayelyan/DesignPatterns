#include <iostream>

class Car;
class Airplane;
class Bicycle;

// visitor interface

class VehicleWasher {
public:
    virtual ~VehicleWasher() = default;
    virtual void wash(Car*) = 0;
    virtual void wash(Airplane*) = 0;
    virtual void wash(Bicycle*) = 0;
};

class WasherA : public VehicleWasher {
public:
    void wash(Car* car) {
        std::cout << "washer A for car" << std::endl;
    }
    void wash(Airplane* ap) {
        std::cout << "washer A for airplane" << std::endl;
    }
    void wash(Bicycle* b) {
        std::cout << "washer A for bicycle" << std::endl;
    }
};

class WasherB : public VehicleWasher {
public:
    void wash(Car* car) {
        std::cout << "washer B for car" << std::endl;
    }
    void wash(Airplane* ap) {
        std::cout << "washer B for airplane" << std::endl;
    }
    void wash(Bicycle* b) {
        std::cout << "washer B for bicycle" << std::endl;
    }
};

class Vehicle {
public:
    virtual ~Vehicle() = default;
    virtual void accept(VehicleWasher*) = 0;
};

class Car : public Vehicle {
public:
    void accept(VehicleWasher* washer) override {
        std::cout << "Car: ";
        washer->wash(this);
    }
};

class Airplane : public Vehicle {
public:
    void accept(VehicleWasher* washer) override {
        std::cout << "Airplane: ";
        washer->wash(this);
    }
};

class Bicycle : public Vehicle {
public:
    void accept(VehicleWasher* washer) override {
        std::cout << "Bicycle: ";
        washer->wash(this);
    }
};


// so we can add other VehicleWashers without altering the existing code


int main() {
    Car car;
    Airplane ap;
    Bicycle bc;

    Vehicle* vehicles[] = { &car, &ap, &bc};

    for (auto v : vehicles) {
        WasherA washer;
        v->accept(&washer);
    }

    std::cout << "______________" << std::endl;

    for (auto v : vehicles) {
        WasherB washer;
        v->accept(&washer);
    }
}