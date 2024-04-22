//
// Created by Teo on 4/21/2024.
//
#include "potion.h"
#include "player.h"

void Potion::use(Player& player) {
    int hpToAdd = getProp();
    std::cout << "Ai folosit potiunea " << getName() << ". Aceasta iti adauga " << hpToAdd << " hp." << std::endl;
    player.addHp(hpToAdd);
}

int Potion::getHp() const {
    return hp;
}

//std::string Potion::getName() const {
//    return name;
//}