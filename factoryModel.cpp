#include <iostream>
#include <string>

// product classes

class Report {
public:
    virtual ~Report() = default;
    virtual std::string toReport() const = 0;
};

class QuarterlyReport : public Report {
public:
    std::string toReport() const override {
        return "End of quarter: Report";
    }
};

class AnnualReport : public Report {
public:
    std::string toReport() const override {
        return "End of year: Report";
    }
};


// creator classes

class EndOfTimePeriod {
public:
    virtual ~EndOfTimePeriod() = default;
    virtual Report* AccountingDepartmet() const = 0;

    std::string BoardMeeting() const {
        Report* report = this->AccountingDepartmet();
        return "AccountingDepartment: " + report->toReport();
    }
};

class EndOfQuarter : public EndOfTimePeriod {
public:
    Report* AccountingDepartmet() const {
        return new QuarterlyReport();
    }
};

class EndOfYear : public EndOfTimePeriod {
public:
    Report* AccountingDepartmet() const {
        return new AnnualReport();
    }
};

// board meetings take place both quarterly and annually
// if the board decides that meetings must take place also weekly, 
// we can easily extend our code

void ClientCode(const EndOfTimePeriod& tp) {
    std::cout << "This function could be called for any time period: "
        << tp.BoardMeeting() << std::endl;
}


int main() {
    EndOfTimePeriod* tp1 = new EndOfQuarter();
    ClientCode(*tp1);

    std::cout << "_____________________" << std::endl;

    EndOfTimePeriod* tp2 = new EndOfYear();
    ClientCode(*tp2);

    return 0;
}