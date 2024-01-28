#include <iostream>
#include <memory>

// Абстрактний клас стратегії
class RouteStrategy {
public:
    virtual void BuildRoute() const = 0;
    virtual ~RouteStrategy() {}
};

// Контекст
class Navigator {
public:
    Navigator(std::unique_ptr<RouteStrategy> strategy) : strategy_(std::move(strategy)) {}

    void SetStrategy(std::unique_ptr<RouteStrategy> strategy) {
        strategy_ = std::move(strategy);
    }

    void BuildRoute() const {
        strategy_->BuildRoute();
    }

private:
    std::unique_ptr<RouteStrategy> strategy_;
};

// Конкретні стратегії
class DrivingStrategy : public RouteStrategy {
public:
    void BuildRoute() const override {
        std::cout << "Побудова маршруту для водіння" << std::endl;
    }
};

class WalkingStrategy : public RouteStrategy {
public:
    void BuildRoute() const override {
        std::cout << "Побудова пішохідного маршруту" << std::endl;
    }
};

class BicyclingStrategy : public RouteStrategy {
public:
    void BuildRoute() const override {
        std::cout << "Побудова велосипедного маршруту" << std::endl;
    }
};

int main() {
    Navigator navigator(std::make_unique<DrivingStrategy>());
    navigator.BuildRoute(); // Побудова маршруту для водіння

    navigator.SetStrategy(std::make_unique<WalkingStrategy>());
    navigator.BuildRoute(); // Побудова пішохідного маршруту

    navigator.SetStrategy(std::make_unique<BicyclingStrategy>());
    navigator.BuildRoute(); // Побудова велосипедного маршруту

    return 0;
}
