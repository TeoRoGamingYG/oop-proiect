#ifndef OOP_ITEM_H
#define OOP_ITEM_H

#include <string>

class Item {
protected:
    std::string name;
    int price, quantity, prop;
public:
    Item(std::string name, int prop, int price, int quantity);

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] int getPrice() const;
    [[nodiscard]] int getQuantity() const;
    [[nodiscard]] int getProp() const;
    void setQuantity(int nQ);
    virtual ~Item() = default;
};

#endif //OOP_ITEM_H