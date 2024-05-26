#ifndef OOP_POTION_H
#define OOP_POTION_H

#include "item.h"
#include "player.h"
#include <iostream>

class Player;

template <typename N, typename P>

class Potion : public Item<N, P> {
private:
    N name;
    P hp;
public:
    Potion(N name, P hp, P price, P quantity, P initQuantity)
            : Item<N, P>(std::move(name), hp, price, quantity, initQuantity), hp(hp) {}

//    void use(Player& player);
//    [[nodiscard]] P getHp();
//    [[nodiscard]] N getName();
    void use(Player& player)
    {
        int hpToAdd = getHp();
        std::cout << "Valoare hpToAdd: " << hpToAdd << std::endl;
        std::cout << "HP-ul jucătorului înainte de utilizare: " << player.getHp() << std::endl;
        player.addHp(hpToAdd);
        std::cout << "HP-ul jucătorului după utilizare: " << player.getHp() << std::endl;
        std::cout << "Ai folosit potiunea " << getName() << ". Aceasta iti adauga " << hpToAdd << " hp." << std::endl;
    }

    P getHp(){
        return hp;
    }

    N getName(){
        return name;
    }
};

#endif // OOP_POTION_H
