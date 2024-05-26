#include <iostream>
#include "potion.h"
#include "sword.h"
#include "shop.h"
#include "item.h"

std::vector<Item<std::string, int>*> Shop::items;

void Shop::addPotion(Potion<std::string, int>& potion) {
    items.push_back(new Potion(potion));
}

void Shop::addSword(Sword<std::string, int>& sword) {
    items.push_back(new Sword(sword));
}

void Shop::displayItems() {
    std::cout << "Shop:\n\n";
    for (auto& item : items) {
        std::cout << item->getName() << " (" << item->getProp() << " pct)" << " - Pret: " << item->getPrice() << " (Stoc: " << item->getQuantity() << ")\n";
    }
    std::cout << '\n';
}

void Shop::resetShop(){
    for (auto& item : items) {
        item->resetQuantity();
    }
}

std::vector<Item<std::string, int>*>& Shop::getItems() {
    return items;
}

Shop::~Shop() {
    for (auto item : items) {
        delete item;
    }
    items.clear();
}