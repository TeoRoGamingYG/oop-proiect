//
// Created by Teo on 4/21/2024.
//

#ifndef OOP_MOB_H
#define OOP_MOB_H

#include <iostream>

class MobInput {
public:
    virtual void handleInput() const = 0;
};

class Mob {
private:
    std::string name;
    int health;
    int attackDamage;
    int defense;

public:
    Mob(std::string name, int health, int attackDamage, int defense);
    ~Mob();

    std::string getName() const;
    int getHealth() const;
    void setHealth(int health);
    int getAttackDamage() const;
    int getDefense() const;

    void takeDamage(int amount);
    void attack(Mob* target);
};

class Goblin : public Mob {
public:
    Goblin();
};

class Troll : public Mob {
public:
    Troll();
};

#endif //OOP_MOB_H
