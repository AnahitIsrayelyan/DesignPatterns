#include <iostream>

class Phone {
private:
    std::string _info;
public:
    Phone() { _info = ""; }

    void printInfo() {
        std::cout << _info << std::endl;
    }
    void appendInfo(std::string str) {
        _info += str;
    }
};

class Ideveloper {
public:
    virtual void createBox() = 0;
    virtual void createDisplay() = 0;
    virtual void installSystem() = 0;

    virtual Phone* getPhone() = 0;
};

class SamsungDeveloper : public Ideveloper {
private:
    Phone* _phone;
public:
    SamsungDeveloper() {
        _phone = new Phone();
    }
    ~SamsungDeveloper() {
        delete _phone;
    }

    void createBox() override {
        _phone->appendInfo("Samsung Box created; ");
    }
    void createDisplay() override {
        _phone->appendInfo("Samsung Display created; ");
    }
    void installSystem() override {
        _phone->appendInfo("Android installed; ");
    }

    Phone* getPhone() override {
        return _phone;
    }
};

class IPhoneDeveloper : public Ideveloper {
private:
    Phone* _phone;
public:
    IPhoneDeveloper() {
        _phone = new Phone();
    }
    ~IPhoneDeveloper() {
        delete _phone;
    }

    void createBox() override {
        _phone->appendInfo("iPhone box created; ");
    }
    void createDisplay() override {
        _phone->appendInfo("iPhone Display created; ");
    }
    void installSystem() override {
        _phone->appendInfo("iOS installed; ");
    }

    Phone* getPhone() override {
        return _phone;
    }
};

class Director {
private:
    Ideveloper* _dev;
public:
    Director(Ideveloper* dev) : _dev{dev} {}

    void setDeveloper(Ideveloper* dev) {
        _dev = dev;
    }

    Phone* partPhone() {
        _dev->createBox();
        _dev->createDisplay();

        return _dev->getPhone();
    }
    Phone* fullPhone() {
        _dev->createBox();
        _dev->createDisplay();
        _dev->installSystem();

        return _dev->getPhone();
    }
};


int main() {
    Ideveloper* samsung = new SamsungDeveloper();
    Director dir(samsung);

    Phone* sam = dir.fullPhone();
    sam->printInfo();

    Ideveloper* iphone = new IPhoneDeveloper();
    dir.setDeveloper(iphone);

    Phone* ip = dir.partPhone();
    ip->printInfo();

    delete samsung;
    delete iphone;
}