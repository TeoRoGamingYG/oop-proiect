#ifndef OOP_SHOP_H
#define OOP_SHOP_H

#include <vector>
#include "item.h"

template <typename N, typename P>
class Potion;

template <typename N, typename P>
class Sword;

class Shop {
private:
    static std::vector<Item<std::string, int>*> items;
public:
    static void addPotion(Potion<std::string, int>& potion);
    static void addSword(Sword<std::string, int>& sword);
    static void displayItems();
    static void resetShop();
    static std::vector<Item<std::string, int>*>& getItems();
    ~Shop();
};

#endif //OOP_SHOP_H