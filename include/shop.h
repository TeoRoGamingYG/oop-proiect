//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H

#include <vector>
#include "item.h"

class Shop {
private:
    std::vector<Item*> stock;

public:
    Shop();

    void addItem(Item* item);
    void displayStock() const;
    Item* buyItem(int index);
    std::vector<Item>& getItems();
};

#endif //OOP_SHOP_H
