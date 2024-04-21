//
// Created by Teo on 4/21/2024.
//
#include "attack.h"

void attack(Player* attacker, Mob* target) {
    int damage = attacker->getAttackDamage() - target->getDefense();
    if (damage < 0) {
        damage = 0;
    }
    std::cout << attacker->getName() << " attacks " << target->getName() << " for " << damage << " damage." << std::endl;
    target->takeDamage(damage);
}

void attack(Mob* attacker, Player* target) {
    int damage = attacker->getAttackDamage() - target->getDefense();
    if (damage < 0) {
        damage = 0;
    }
    std::cout << attacker->getName() << " attacks " << target->getName() << " for " << damage << " damage." << std::endl;
    target->takeDamage(damage);
}

