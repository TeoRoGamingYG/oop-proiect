#include <gtest/gtest.h>
#include "example.h"
#include "potion.h"
#include "sword.h"
#include "player.h"

TEST(SuiteName, TestName) {

    EXPECT_EQ(doSomething(10), 10);
    // Other assertions: https://google.github.io/googletest/reference/assertions.html#boolean
}

TEST(SuiteName, test_potiune) {
    Player player("Gogu", 500, 20, 100, 0, 0);
    Potion<std::string, int> healthpotion("Potiune", 20, 100, 3, 3);
    int initialHP = player.getHp();
    healthpotion.use(player);
    int newHP = player.getHp();
    EXPECT_EQ(newHP, initialHP + 20);
}

TEST(SuiteName, test_sabie) {
    Player player("Gogu", 500, 20, 100, 0, 0);
    Sword<std::string, int> sabie("SabieFer", 20, 30, 1, 1);
    int initialAtk = player.getAtk();
    sabie.use(player);
    int newAtk = player.getAtk();
    EXPECT_EQ(newAtk, initialAtk + 20);
}