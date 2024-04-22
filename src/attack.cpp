//
// Created by Teo on 4/21/2024.
//
#include "attack.h"

static void performAttack(Player& player, Mob& mob)
{
    mob.takeDmg(player.getAtk());
    if (mob.isAlive())
    {
        player.takeDmg(mob.getAtk());
    }
}

