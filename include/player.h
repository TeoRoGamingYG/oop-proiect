//
// Created by Teo on 4/21/2024.
//
#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H

#include <iostream>
#include <vector>
#include <string>
#include "item.h"
class Shop;
class Potion;
class Sword;

class Player {
private:
    int hp = 500, exp = 0, level = 0, gold = 100, atk = 20, lhp = hp, lhps = 2;
    int verify = 0;
    std::vector<Item> inventory;
    std::string name;
public:
    void buyItem(const Item& item, Shop& shop);
    void useItem(int index);
    Player(std::string name, int hp, int atk, int gold, int exp, int level);

    friend std::ostream& operator<<(std::ostream& out, const Player& player);
    friend std::istream& operator>>(std::istream& in, Player& pl);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getAtk() const;
    [[nodiscard]] int getLvl() const;
    [[nodiscard]] int getVerify() const;
    [[nodiscard]] int getGold() const;

    void LowHp_Skill();
    void addToInventory(const Item& item);
    void showInventory() const;
    [[nodiscard]] int getInventorySize() const;
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