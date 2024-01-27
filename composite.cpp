#include <iostream>
#include <vector>
#include <memory>

// Інтерфейс Graphic
class Graphic {
public:
    virtual void draw() const = 0;
    virtual void add(std::shared_ptr<Graphic> graphic) {}
    virtual ~Graphic() {}
};

// Конкретний клас Circle, який реалізує Graphic
class Circle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Конкретний клас Rectangle, який реалізує Graphic
class Rectangle : public Graphic {
public:
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

// Композиція Graphics
class CompositeGraphic : public Graphic {
private:
    std::vector<std::shared_ptr<Graphic>> graphics;

public:
    void draw() const override {
        for (auto& graphic : graphics) {
            graphic->draw();
        }
    }

    void add(std::shared_ptr<Graphic> graphic) override {
        graphics.push_back(graphic);
    }
};

int main() {
    auto circle1 = std::make_shared<Circle>();
    auto circle2 = std::make_shared<Circle>();
    auto rectangle = std::make_shared<Rectangle>();

    CompositeGraphic graphic;
    graphic.add(circle1);
    graphic.add(circle2);
    graphic.add(rectangle);

    // Викликаємо draw() для всієї композиції
    graphic.draw();

    return 0;
}
