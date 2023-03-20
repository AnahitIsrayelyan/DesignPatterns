#include <iostream>

class Singleton {
private:
    Singleton(const std::string& value) : _value{value} {};
    static Singleton* _singleton;
    std::string _value;
public:
    Singleton(Singleton&) = delete;    
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance(const std::string& value) {
        if (_singleton == nullptr) {
            _singleton = new Singleton(value);
        }
        return _singleton;
    }

    void value() { 
        std::cout << _value;
    }
};

Singleton* Singleton::_singleton = nullptr;

int main() {
    Singleton* s = Singleton::getInstance("A");
    s->value();
    Singleton* s2 = Singleton::getInstance("B");
    s2->value();
}