//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_ATTACK_H
#define OOP_ATTACK_H

#include "player.h"
#include "mob.h"

void attack(Player* attacker, Mob* target);
void attack(Mob* attacker, Player* target);

#endif //OOP_ATTACK_H
