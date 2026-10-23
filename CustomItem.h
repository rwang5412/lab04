#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <map>
#include <string>

#include "IceCreamItem.h"

class CustomItem : public IceCreamItem {
public:
    explicit CustomItem(std::string size);
    virtual ~CustomItem();

    void addTopping(std::string topping);
    std::string composeItem() override;
    double getPrice() override;

private:
    std::map<std::string, int> toppings;
};

#endif