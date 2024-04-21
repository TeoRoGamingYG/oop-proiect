//
// Created by Teo on 4/21/2024.
//
#include "Sword.h"

Sword::Sword(std::string name, int atk, int price, int quantity) : Item(name, atk, price, quantity), atk(atk) {}

void Sword::use(Player& player) {}
