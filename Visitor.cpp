#include <iostream>
#include <vector>

// Попередні оголошення класів компонентів
class Button;
class TextField;

// Інтерфейс відвідувача
class Visitor {
public:
    virtual void VisitButton(Button* button) = 0;
    virtual void VisitTextField(TextField* textField) = 0;
};

// Інтерфейс компонентів
class Component {
public:
    virtual void Accept(Visitor* visitor) = 0;
};

// Конкретний клас компонента Button
class Button : public Component {
public:
    void Accept(Visitor* visitor) override {
        visitor->VisitButton(this);
    }

    std::string ButtonSpecificOperation() const {
        return "Button specific operation";
    }
};

// Конкретний клас компонента TextField
class TextField : public Component {
public:
    void Accept(Visitor* visitor) override {
        visitor->VisitTextField(this);
    }

    std::string TextFieldSpecificOperation() const {
        return "TextField specific operation";
    }
};

// Конкретний відвідувач, який виконує операцію експорту
class ExportVisitor : public Visitor {
public:
    void VisitButton(Button* button) override {
        std::cout << "Exporting Button: " << button->ButtonSpecificOperation() << std::endl;
    }

    void VisitTextField(TextField* textField) override {
        std::cout << "Exporting TextField: " << textField->TextFieldSpecificOperation() << std::endl;
    }
};

int main() {
    Button button;
    TextField textField;
    ExportVisitor exportVisitor;

    button.Accept(&exportVisitor);
    textField.Accept(&exportVisitor);

    return 0;
}
