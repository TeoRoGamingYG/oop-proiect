//
// Created by Teo on 4/21/2024.
//
#include <utility>

#include "Sword.h"
#include "Player.h"
Sword::Sword([[maybe_unused]] std::string name, int atk, int price, int quantity) : Item(std::move(name), atk, price, quantity), atk(atk) {}

void Sword::use(Player& player) {
    int atkToAdd = getProp();
    std::cout << "Ai echipat sabia " << getName() << ".\n";
    player.addAtk(atkToAdd);
}

