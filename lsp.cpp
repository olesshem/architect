#include <iostream>
#include <string>

// Базовий клас
class Bird {
public:
    virtual void fly() {
        std::cout << "This bird is flying." << std::endl;
    }

    virtual void makeSound() {
        std::cout << "This bird is making sound." << std::endl;
    }
};

// Клас, що успадковується від Bird та може літати
class Sparrow : public Bird {
public:
    void fly() override {
        std::cout << "Sparrow is flying." << std::endl;
    }

    void makeSound() override {
        std::cout << "Sparrow is chirping." << std::endl;
    }
};

// Клас, що успадковується від Bird, але не може літати
class Ostrich : public Bird {
public:
    void fly() override {
        std::cout << "Ostrich can't fly." << std::endl;
    }

    void makeSound() override {
        std::cout << "Ostrich is booming." << std::endl;
    }
};

void makeTheBirdFly(Bird* bird) {
    bird->fly();
}

int main() {
    Bird* mySparrow = new Sparrow();
    Bird* myOstrich = new Ostrich();

    makeTheBirdFly(mySparrow); // Works as expected
    makeTheBirdFly(myOstrich); // Ostrich can't fly, but the program still works

    delete mySparrow;
    delete myOstrich;

    return 0;
}
