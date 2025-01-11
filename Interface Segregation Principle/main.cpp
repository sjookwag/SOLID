// 4. Interface Segregation Principle
// This principle is the first principle that applies to Interfaces instead of classes in SOLID 
// and it is similar to the single responsibility principle.It states that 
// "do not force any client to implement an interface which is irrelevant to them".
// Here your main goal is to focus on avoiding fat interface and give preference to many small client 
// - specific interfaces.You should prefer many client interfaces rather than one general interface 
// and each interface should have a specific responsibility.
// Let¡¯s understand Interface Segregation Principle using an example :
// Suppose if you enter a restaurant and you are pure vegetarian.The waiter in that restaurant gave you 
// the menu card which includes vegetarian items, non - vegetarian items, drinks, and sweets.
// In this case, as a customer, you should have a menu card which includes only vegetarian items, 
// not everything which you don¡¯t eat in your food.Here the menu should be different for different types of customers.
// The common or general menu card for everyone can be divided into multiple cards instead of just one.
// Using this principle helps in reducing the side effects and frequency of required changes.

// IVegetarianMenu Interface : This interface defines a method to get vegetarian items.It ensures that only classes implementing vegetarian menus will need to provide this functionality.
// INonVegetarianMenu Interface : Similar to the vegetarian interface, this one defines a method for getting non - vegetarian items.
// IDrinkMenu Interface : This interface defines a method for getting drink items, keeping it separate from food items.
// VegetarianMenu Class : Implements the IVegetarianMenu interface and provides a list of vegetarian items.
// NonVegetarianMenu Class : Implements the INonVegetarianMenu interface and provides a list of non - vegetarian items.
// DrinkMenu Class : Implements the IDrinkMenu interface and provides a list of drink items.
#include <iostream>
#include <vector>
#include <string>

// Interface for vegetarian menu
class IVegetarianMenu {
public:
    virtual std::vector<std::string> getVegetarianItems() = 0;
};

// Interface for non-vegetarian menu
class INonVegetarianMenu {
public:
    virtual std::vector<std::string> getNonVegetarianItems() = 0;
};

// Interface for drinks menu
class IDrinkMenu {
public:
    virtual std::vector<std::string> getDrinkItems() = 0;
};

// Class for vegetarian menu
class VegetarianMenu : public IVegetarianMenu {
public:
    std::vector<std::string> getVegetarianItems() override {
        return { "Vegetable Curry", "Paneer Tikka", "Salad" };
    }
};

// Class for non-vegetarian menu
class NonVegetarianMenu : public INonVegetarianMenu {
public:
    std::vector<std::string> getNonVegetarianItems() override {
        return { "Chicken Curry", "Fish Fry", "Mutton Biryani" };
    }
};

// Class for drinks menu
class DrinkMenu : public IDrinkMenu {
public:
    std::vector<std::string> getDrinkItems() override {
        return { "Water", "Soda", "Juice" };
    }
};

// Function to display menu items for a vegetarian customer
void displayVegetarianMenu(IVegetarianMenu* menu) {
    std::cout << "Vegetarian Menu:\n";
    for (const auto& item : menu->getVegetarianItems()) {
        std::cout << "- " << item << std::endl;
    }
}

// Function to display menu items for a non-vegetarian customer
void displayNonVegetarianMenu(INonVegetarianMenu* menu) {
    std::cout << "Non-Vegetarian Menu:\n";
    for (const auto& item : menu->getNonVegetarianItems()) {
        std::cout << "- " << item << std::endl;
    }
}

int main() {
    VegetarianMenu vegMenu;
    NonVegetarianMenu nonVegMenu;
    DrinkMenu drinkMenu;

    displayVegetarianMenu(&vegMenu);
    displayNonVegetarianMenu(&nonVegMenu);

    return 0;
}