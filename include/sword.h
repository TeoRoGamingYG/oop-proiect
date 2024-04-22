//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_SWORD_H
#define OOP_SWORD_H

#include "item.h"
#include "player.h"

class Sword : public Item {
private:
    int atk;
public:
    Sword([[maybe_unused]] std::string name, int atk, int price, int quantity);
    void use(Player& player);
};

#endif //OOP_SWORD_H
