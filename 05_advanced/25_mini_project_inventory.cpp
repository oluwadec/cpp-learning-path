// Topic 25: Mini Project - Inventory Manager
// A small project that brings many topics together: classes, std::map, std::vector,
// exceptions, lambdas, algorithms and formatted output.
//
// Compile: g++ -std=c++17 -Wall -Wextra -o inventory 25_mini_project_inventory.cpp
// Run:     ./inventory

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

// One product in the shop.
struct Item {
    std::string name;
    int quantity;
    double price;
};

class Inventory {
private:
    std::map<std::string, Item> items;  // item name -> item details

public:
    // Add a new item, or increase the quantity if it already exists.
    void addItem(const std::string& name, int quantity, double price) {
        if (quantity <= 0 || price < 0) {
            throw std::invalid_argument("quantity must be positive and price cannot be negative");
        }

        auto found = items.find(name);
        if (found != items.end()) {
            found->second.quantity += quantity;
        } else {
            items[name] = Item{name, quantity, price};
        }
    }

    // Sell some units. Throws if we do not have enough.
    double sell(const std::string& name, int quantity) {
        auto found = items.find(name);
        if (found == items.end()) {
            throw std::runtime_error(name + " is not in the inventory");
        }
        if (found->second.quantity < quantity) {
            throw std::runtime_error("not enough " + name + " (only " +
                                     std::to_string(found->second.quantity) + " left)");
        }

        found->second.quantity -= quantity;
        return quantity * found->second.price;
    }

    // Total value of everything in stock.
    double totalValue() const {
        double total = 0;
        for (const auto& entry : items) {
            total += entry.second.quantity * entry.second.price;
        }
        return total;
    }

    // Names of items with fewer than "limit" units left.
    std::vector<std::string> lowStock(int limit) const {
        std::vector<std::string> result;
        for (const auto& entry : items) {
            if (entry.second.quantity < limit) {
                result.push_back(entry.first);
            }
        }
        return result;
    }

    // Print a table, sorted by price (most expensive first).
    void printReport() const {
        std::vector<Item> list;
        for (const auto& entry : items) {
            list.push_back(entry.second);
        }

        std::sort(list.begin(), list.end(), [](const Item& a, const Item& b) {
            return a.price > b.price;
        });

        std::cout << std::left << std::setw(12) << "Item"
                  << std::right << std::setw(6) << "Qty"
                  << std::setw(10) << "Price" << '\n';
        std::cout << std::string(28, '-') << '\n';

        std::cout << std::fixed << std::setprecision(2);
        for (const Item& item : list) {
            std::cout << std::left << std::setw(12) << item.name
                      << std::right << std::setw(6) << item.quantity
                      << std::setw(10) << item.price << '\n';
        }
        std::cout << std::string(28, '-') << '\n';
        std::cout << "Total stock value: " << totalValue() << '\n';
    }
};

int main() {
    Inventory shop;

    shop.addItem("Notebook", 40, 450.00);
    shop.addItem("Pen", 120, 100.00);
    shop.addItem("Calculator", 8, 5500.00);
    shop.addItem("Pen", 30, 100.00);        // adds to the existing Pen stock

    std::cout << "=== Starting inventory ===\n";
    shop.printReport();

    // --- Selling things, with error handling ---
    std::cout << "\n=== Sales ===\n";
    std::cout << std::fixed << std::setprecision(2);

    try {
        double earned = shop.sell("Calculator", 3);
        std::cout << "Sold 3 calculators for " << earned << '\n';

        earned = shop.sell("Notebook", 15);
        std::cout << "Sold 15 notebooks for " << earned << '\n';

        shop.sell("Calculator", 10);        // too many, throws an exception
    } catch (const std::exception& e) {
        std::cout << "Sale failed: " << e.what() << '\n';
    }

    try {
        shop.sell("Stapler", 1);            // not in the inventory
    } catch (const std::exception& e) {
        std::cout << "Sale failed: " << e.what() << '\n';
    }

    try {
        shop.addItem("Eraser", -5, 50);     // bad input
    } catch (const std::exception& e) {
        std::cout << "Could not add: " << e.what() << '\n';
    }

    // --- Reorder warning ---
    std::cout << "\n=== Low stock (fewer than 10) ===\n";
    for (const std::string& name : shop.lowStock(10)) {
        std::cout << name << '\n';
    }

    std::cout << "\n=== Final inventory ===\n";
    shop.printReport();

    return 0;
}
