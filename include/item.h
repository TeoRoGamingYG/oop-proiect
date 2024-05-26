#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>

class Player;

template <typename N, typename P>
class Item {
protected:
    N name1;
    P price; P prop; P quantity; P initQuantity;

public:
    Item(N name1, P prop, P price, P quantity, P initQuantity)
            : name1(std::move(name1)), price(price), prop(prop), quantity(quantity), initQuantity(initQuantity) {}

    [[nodiscard]] N& getName() { return name1; }
    [[nodiscard]] P getPrice() { return price; }
    [[nodiscard]] P getQuantity() { return quantity; }
    [[nodiscard]] P getinitQuantity() { return initQuantity; }
    [[nodiscard]] P getProp() { return prop; }
    void setQuantity(int nQ) { quantity = nQ; }
    void resetQuantity() { quantity = initQuantity; }

    //virtual void use(Player& player) = 0;
    virtual ~Item() = default;
};

#endif //OOP_ITEM_H
