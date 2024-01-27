#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Інтерфейс команди
class Command {
public:
    virtual ~Command() {}
    virtual void Execute() = 0;
    virtual void Undo() = 0;
};

// Конкретна команда для додавання тексту
class AddTextCommand : public Command {
    std::string& document_;
    std::string textToAdd_;

public:
    AddTextCommand(std::string& document, const std::string& textToAdd)
        : document_(document), textToAdd_(textToAdd) {}

    void Execute() override {
        document_ += textToAdd_;
    }

    void Undo() override {
        document_ = document_.substr(0, document_.size() - textToAdd_.size());
    }
};

// Рецептор (Receiver)
class TextDocument {
    std::string content_;

public:
    void AddText(const std::string& text) {
        content_ += text;
    }

    void RemoveText(size_t length) {
        if (length <= content_.size()) {
            content_ = content_.substr(0, content_.size() - length);
        }
    }

    void Display() const {
        std::cout << content_ << std::endl;
    }
};

// Клієнтський код
int main() {
    TextDocument document;
    std::vector<std::unique_ptr<Command>> commands;

    commands.emplace_back(new AddTextCommand(document, "Hello "));
    commands.emplace_back(new AddTextCommand(document, "World"));

    // Виконання команд
    for (auto& cmd : commands) {
        cmd->Execute();
    }

    document.Display();

    // Відкат команд
    for (auto& cmd : commands) {
        cmd->Undo();
    }

    document.Display();

    return 0;
}
