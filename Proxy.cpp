#include <iostream>
#include <string>

// Інтерфейс для зображення
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() {}
};

// Справжнє зображення, завантаження якого важке/дороге
class RealImage : public Image {
private:
    std::string filename_;

    void loadFromDisk() {
        std::cout << "Loading " << filename_ << std::endl;
    }

public:
    RealImage(const std::string& filename) : filename_(filename) {
        loadFromDisk();
    }

    void display() override {
        std::cout << "Displaying " << filename_ << std::endl;
    }
};

// Замісник, який контролює доступ до справжнього зображення
class ProxyImage : public Image {
private:
    RealImage* realImage_;
    std::string filename_;

public:
    ProxyImage(const std::string& filename) : filename_(filename), realImage_(nullptr) {}

    void display() override {
        if (realImage_ == nullptr) {
            realImage_ = new RealImage(filename_);
        }
        realImage_->display();
    }

    ~ProxyImage() {
        delete realImage_;
    }
};

// Клієнтський код
int main() {
    Image* image = new ProxyImage("test.jpg");

    // Зображення буде завантажене тільки при першому виклику display()
    image->display();
    std::cout << "Image will not be loaded again." << std::endl;

    // Не буде завантажувати зображення знову
    image->display();

    delete image;
    return 0;
}
