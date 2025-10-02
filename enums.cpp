#include <iostream>
#include <cstdlib>

enum class State {
    INIT,
    SEARCHING,
    FOUND,
    END
};

void initializationProc() {
    std::cout << "Initializing Drone 2025 Super-fast search aglorithm\n";
}

bool searchForObject() {
    if (rand() < (RAND_MAX / 20)) {
        std::cout << "Found object\n";
        return true;
    }
    std::cout << "Still searching for object\n";
    return false;
}

void reportFoundObject() {
    std::cout << "Message to ROS2: Found the object!\n";
}

int main() {
    srand(500);

    State current_state;
    current_state = State::INIT;

    while (current_state != State::END) {
        switch (current_state) {
            case State::INIT:
                initializationProc();
                current_state = State::SEARCHING;
                break;
            case State::SEARCHING:
                if (searchForObject() == true) {
                    current_state = State::FOUND;
                }
                break;
            case State::FOUND:
                reportFoundObject();
                current_state = State::END;
                break;
            default:
                break;
        }
    }
}