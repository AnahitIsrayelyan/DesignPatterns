#include <iostream>

// Facade is a structural design pattern that provides a simplified 
// (but limited) interface to a complex system of classes, library or framework.


class Restaurant {
public:
    void orderSmth() {
        std::cout << "Ordered from restaurant." << std::endl;
    }
    void payForOrder() {
        std::cout << "Paid to restaurant." << std::endl;
    }
};

class Delivery {
public:
    void deliver() {
        std::cout << "Deliver." << std::endl;
    }
    void payForDelivery() {
        std::cout << "Paid for delivery." << std::endl;
    }
};

class BankAccount {
public:
    void withdrawMoney() {
        std::cout << "Withdraw from bankaccount." << std::endl;
    }
};

// Order is our facade class, which delegates its behavior and
// gives simplified interface for complex system

class Order {
private:
    Restaurant* _rest;
    Delivery* _del;
    BankAccount* _ba;
public: 
    Order(Restaurant* rest = nullptr,
            Delivery* del = nullptr,
            BankAccount* ba = nullptr) {
        _rest = rest ?: new Restaurant();
        _del = del ?: new Delivery();
        _ba = ba ?: new BankAccount();
    }

    void makeOrder() {
        _rest->orderSmth();
        _del->deliver();
    }

    void payForOrder() {
        _rest->payForOrder();
        _del->payForDelivery();
        _ba->withdrawMoney();
    }
};


int main() {
    Order o;
    o.makeOrder();

    std::cout << "____________" << std::endl;

    o.payForOrder();
}