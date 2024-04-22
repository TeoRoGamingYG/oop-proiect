//
// Created by Teo on 4/21/2024.
//
#include "sword.h"
#include "player.h"

void Sword::use(Player& player) {
    int atkToAdd = getProp();
    std::cout << "Ai echipat sabia " << getName() << ".\n";
    player.addAtk(atkToAdd);
}

int Sword::getAtk() const {
    return atk;
}

//std::string Sword::getName() const {
//    return name;
//}