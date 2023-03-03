#include <iostream>

// Notifier class is the interface, which must be implemented by both components and decorators
class Notifier {
public:
    virtual ~Notifier() = default;
    virtual std::string notify() = 0;
};

// specifies a message to be notified
class FireNotifier : public Notifier {
public:
    std::string notify() override { 
        return "Fire!"; 
    }
};

// each decorator will override and implement the behavior in a specific way
class Message : public Notifier {
protected:
    Notifier* m_notifier;
public:
    Message(Notifier* note) : m_notifier(note) {};
    std::string notify() override {
        return m_notifier->notify();
    }
};

class FBMessage : public Message {
public:
    FBMessage(Notifier* note) : Message(note) {};
    std::string notify() override {
        return "FB message: " + m_notifier->notify();
    }
};

class SMSMessage : public Message {
public:
    SMSMessage(Notifier* note) : Message(note) {};
    std::string notify() override {
        return "SMS: " + m_notifier->notify();
    }
};


void SendMessage(Notifier* note) {
    std::cout << note->notify() << std::endl;
}

int main() {
    Notifier* fire = new FireNotifier();
    SendMessage(fire);
    Notifier* fb = new FBMessage(fire);
    SendMessage(fb);
    Notifier* sms = new SMSMessage(fire);
    SendMessage(sms);
    Notifier* dub = new SMSMessage(fb);
    SendMessage(dub);

    delete dub;
    delete sms;
    delete fb; 
    delete fire;

    return 0;
}