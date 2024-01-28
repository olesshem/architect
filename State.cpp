#include <iostream>
#include <memory>

// Абстрактний клас стану
class State {
public:
    virtual void Handle() = 0;
    virtual ~State() {}
};

// Контекст
class MusicPlayer {
public:
    MusicPlayer(std::unique_ptr<State> state) : state_(std::move(state)) {}

    void SetState(std::unique_ptr<State> state) {
        state_ = std::move(state);
    }

    void Request() {
        state_->Handle();
    }

private:
    std::unique_ptr<State> state_;
};

// Конкретні стани
class PlayState : public State {
public:
    void Handle() override {
        std::cout << "Відтворення музики" << std::endl;
    }
};

class PauseState : public State {
public:
    void Handle() override {
        std::cout << "Музика на паузі" << std::endl;
    }
};

class StopState : public State {
public:
    void Handle() override {
        std::cout << "Музика зупинена" << std::endl;
    }
};

int main() {
    MusicPlayer player(std::make_unique<PlayState>());
    player.Request(); // Відтворення музики

    player.SetState(std::make_unique<PauseState>());
    player.Request(); // Музика на паузі

    player.SetState(std::make_unique<StopState>());
    player.Request(); // Музика зупинена

    return 0;
}
