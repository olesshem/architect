#include <iostream>
#include <map>
#include <string>

// Спільний стан
class TreeType {
private:
    std::string name_;
    std::string color_;
    std::string texture_;

public:
    TreeType(const std::string& name, const std::string& color, const std::string& texture)
        : name_(name), color_(color), texture_(texture) {}

    void draw(const std::string& canvas, int x, int y) {
        // Реалізація відображення дерева на полотні.
        std::cout << "Draw " << name_ << " tree at (" << x << ", " << y << ") on " << canvas << std::endl;
    }
};

// Фабрика для уникнення дублювання об'єктів TreeType
class TreeFactory {
private:
    static std::map<std::string, TreeType*> treeTypes_;

public:
    static TreeType* getTreeType(const std::string& name, const std::string& color, const std::string& texture) {
        std::string key = name + color + texture;
        if (treeTypes_.find(key) == treeTypes_.end()) {
            treeTypes_[key] = new TreeType(name, color, texture);
        }
        return treeTypes_[key];
    }

    static void cleanUp() {
        for (auto it : treeTypes_) {
            delete it.second;
        }
        treeTypes_.clear();
    }
};

std::map<std::string, TreeType*> TreeFactory::treeTypes_;

// Клієнтський код, який використовує Flyweight
class Tree {
private:
    int x_, y_;
    TreeType* type_;

public:
    Tree(int x, int y, TreeType* type) : x_(x), y_(y), type_(type) {}

    void draw(const std::string& canvas) {
        type_->draw(canvas, x_, y_);
    }
};

int main() {
    TreeType* tt1 = TreeFactory::getTreeType("Maple", "Red", "MapleTexture");
    TreeType* tt2 = TreeFactory::getTreeType("Oak", "Green", "OakTexture");

    Tree tree1(1, 2, tt1);
    Tree tree2(5, 3, tt2);

    tree1.draw("Canvas1");
    tree2.draw("Canvas2");

    TreeFactory::cleanUp();

    return 0;
}
