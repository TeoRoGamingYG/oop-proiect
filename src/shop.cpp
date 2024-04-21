//
// Created by Teo on 4/21/2024.
//
#include <iostream>
#include "shop.h"

Shop::Shop() {}

void Shop::addItem(Item* item) {
    stock.push_back(item);
}

void Shop::displayStock() const {
    std::cout << "Shop Stock:" << std::endl;
    for (size_t i = 0; i < stock.size(); ++i) {
        std::cout << "[" << i << "] " << stock[i]->getName() << std::endl;
    }
}

Item* Shop::buyItem(int index) {
    if (index >= 0 && index < stock.size()) {
        Item* item = stock[index];
        stock.erase(stock.begin() + index);
        return item;
    } else {
        std::cout << "Invalid item index!" << std::endl;
        return nullptr;
    }
}

std::vector<Item>& Shop::getItems() {return getItems();}
