#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "item.h"
#include "shop.h"

template <typename N, typename P>
class Potion;

template <typename N, typename P>
class Sword;

class Player {
private:
    int hp = 500, exp = 0, level = 0, gold = 100, atk = 20, lhp = hp, lhps = 2;
    int verify = 0;
    std::vector<Item<std::string, int>> inventory;
    std::string name;
public:
    void buyItem(Item<std::string, int>& item, Shop& shop);
    void useItem(int index);
    Player(std::string name, int hp, int atk, int gold, int exp, int level);

    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    friend std::istream& operator>>(std::istream& in, Player& pl);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getAtk() const;
    [[nodiscard]] int getLvl() const;
    [[nodiscard]] int getVerify() const;
    [[nodiscard]] int getGold() const;

    void LowHp_Skill();
    void addToInventory(Item<std::string, int>& item);
    void showInventory();
    //[[nodiscard]] int getInventorySize() const;
    [[nodiscard]] bool isInventoryEmpty() const;
    void addHp(int hp);
    void addAtk(int atk);
    void takeDmg(int damage);
    [[nodiscard]] bool isAlive() const;
    void player_earn(int experience, int coins);
    void LevelUp_Player();
    ~Player() = default;
};

#endif