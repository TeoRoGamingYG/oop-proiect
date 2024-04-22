//
// Created by Teo on 4/21/2024.
//
#include <utility>

#include "potion.h"
#include "player.h"
Potion::Potion([[maybe_unused]] std::string name, int hp, int price, int quantity) : Item(std::move(name), hp, price, quantity), hp(hp) {}

void Potion::use(Player& player) {
    int hpToAdd = getProp();
    std::cout << "Ai folosit potiunea " << getName() << ". Aceasta iti adauga " << hpToAdd << " hp." << std::endl;
    player.addHp(hpToAdd);
}
