//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_ATTACK_H
#define OOP_ATTACK_H

#include "Player.h"
#include "mob.h"

class Attack {
public:
    static void performAttack(Player& player, Mob& mob);
    ~Attack()=default;
};

#endif //OOP_ATTACK_H
