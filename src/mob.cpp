//
// Created by Teo on 4/21/2024.
//
#include "mob.h"

Mob::Mob(std::string name, int health, int attackDamage, int defense)
        : name(name), health(health), attackDamage(attackDamage), defense(defense) {}

Mob::~Mob() {}

std::string Mob::getName() const {
    return name;
}

int Mob::getHealth() const {
    return health;
}

void Mob::setHealth(int health) {
    this->health = health;
}

int Mob::getAttackDamage() const {
    return attackDamage;
}

int Mob::getDefense() const {
    return defense;
}

void Mob::takeDamage(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}

void Mob::attack(Mob* target) {
    int damage = attackDamage - target->getDefense();
    if (damage < 0) {
        damage = 0;
    }
    std::cout << name << " attacks " << target->getName() << " for " << damage << " damage." << std::endl;
    target->takeDamage(damage);
}

Goblin::Goblin() : Mob("Goblin", 30, 5, 2) {}

Troll::Troll() : Mob("Troll", 50, 10, 5) {}
