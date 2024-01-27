#include <iostream>
#include <memory>

// Абстрактні продукти
class Button {
public:
    virtual void paint() = 0;
    virtual ~Button() = default;
};

class Checkbox {
public:
    virtual void paint() = 0;
    virtual ~Checkbox() = default;
};

// Конкретні продукти різних варіантів
class WinButton : public Button {
public:
    void paint() override {
        std::cout << "Render a button in a Windows style.\n";
    }
};

class MacButton : public Button {
public:
    void paint() override {
        std::cout << "Render a button in a MacOS style.\n";
    }
};

class WinCheckbox : public Checkbox {
public:
    void paint() override {
        std::cout << "Render a checkbox in a Windows style.\n";
    }
};

class MacCheckbox : public Checkbox {
public:
    void paint() override {
        std::cout << "Render a checkbox in a MacOS style.\n";
    }
};

// Абстрактна фабрика
class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() = default;
};

// Конкретні фабрики, що створюють відповідні продукти
class WinFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<WinButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<WinCheckbox>();
    }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<MacButton>();
    }

    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<MacCheckbox>();
    }
};

// Клієнтський код, який використовує фабрики
void Application(const std::unique_ptr<GUIFactory>& factory) {
    auto button = factory->createButton();
    auto checkbox = factory->createCheckbox();
    button->paint();
    checkbox->paint();
}

int main() {
    std::unique_ptr<GUIFactory> winFactory = std::make_unique<WinFactory>();
    std::unique_ptr<GUIFactory> macFactory = std::make_unique<MacFactory>();

    std::cout << "Windows GUI:\n";
    Application(winFactory);

    std::cout << "\nMacOS GUI:\n";
    Application(macFactory);

    return 0;
}
