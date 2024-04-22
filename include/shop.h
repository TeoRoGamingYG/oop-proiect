//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_SHOP_H
#define OOP_SHOP_H

#include <iostream>
#include <vector>
#include "Player.h"
#include "item.h"
#include "potion.h"
#include "sword.h"

class Shop {
private:
    std::vector<Item> items;

public:
    void addPotion(const Potion& potion);
    void addSword(const Sword& sword);
    void displayItems() const;
    std::vector<Item>& getItems();
};

#endif //OOP_SHOP_H
