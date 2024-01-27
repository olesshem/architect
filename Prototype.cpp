#include <iostream>
#include <memory>

// Абстрактний клас, що представляє прототип
class Prototype {
public:
    virtual ~Prototype() = default;

    // Метод для клонування об'єкта
    virtual std::unique_ptr<Prototype> clone() const = 0;

    virtual void Display() const = 0;
};

// Конкретний клас, що реалізує клонування
class ConcretePrototype : public Prototype {
public:
    ConcretePrototype(int data) : data_(data) {}

    // Реалізація методу клонування
    std::unique_ptr<Prototype> clone() const override {
        return std::make_unique<ConcretePrototype>(*this);
    }

    void Display() const override {
        std::cout << "Data: " << data_ << std::endl;
    }

private:
    int data_;
};

int main() {
    std::unique_ptr<Prototype> original = std::make_unique<ConcretePrototype>(100);
    std::unique_ptr<Prototype> cloned = original->clone();

    std::cout << "Original object: ";
    original->Display();

    std::cout << "Cloned object: ";
    cloned->Display();

    return 0;
}
