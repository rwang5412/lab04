#include "CustomItem.h"

#include <iomanip>
#include <sstream>

CustomItem::CustomItem(std::string itemSize) : IceCreamItem(itemSize) {
    if (size == "small") {
        price = 3.00;
    } else if (size == "medium") {
        price = 5.00;
    } else if (size == "large") {
        price = 6.50;
    }
}

CustomItem::~CustomItem() {}

void CustomItem::addTopping(std::string topping) {
    ++toppings[topping];
    price += 0.40;
}

std::string CustomItem::composeItem() {
    std::ostringstream output;
    output << "Custom Size: " << size << "\nToppings:\n";
    for (std::map<std::string, int>::const_iterator topping = toppings.begin();
         topping != toppings.end(); ++topping) {
        output << topping->first << ": " << topping->second << " oz\n";
    }
    output << "Price: $" << std::fixed << std::setprecision(2) << price << "\n";
    return output.str();
}

double CustomItem::getPrice() {
    return price;
}