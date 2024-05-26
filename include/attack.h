#ifndef OOP_ATTACK_H
#define OOP_ATTACK_H

#include "player.h"
#include "mob.h"

class Attack {
public:
    static void performAttack(Player& player, Mob& mob)
    {
        mob.takeDmg(player.getAtk());
        if (mob.isAlive())
            {
                player.takeDmg(mob.getAtk());
            }
    };
    ~Attack()=default;
};

#endif //OOP_ATTACK_H
