#include <iostream>
#include <string>

enum LogLevel {
    INFO,
    WARNING,
    ERROR
};

// Базовий клас обробника
class Logger {
protected:
    LogLevel logLevel;
    Logger* next = nullptr; // Наступний елемент у ланцюгу

public:
    Logger(LogLevel level) : logLevel(level) {}

    // Встановлення наступного обробника у ланцюгу
    Logger* setNext(Logger* l) {
        next = l;
        return this;
    }

    // Обробка запиту
    void message(const std::string& msg, LogLevel severity) {
        if (logLevel <= severity) {
            writeMessage(msg);
        }
        if (next != nullptr) {
            next->message(msg, severity);
        }
    }

protected:
    virtual void writeMessage(const std::string& msg) = 0;
};

// Конкретні обробники
class ConsoleLogger : public Logger {
public:
    ConsoleLogger(LogLevel level) : Logger(level) {}

protected:
    void writeMessage(const std::string& msg) override {
        std::cout << "Writing to console: " << msg << std::endl;
    }
};

class FileLogger : public Logger {
public:
    FileLogger(LogLevel level) : Logger(level) {}

protected:
    void writeMessage(const std::string& msg) override {
        std::cout << "Writing to file: " << msg << std::endl;
    }
};

class EmailLogger : public Logger {
public:
    EmailLogger(LogLevel level) : Logger(level) {}

protected:
    void writeMessage(const std::string& msg) override {
        std::cout << "Sending via email: " << msg << std::endl;
    }
};

// Клієнтський код
int main() {
    Logger* consoleLogger = new ConsoleLogger(INFO);
    Logger* fileLogger = new FileLogger(ERROR);
    Logger* emailLogger = new EmailLogger(WARNING);

    consoleLogger->setNext(fileLogger)->setNext(emailLogger);

    consoleLogger->message("This is an informational message.", INFO);
    consoleLogger->message("This is a warning message.", WARNING);
    consoleLogger->message("This is an error message.", ERROR);

    delete consoleLogger;
    delete fileLogger;
    delete emailLogger;

    return 0;
}
