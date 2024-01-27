#include <iostream>
#include <vector>
#include <cmath>

// Абстрактний базовий клас
class Shape {
public:
    virtual double area() const = 0; // Чисто віртуальна функція
};

// Клас для кола
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

// Клас для прямокутника
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// Функція для розрахунку загальної площі
double totalArea(const std::vector<Shape*>& shapes) {
    double total = 0.0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

int main() {
    Circle circle(5);
    Rectangle rectangle(4, 5);

    std::vector<Shape*> shapes = { &circle, &rectangle };
    std::cout << "Total Area: " << totalArea(shapes) << std::endl;

    return 0;
}
