#include <iostream>

// Підсистема 1
class Subsystem1 {
public:
    std::string operation1() const {
        return "Subsystem1: Ready!\n";
    }
    // ...
    std::string operationN() const {
        return "Subsystem1: Go!\n";
    }
};

// Підсистема 2
class Subsystem2 {
public:
    std::string operation1() const {
        return "Subsystem2: Get ready!\n";
    }
    // ...
    std::string operationZ() const {
        return "Subsystem2: Fire!\n";
    }
};

// Клас Фасад, який надає прості інтерфейси до складних підсистем
class Facade {
protected:
    Subsystem1* subsystem1_;
    Subsystem2* subsystem2_;
    // Фасад може працювати з різними підсистемами власною логікою.

public:
    Facade(
        Subsystem1* subsystem1 = nullptr,
        Subsystem2* subsystem2 = nullptr) {
        this->subsystem1_ = subsystem1 ? : new Subsystem1;
        this->subsystem2_ = subsystem2 ? : new Subsystem2;
    }
    ~Facade() {
        delete subsystem1_;
        delete subsystem2_;
    }
    // Методи Фасаду зручні для клієнтського коду.
    std::string Operation() {
        std::string result = "Facade initializes subsystems:\n";
        result += subsystem1_->operation1();
        result += subsystem2_->operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += subsystem1_->operationN();
        result += subsystem2_->operationZ();
        return result;
    }
};

// Клієнтський код
int main() {
    Subsystem1* subsystem1 = new Subsystem1;
    Subsystem2* subsystem2 = new Subsystem2;
    Facade* facade = new Facade(subsystem1, subsystem2);
    std::cout << facade->Operation();

    delete facade;

    return 0;
}
