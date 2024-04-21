//
// Created by Teo on 4/21/2024.
//
#include "Potion.h"

Potion::Potion(std::string name, int hp, int price, int quantity) : Item(name, hp, price, quantity), hp(hp) {}

void Potion::use(Player& player){};
