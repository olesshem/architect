#include <iostream>
#include <memory>

// Абстрактний клас Transport
class Transport {
public:
    virtual void deliver() = 0;
    virtual ~Transport() = default;
};

// Клас Car, що є нащадком Transport
class Car : public Transport {
public:
    void deliver() override {
        std::cout << "Deliver by car" << std::endl;
    }
};

// Клас Bike, що є нащадком Transport
class Bike : public Transport {
public:
    void deliver() override {
        std::cout << "Deliver by bike" << std::endl;
    }
};

// Абстрактний клас TransportFactory
class TransportFactory {
public:
    virtual std::unique_ptr<Transport> createTransport() = 0;
    virtual ~TransportFactory() = default;
};

// Конкретна фабрика для створення Car
class CarFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<Car>();
    }
};

// Конкретна фабрика для створення Bike
class BikeFactory : public TransportFactory {
public:
    std::unique_ptr<Transport> createTransport() override {
        return std::make_unique<Bike>();
    }
};

// Клієнтський код
int main() {
    std::unique_ptr<TransportFactory> carFactory = std::make_unique<CarFactory>();
    auto car = carFactory->createTransport();
    car->deliver();

    std::unique_ptr<TransportFactory> bikeFactory = std::make_unique<BikeFactory>();
    auto bike = bikeFactory->createTransport();
    bike->deliver();

    return 0;
}
