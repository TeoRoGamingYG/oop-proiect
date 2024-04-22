//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_POTION_H
#define OOP_POTION_H

#include <utility>

#include "item.h"
class Player;

class Potion : public Item {
private:
    [[maybe_unused]] int hp;
public:
    Potion([[maybe_unused]] std::string name, int hp, int price, int quantity) : Item(std::move(name), hp, price, quantity), hp(hp) {};
    void use(Player& player);
};

#endif