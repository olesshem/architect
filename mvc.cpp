#include <iostream>
#include <string>

// Модель
class Model {
public:
    void SetData(const std::string& data) {
        this->data = data;
    }

    std::string GetData() const {
        return data;
    }

private:
    std::string data;
};

// Вид
class View {
public:
    void Display(const std::string& data) {
        std::cout << "Data: " << data << std::endl;
    }
};

// Контролер
class Controller {
public:
    Controller(Model& model, View& view) : model(model), view(view) {}

    void SetData(const std::string& data) {
        model.SetData(data);
    }

    void UpdateView() {
        view.Display(model.GetData());
    }

private:
    Model& model;
    View& view;
};

// Клієнтський код
int main() {
    Model model;
    View view;
    Controller controller(model, view);

    controller.SetData("Hello MVC!");
    controller.UpdateView();

    return 0;
}
