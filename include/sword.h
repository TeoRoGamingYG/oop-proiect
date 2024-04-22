//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_SWORD_H
#define OOP_SWORD_H

#include <utility>

#include "item.h"
class Player;

class Sword : public Item {
private:
    int atk;
public:
    Sword(std::string name, int atk, int price, int quantity) : Item(std::move(name), atk, price, quantity), atk(atk) {};
    void use(Player& player);
    [[nodiscard]] int getAtk() const;
    //[[nodiscard]] std::string getName() const;
};

#endif
