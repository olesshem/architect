#include <iostream>

// Старий інтерфейс
class LegacyRectangle {
public:
    LegacyRectangle(int x, int y, int width, int height)
        : x_(x), y_(y), width_(width), height_(height) {}

    void oldDraw() {
        std::cout << "LegacyRectangle: draw. x: " << x_ << ", y: " << y_
            << ", width: " << width_ << ", height: " << height_ << std::endl;
    }

private:
    int x_;
    int y_;
    int width_;
    int height_;
};

// Цільовий інтерфейс
class NewRectangle {
public:
    virtual ~NewRectangle() = default;
    virtual void draw() = 0;
};

// Адаптер
class RectangleAdapter : public NewRectangle {
public:
    RectangleAdapter(int x, int y, int width, int height)
        : legacyRectangle_(x, y, width, height) {}

    void draw() override {
        legacyRectangle_.oldDraw();
    }

private:
    LegacyRectangle legacyRectangle_;
};

// Клієнтський код
int main() {
    NewRectangle* rectangle = new RectangleAdapter(20, 50, 40, 60);
    rectangle->draw();
    delete rectangle;

    return 0;
}