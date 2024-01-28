#include <iostream>
#include <list>
#include <string>

// Інтерфейс спостерігача
class Observer {
public:
    virtual ~Observer() {}
    virtual void Update(const std::string& message_from_subject) = 0;
};

// Інтерфейс суб'єкта
class Subject {
public:
    virtual ~Subject() {}
    virtual void Attach(Observer* observer) = 0;
    virtual void Detach(Observer* observer) = 0;
    virtual void Notify() = 0;
};

// Конкретний суб'єкт
class WeatherStation : public Subject {
public:
    void Attach(Observer* observer) override {
        list_observer_.push_back(observer);
    }

    void Detach(Observer* observer) override {
        list_observer_.remove(observer);
    }

    void Notify() override {
        std::list<Observer*>::iterator iterator = list_observer_.begin();
        while (iterator != list_observer_.end()) {
            (*iterator)->Update(message_);
            ++iterator;
        }
    }

    void CreateMessage(std::string message = "Empty") {
        this->message_ = message;
        Notify();
    }

private:
    std::list<Observer*> list_observer_;
    std::string message_;
};

// Конкретний спостерігач
class WeatherScreen : public Observer {
public:
    WeatherScreen(WeatherStation& subject) : subject_(subject) {
        subject_.Attach(this);
    }

    virtual ~WeatherScreen() {
        subject_.Detach(this);
    }

    void Update(const std::string& message_from_subject) override {
        message_from_subject_ = message_from_subject;
        PrintInfo();
    }

    void PrintInfo() {
        std::cout << "WeatherScreen: нові дані погоди: " << message_from_subject_ << std::endl;
    }

private:
    std::string message_from_subject_;
    WeatherStation& subject_;
};

int main() {
    WeatherStation weather_station;

    WeatherScreen screen(weather_station);
    weather_station.CreateMessage("Сонячно");
    weather_station.CreateMessage("Хмарно");

    return 0;
}
