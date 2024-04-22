//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_POTION_H
#define OOP_POTION_H

#include "item.h"
#include "player.h"

class Potion : public Item {
private:
    int hp;
public:
    Potion([[maybe_unused]] std::string name, int hp, int price, int quantity);
    void use(Player& player);
};

#endif //OOP_POTION_H
