#ifndef OOP_MOB_H
#define OOP_MOB_H

#include <iostream>
#include <string>

class Mob {
private:
    std::string name;
    int hp, ihp, atk, gold, exp;

public:
    Mob(std::string name, int hp, int atk, int gold, int exp);

    Mob(const Mob& other) = default;
    Mob& operator=(const Mob& aux) = default;

    Mob& operator+(const Mob& mob) const;

    friend std::ostream& operator<<(std::ostream& out, const Mob& mob);

    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getHp() const;
    [[nodiscard]] int getAtk() const;
    [[nodiscard]] int getGold() const;
    [[nodiscard]] int getExp() const;

    void takeDmg(int damage);
    [[nodiscard]] bool isAlive() const;
    void reset_mob_hp();

    ~Mob() = default;
};

bool operator<(const Mob& mob1, const Mob& mob2);

#endif //OOP_MOB_H
