//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_POTION_H
#define OOP_POTION_H

#include "Item.h"
#include "Player.h"

class Potion : public Item {
private:
    int hp;
public:
    Potion(std::string name, int hp, int price, int quantity);
    void use(Player& player);
};

#endif //OOP_POTION_H
