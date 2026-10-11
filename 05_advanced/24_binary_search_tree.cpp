// Topic 24: Binary Search Tree
// A binary search tree keeps values in order: smaller values go to the left of a
// node, bigger values go to the right. That makes searching fast.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o binary_search_tree 24_binary_search_tree.cpp
// Run:     ./binary_search_tree

#include <algorithm>
#include <iostream>

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : value(v), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    // Recursive helper: insert a value below "node" and return the (possibly new) node.
    TreeNode* insertInto(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insertInto(node->left, value);
        } else if (value > node->value) {
            node->right = insertInto(node->right, value);
        }
        // equal values are ignored, so the tree has no duplicates
        return node;
    }

    bool search(TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        if (value == node->value) {
            return true;
        }
        if (value < node->value) {
            return search(node->left, value);
        }
        return search(node->right, value);
    }

    // In-order: left, then this node, then right. This prints values sorted.
    void printInOrder(TreeNode* node) const {
        if (node == nullptr) {
            return;
        }
        printInOrder(node->left);
        std::cout << node->value << ' ';
        printInOrder(node->right);
    }

    int height(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + std::max(height(node->left), height(node->right));
    }

    int countNodes(TreeNode* node) const {
        if (node == nullptr) {
            return 0;
        }
        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Delete every node (children first, then the node itself).
    void destroy(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree() {
        destroy(root);
    }

    BinarySearchTree(const BinarySearchTree&) = delete;
    BinarySearchTree& operator=(const BinarySearchTree&) = delete;

    void insert(int value) {
        root = insertInto(root, value);
    }

    bool contains(int value) const {
        return search(root, value);
    }

    void print() const {
        printInOrder(root);
        std::cout << '\n';
    }

    int height() const {
        return height(root);
    }

    int size() const {
        return countNodes(root);
    }

    int smallest() const {
        TreeNode* current = root;
        while (current->left != nullptr) {      // keep going left
            current = current->left;
        }
        return current->value;
    }

    int largest() const {
        TreeNode* current = root;
        while (current->right != nullptr) {     // keep going right
            current = current->right;
        }
        return current->value;
    }
};

int main() {
    BinarySearchTree tree;

    int values[] = {50, 30, 70, 20, 40, 60, 80, 30};   // note the duplicate 30
    for (int v : values) {
        tree.insert(v);
    }

    std::cout << "Sorted values: ";
    tree.print();

    std::cout << "Size: " << tree.size() << " (the duplicate was ignored)\n";
    std::cout << "Height: " << tree.height() << '\n';
    std::cout << "Smallest: " << tree.smallest() << ", largest: " << tree.largest() << '\n';

    std::cout << std::boolalpha;
    std::cout << "Contains 60? " << tree.contains(60) << '\n';
    std::cout << "Contains 65? " << tree.contains(65) << '\n';

    return 0;
}
