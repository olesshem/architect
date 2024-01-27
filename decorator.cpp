#include <iostream>
#include <memory>

// Інтерфейс Component
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() {}
};

// Конкретний компонент, який реалізує інтерфейс Component
class ConcreteComponent : public Component {
public:
    void operation() const override {
        std::cout << "ConcreteComponent operation" << std::endl;
    }
};

// Абстрактний декоратор, який також реалізує інтерфейс Component
class Decorator : public Component {
protected:
    std::shared_ptr<Component> component;

public:
    Decorator(std::shared_ptr<Component> component) : component(component) {}

    void operation() const override {
        if (component)
            component->operation();
    }
};

// Конкретний декоратор A
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(std::shared_ptr<Component> component) : Decorator(component) {}

    void operation() const override {
        Decorator::operation();
        addedBehavior();
    }

    void addedBehavior() const {
        std::cout << "ConcreteDecoratorA added behavior" << std::endl;
    }
};

// Конкретний декоратор B
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(std::shared_ptr<Component> component) : Decorator(component) {}

    void operation() const override {
        Decorator::operation();
        addedState = "New State";
        std::cout << "ConcreteDecoratorB added behavior with state: " << addedState << std::endl;
    }

private:
    mutable std::string addedState;
};

int main() {
    auto simple = std::make_shared<ConcreteComponent>();
    std::cout << "Simple component:" << std::endl;
    simple->operation();

    auto decoratorA = std::make_shared<ConcreteDecoratorA>(simple);
    auto decoratorB = std::make_shared<ConcreteDecoratorB>(decoratorA);
    std::cout << "\nDecorated component:" << std::endl;
    decoratorB->operation();

    return 0;
}
