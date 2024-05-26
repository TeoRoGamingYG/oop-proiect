#ifndef OOP_ITEMFACTORY_H
#define OOP_ITEMFACTORY_H

#include "item.h"
#include "sword.h"
#include "potion.h"
#include <memory>
#include <string>

class ItemFactory {
public:
    static std::unique_ptr<Item<std::string, int>> createItem(const std::string& type, const std::string& name, int prop, int price, int quantity, int initQuantity) {
        if (type == "Sword") {
            return std::make_unique<Sword<std::string, int>>(name, prop, price, quantity, initQuantity);
        } else if (type == "Potion") {
            return std::make_unique<Potion<std::string, int>>(name, prop, price, quantity, initQuantity);
        }
        return nullptr;
    }
};

#endif //OOP_ITEMFACTORY_H
