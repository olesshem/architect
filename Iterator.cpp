#include <iostream>
#include <vector>

// Інтерфейс ітератора
template <typename T>
class Iterator {
public:
    virtual ~Iterator() {}
    virtual T& Next() = 0;
    virtual bool HasNext() const = 0;
};

// Конкретна колекція
template <typename T>
class Container {
    std::vector<T> collection_;

public:
    void Add(const T& item) {
        collection_.push_back(item);
    }

    // Фабричний метод для створення ітератора
    Iterator<T>* CreateIterator() const;

    friend class ContainerIterator;

    // Конкретний ітератор для Container
    class ContainerIterator : public Iterator<T> {
        const Container& container_;
        size_t current_ = 0;

    public:
        ContainerIterator(const Container& container) : container_(container) {}

        T& Next() override {
            return container_.collection_[current_++];
        }

        bool HasNext() const override {
            return current_ < container_.collection_.size();
        }
    };
};

template <typename T>
Iterator<T>* Container<T>::CreateIterator() const {
    return new ContainerIterator(*this);
}

// Клієнтський код
int main() {
    Container<int> numbers;
    numbers.Add(1);
    numbers.Add(2);
    numbers.Add(3);

    Iterator<int>* it = numbers.CreateIterator();
    while (it->HasNext()) {
        std::cout << it->Next() << std::endl;
    }

    delete it;
    return 0;
}
