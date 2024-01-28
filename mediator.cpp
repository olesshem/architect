#include <iostream>
#include <string>
#include <vector>

class User;

// Інтерфейс посередника
class Mediator {
public:
    virtual void Send(const std::string& message, User* user) = 0;
};

// Конкретний користувач, який взаємодіє з іншими через посередника
class User {
    Mediator* mediator_;
    std::string name_;

public:
    User(const std::string& name, Mediator* mediator) : name_(name), mediator_(mediator) {}

    void Send(const std::string& message) {
        mediator_->Send(message, this);
    }

    void Receive(const std::string& message) {
        std::cout << name_ << " received: " << message << std::endl;
    }

    std::string GetName() const {
        return name_;
    }
};

// Конкретний посередник - чат-рум
class ChatRoom : public Mediator {
    std::vector<User*> users_;

public:
    void RegisterUser(User* user) {
        users_.push_back(user);
    }

    void Send(const std::string& message, User* sender) override {
        for (auto* user : users_) {
            if (user != sender) {
                user->Receive(message);
            }
        }
    }
};

// Клієнтський код
int main() {
    ChatRoom chatRoom;

    User user1("Alice", &chatRoom);
    User user2("Bob", &chatRoom);
    User user3("Charlie", &chatRoom);

    chatRoom.RegisterUser(&user1);
    chatRoom.RegisterUser(&user2);
    chatRoom.RegisterUser(&user3);

    user1.Send("Hi everyone!");
    user2.Send("Hey Alice!");
    user3.Send("Hello Bob and Alice!");

    return 0;
}
