#include <iostream>

// Інтерфейс для пристроїв, що друкують
class IPrinter {
public:
    virtual void Print() = 0;
};

// Інтерфейс для пристроїв, що сканують
class IScanner {
public:
    virtual void Scan() = 0;
};

// Клас, що реалізує лише друк
class Printer : public IPrinter {
public:
    void Print() override {
        std::cout << "Print document." << std::endl;
    }
};

// Клас, що реалізує лише сканування
class Scanner : public IScanner {
public:
    void Scan() override {
        std::cout << "Scan document." << std::endl;
    }
};

// Клас, що реалізує і друк, і сканування
class MultiFunctionPrinter : public IPrinter, public IScanner {
public:
    void Print() override {
        std::cout << "Print document." << std::endl;
    }

    void Scan() override {
        std::cout << "Scan document." << std::endl;
    }
};

int main() {
    Printer printer;
    Scanner scanner;
    MultiFunctionPrinter mfp;

    printer.Print();
    scanner.Scan();
    mfp.Print();
    mfp.Scan();

    return 0;
}
