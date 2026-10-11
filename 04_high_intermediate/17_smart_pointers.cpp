// Topic 17: Smart Pointers
// Smart pointers call delete for you, so you cannot forget it.
//   unique_ptr: exactly one owner
//   shared_ptr: many owners, deleted when the last owner goes away
//
// Compile: g++ -std=c++17 -Wall -Wextra -o smart_pointers 17_smart_pointers.cpp
// Run:     ./smart_pointers

#include <iostream>
#include <memory>
#include <string>

class Player {
private:
    std::string name;

public:
    Player(const std::string& n) : name(n) {
        std::cout << "  [" << name << " created]\n";
    }

    ~Player() {
        std::cout << "  [" << name << " destroyed]\n";
    }

    void play() const {
        std::cout << "  " << name << " is playing\n";
    }
};

int main() {
    // --- unique_ptr ---
    std::cout << "unique_ptr:\n";
    {
        std::unique_ptr<Player> p1 = std::make_unique<Player>("Ada");
        p1->play();
    }   // p1 goes out of scope here, so the Player is deleted automatically
    std::cout << "After the block\n";

    // --- Moving a unique_ptr (it cannot be copied) ---
    std::cout << "\nMoving ownership:\n";
    std::unique_ptr<Player> owner1 = std::make_unique<Player>("Bola");
    std::unique_ptr<Player> owner2 = std::move(owner1);   // owner2 now owns it

    if (owner1 == nullptr) {
        std::cout << "  owner1 is empty now\n";
    }
    owner2->play();

    // --- shared_ptr ---
    std::cout << "\nshared_ptr:\n";
    std::shared_ptr<Player> a = std::make_shared<Player>("Chidi");
    std::cout << "  owners: " << a.use_count() << '\n';

    {
        std::shared_ptr<Player> b = a;      // copying shares ownership
        std::cout << "  owners: " << a.use_count() << '\n';
        b->play();
    }   // b is gone, but the Player lives on because a still owns it

    std::cout << "  owners: " << a.use_count() << '\n';

    std::cout << "\nEnd of main, remaining objects are cleaned up:\n";
    return 0;
}
