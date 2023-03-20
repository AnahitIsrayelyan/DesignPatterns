#include <iostream>
#include <vector>

#define LIMIT 5

class Multiton {
private:
    static std::vector<Multiton*> _instances;
    static int _limit;
    static int _currentIndex;
    int _value;
    Multiton() { _value = _currentIndex + 1; }
public:
    static Multiton* getInstance() {
        if (!Multiton::_instances[_currentIndex % _limit]) {
            Multiton::_instances[_currentIndex % _limit] = new Multiton();
        }
        return Multiton::_instances[_currentIndex++ % _limit];
    }

    static int reserverSize() {
        Multiton::_instances.reserve(LIMIT);
        for (int i = 0; i < LIMIT; ++i) {
            Multiton::_instances[i] = NULL;
        }
        return LIMIT;
    }

    void value() {
        std::cout << _value << std::endl;
    }
};

std::vector<Multiton*> Multiton::_instances;
int Multiton::_limit = Multiton::reserverSize();
int Multiton::_currentIndex = 0;

int main() {
    Multiton::getInstance()->value();
    Multiton::getInstance()->value();
    Multiton::getInstance()->value();
    Multiton::getInstance()->value();
    Multiton::getInstance()->value();
    Multiton::getInstance()->value();
}
