//
// Created by Teo on 4/21/2024.
//
#include "Item.h"

Item::Item(std::string name, int prop, int price, int quantity)
        : name(std::move(name)), price(price), quantity(quantity), prop(prop) {}

const std::string& Item::getName() const { return name; }
int Item::getPrice() const { return price; }
int Item::getQuantity() const { return quantity; }
int Item::getProp() const { return prop; }
void Item::setQuantity(int nQ) { quantity = nQ; }

