#ifndef OOP_SWORD_H
#define OOP_SWORD_H

#include <iostream>
#include "item.h"

class Player;

template <typename N, typename P>
class Sword : public Item<N, P> {
private:
    N name3;
    P atk;
public:
    Sword(N name3, P atk, P price, P quantity, P initQuantity)
            : Item<N, P>(std::move(name3), atk, price, quantity, initQuantity), atk(atk) {}

    void use(Player& player) {
        int atkToAdd = getAtk();
        std::cout << "Ai echipat sabia " << getName() << ".\n";
        player.addAtk(atkToAdd);
    }

    P getAtk() {
        return atk;
    }

    N getName() const{
        return name3;
    }
};

#endif // OOP_SWORD_H
