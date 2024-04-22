//
// Created by Teo on 4/21/2024.
//
#include <iostream>
#include "shop.h"

void Shop::addPotion(const Potion& potion) {
    items.push_back(potion);
}

void Shop::addSword(const Sword& sword) {
    items.push_back(sword);
}

void Shop::displayItems() const {
    std::cout << "Shop:\n\n";
    for (const auto& item : items) {
        std::cout << item.getName() << " (" << item.getProp() << " hp)" << " - Pret: " << item.getPrice() << " (Stoc: " << item.getQuantity() << ")\n";
    }
    std::cout << '\n';
}

std::vector<Item>& Shop::getItems() {
    return items;
}

