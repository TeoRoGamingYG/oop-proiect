//
// Created by Teo on 4/21/2024.
//
#include <iostream>
#include "mob.h"

Mob::Mob(std::string name, int hp, int atk, int gold, int exp)
        : name(std::move(name)), hp(hp), ihp(hp), atk(atk), gold(gold), exp(exp) {}

Mob& Mob::operator+(const Mob& mob) const {
    Mob* result = new Mob(*this);
    result->name = "Evolved " + name;
    result->hp = mob.hp / 2 + hp;
    result->atk = mob.atk / 2 + atk;
    result->gold += gold;
    result->exp = mob.exp / 5 + exp;
    return *result;
}

std::ostream& operator<<(std::ostream& out, const Mob& mob) {
    out << "NAME: " << mob.name << '\n';
    out << "HP: " << mob.hp << "; DMG: " << mob.atk << "; EXP: " << mob.exp << '\n';
    return out;
}

std::string Mob::getName() const {
    return name;
}

int Mob::getHp() const {
    return hp;
}

int Mob::getAtk() const {
    return atk;
}

int Mob::getGold() const {
    return gold;
}

int Mob::getExp() const {
    return exp;
}

void Mob::takeDmg(int damage) {
    if (hp >= damage)
        hp -= damage;
    else
        hp = 0;
    std::cout << name << " a suferit " << damage << " damage. " << name << " are acum " << hp << " health." << std::endl;
}

bool Mob::isAlive() const {
    return hp > 0;
}

void Mob::reset_mob_hp() {
    hp = ihp;
}

bool operator<(const Mob& mob1, const Mob& mob2) {
    return mob1.getHp() < mob2.getHp();
}
