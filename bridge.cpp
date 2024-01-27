#include <iostream>
#include <memory>

// Інтерфейс реалізації
class Color {
public:
    virtual ~Color() = default;
    virtual void applyColor() const = 0;
};

// Конкретні реалізації
class Red : public Color {
public:
    void applyColor() const override {
        std::cout << "Applying red color" << std::endl;
    }
};

class Blue : public Color {
public:
    void applyColor() const override {
        std::cout << "Applying blue color" << std::endl;
    }
};

// Абстракція
class Shape {
protected:
    std::unique_ptr<Color> color_;

public:
    Shape(std::unique_ptr<Color> color) : color_(std::move(color)) {}
    virtual ~Shape() = default;

    virtual void draw() const = 0;
};

// Розширення абстракції
class Circle : public Shape {
public:
    Circle(std::unique_ptr<Color> color) : Shape(std::move(color)) {}

    void draw() const override {
        std::cout << "Circle drawn. ";
        color_->applyColor();
    }
};

class Square : public Shape {
public:
    Square(std::unique_ptr<Color> color) : Shape(std::move(color)) {}

    void draw() const override {
        std::cout << "Square drawn. ";
        color_->applyColor();
    }
};

int main() {
    std::unique_ptr<Shape> redCircle = std::make_unique<Circle>(std::make_unique<Red>());
    std::unique_ptr<Shape> blueSquare = std::make_unique<Square>(std::make_unique<Blue>());

    redCircle->draw();
    blueSquare->draw();

    return 0;
}
