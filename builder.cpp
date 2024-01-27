#include <iostream>
#include <string>

// Продукт
class House {
public:
    void setFoundation(const std::string& foundationType) {
        this->foundation = foundationType;
    }

    void setStructure(const std::string& structureType) {
        this->structure = structureType;
    }

    void setRoof(const std::string& roofType) {
        this->roof = roofType;
    }

    void displayHouse() const {
        std::cout << "House with " << foundation << " foundation, "
            << structure << " structure, and "
            << roof << " roof.\n";
    }

private:
    std::string foundation;
    std::string structure;
    std::string roof;
};

// Абстрактний будівельник
class HouseBuilder {
public:
    virtual void buildFoundation() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual House getHouse() = 0;
    virtual ~HouseBuilder() = default;
};

// Конкретний будівельник
class ConcreteHouseBuilder : public HouseBuilder {
public:
    void buildFoundation() override {
        house.setFoundation("Concrete");
    }

    void buildStructure() override {
        house.setStructure("Concrete Blocks");
    }

    void buildRoof() override {
        house.setRoof("Concrete Slab");
    }

    House getHouse() override {
        return house;
    }

private:
    House house;
};

// Директор, який керує будівництвом
class Director {
public:
    void setBuilder(HouseBuilder* newBuilder) {
        builder = newBuilder;
    }

    House construct() {
        builder->buildFoundation();
        builder->buildStructure();
        builder->buildRoof();
        return builder->getHouse();
    }

private:
    HouseBuilder* builder;
};

int main() {
    ConcreteHouseBuilder concreteBuilder;
    Director director;

    director.setBuilder(&concreteBuilder);
    House house = director.construct();
    house.displayHouse();

    return 0;
}
