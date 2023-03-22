#include <iostream>

class DataReader {
public:
    virtual void read() = 0;
};

class DataBaseReader : public DataReader {
public:
    void read() override {
        std::cout << "Data from DB ";
    }
};

class FileReader : public DataReader {
public:
    void read() override {
        std::cout << "Data from file ";
    }
};

class Sender {
protected:
    DataReader* _dr;
public:
    Sender(DataReader* dr) : _dr{dr} {}

    virtual void send() = 0;
};

class EmailSender : public Sender {
public:
    EmailSender(DataReader* dr) : Sender(dr) {}

    void send() override {
        _dr->read();
        std::cout << "was sent by email." << std::endl;
    }
};

class TelegramSender : public Sender {
public:
    TelegramSender(DataReader* dr) : Sender(dr) {}

    void send() {
        _dr->read();
        std::cout << "was sent by telegram." << std::endl;
    }
};


int main() {
    Sender* sender1 = new EmailSender(new DataBaseReader());
    sender1->send();

    Sender* sender2 = new TelegramSender(new FileReader());
    sender2->send();

    delete sender1;
    delete sender2;
}