#include <iostream>
#include <string>
#include <memory>

// Інтерфейс для логування
class ILogger {
public:
    virtual void Log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

// Реалізація логування в консоль
class ConsoleLogger : public ILogger {
public:
    void Log(const std::string& message) override {
        std::cout << "Console log: " << message << std::endl;
    }
};

// Реалізація логування в файл (простий приклад, без реального запису в файл)
class FileLogger : public ILogger {
public:
    void Log(const std::string& message) override {
        std::cout << "File log: " << message << std::endl; // Уявіть, що це запис в файл
    }
};

// Клас, що використовує логування
class Application {
public:
    Application(std::shared_ptr<ILogger> logger) : logger_(logger) {}

    void Run() {
        logger_->Log("Application is running");
        // Інший код програми
    }

private:
    std::shared_ptr<ILogger> logger_;
};

int main() {
    auto consoleLogger = std::make_shared<ConsoleLogger>();
    auto fileLogger = std::make_shared<FileLogger>();

    Application app1(consoleLogger);
    app1.Run();

    Application app2(fileLogger);
    app2.Run();

    return 0;
}
