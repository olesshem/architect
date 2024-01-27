#include <iostream>

// Клас Singleton
class Singleton {
public:
    // Статичний метод для доступу до екземпляра Singleton
    static Singleton& getInstance() {
        static Singleton instance; // Гарантований один екземпляр
        return instance;
    }

    // Видалення методів копіювання та присвоєння
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    void display() const {
        std::cout << "I am a Singleton!" << std::endl;
    }

private:
    // Приватний конструктор
    Singleton() = default;
};

int main() {
    // Отримання та використання екземпляра Singleton
    Singleton& singletonInstance = Singleton::getInstance();
    singletonInstance.display();

    return 0;
}
