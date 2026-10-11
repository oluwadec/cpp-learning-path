// Topic 23: Linked List
// A linked list is a chain of nodes. Each node holds a value and a pointer to the
// next node. We build one by hand to see how pointers and new/delete work together.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o linked_list 23_linked_list.cpp
// Run:     ./linked_list

#include <iostream>

struct Node {
    int value;
    Node* next;

    Node(int v) : value(v), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;                         // the first node (nullptr when the list is empty)
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    // The destructor deletes every node so nothing is leaked.
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Copying is switched off to keep this example simple and safe.
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    // Add to the front: quick, no walking needed.
    void addFront(int value) {
        Node* node = new Node(value);
        node->next = head;
        head = node;
        ++count;
    }

    // Add to the back: walk to the last node first.
    void addBack(int value) {
        Node* node = new Node(value);
        if (head == nullptr) {
            head = node;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = node;
        }
        ++count;
    }

    // Remove the first node that holds this value. Returns true if found.
    bool remove(int value) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->value == value) {
                if (previous == nullptr) {
                    head = current->next;           // removing the first node
                } else {
                    previous->next = current->next; // skip over the node
                }
                delete current;
                --count;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    bool contains(int value) const {
        for (Node* current = head; current != nullptr; current = current->next) {
            if (current->value == value) {
                return true;
            }
        }
        return false;
    }

    // Reverse the list by flipping every next pointer.
    void reverse() {
        Node* previous = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        head = previous;
    }

    int size() const {
        return count;
    }

    void print() const {
        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->value << " -> ";
        }
        std::cout << "end\n";
    }
};

int main() {
    LinkedList list;

    list.addBack(10);
    list.addBack(20);
    list.addBack(30);
    list.addFront(5);

    std::cout << "List: ";
    list.print();
    std::cout << "Size: " << list.size() << '\n';

    std::cout << std::boolalpha;
    std::cout << "Contains 20? " << list.contains(20) << '\n';
    std::cout << "Contains 99? " << list.contains(99) << '\n';

    list.remove(20);
    std::cout << "After removing 20: ";
    list.print();

    std::cout << "Removing 99 worked? " << list.remove(99) << '\n';

    list.reverse();
    std::cout << "Reversed: ";
    list.print();

    return 0;
}
