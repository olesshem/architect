#include <iostream>
#include <string>
#include <memory>

// Клас, що представляє стан редактора
class Memento {
public:
    Memento(const std::string& state) : state_(state) {}
    std::string GetState() const {
        return state_;
    }

private:
    std::string state_;
};

// Клас редактора
class Editor {
public:
    void SetText(const std::string& text) {
        text_ = text;
    }

    std::string GetText() const {
        return text_;
    }

    std::shared_ptr<Memento> Save() {
        return std::make_shared<Memento>(text_);
    }

    void Restore(std::shared_ptr<Memento> memento) {
        if (memento) {
            text_ = memento->GetState();
        }
    }

private:
    std::string text_;
};

int main() {
    Editor editor;
    editor.SetText("Initial text");

    // Збереження стану
    auto saved = editor.Save();

    editor.SetText("Modified text");
    std::cout << "Current text: " << editor.GetText() << std::endl;

    // Відновлення попереднього стану
    editor.Restore(saved);
    std::cout << "Restored text: " << editor.GetText() << std::endl;

    return 0;
}
