#include "player.h"
#include "shop.h"
#include "item.h"



Player::Player(std::basic_string<char> name, int hp, int atk, int gold, int exp, int level) {
    this->name = std::move(name);
    this->hp = hp;
    this->atk = atk;
    this->gold = gold;
    this->exp = exp;
    this->level = level;
}

std::ostream& operator<<(std::ostream& out, const Player& player) {
    out << "NAME: " << player.name << '\n';
    out << "HP: " << player.hp << "; DMG: " << player.atk << "; GOLD: " << player.gold << "; EXP: " << player.exp<< "; LEVEL: " << player.level << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Player& pl) {
    in >> pl.name;
    return in;
}

std::basic_string<char> Player::getName() const {
    return name;
}

int Player::getHp() const {
    return hp;
}

int Player::getAtk() const {
    return atk;
}

int Player::getLvl() const {
    return level;
}

int Player::getVerify() const {
    return verify;
}

int Player::getGold() const {
    return gold;
}

void Player::LowHp_Skill() {
    if(level >= 1 && hp <= 50 && lhps != 0)
    {
        std::cout << '\n' << "Hey, "<< name << "...mai ai putin hp...ai putea sa mori daca continui batalia." << '\n';
        std::cout << '\n' << "Totusi te poate ajuta skill-ul deblocat (LowHp Skill)!" << '\n';
        std::cout << '\n' << "Mai ai: " << lhps << " folosiri!" << '\n';
        std::cout << '\n' << "Ce alegi?" << '\n';
        std::cout << "1.Use Skill" << '\n';
        std::cout << "2.Fugi" << '\n';
        int interact;
        std::cin >> interact;
        switch (interact) {
            case 1:
                hp+=hp;
                atk+=5;
                lhps--;
                break;
            case 2:
                verify = interact;
                break;
            default:
                break;
        }
    }
}

void Player::addToInventory(Item<std::string, int>& item)
{
    bool found = false;
    for(auto& eItem : inventory)
    {
        if(eItem.getName() == item.getName())
        {
            eItem.setQuantity(eItem.getQuantity() + 1);
            found = true;
            break;
        }
    }
    if (!found) {
        inventory.emplace_back(item.getName(), item.getProp(), item.getPrice(), 1, item.getinitQuantity());
    }
}

void Player::showInventory() {
    std::cout << "Inventarul:\n";
    for (unsigned int i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ". " << inventory[i].getName() << " (" << inventory[i].getQuantity() << ")" <<'\n';
    }
}

//int Player::getInventorySize() const {
//    return inventory.size();
//}

bool Player::isInventoryEmpty() const {
    return inventory.empty();
}

void Player::buyItem(Item<std::string, int>& item, Shop& shop) {
    if (gold >= item.getPrice() && item.getQuantity() != 0)
    {
        gold -= item.getPrice();
        addToInventory(item);
        std::cout << "Ai cumparat " << item.getName() << " cu succes!" << '\n' << '\n';

        for (auto& shopItem : shop.getItems())
        {
            if (shopItem->getName() == item.getName())
            {
                *shopItem = Item(item.getName(), shopItem->getProp(), item.getPrice(), item.getQuantity() - 1, item.getinitQuantity());
                break;
            }
        }
    }
    else if(gold < item.getPrice())
    {
        std::cout << "Nu ai suficient aur pentru a cumpara " << item.getName() << "." << '\n' << '\n';
    }
    else if(item.getQuantity() == 0)
    {
        std:: cout << "Magazinul nu are stocuri suficiente. Ne pare rau!" << '\n' << '\n';
    }
}

void Player::addHp(int hpp)
{
    this->hp += hpp;
}

void Player::addAtk(int atkk)
{
    this->atk += atkk;
}

void Player::useItem(int index) {
    if (index >= 0 && unsigned(index) < inventory.size()) {
        std::cout << "Item selectat: " << inventory[index].getName() << std::endl;

        if (inventory[index].getName() == "Small Health Potion" || inventory[index].getName() == "Medium Health Potion" || inventory[index].getName() == "Large Health Potion" || inventory[index].getName() == "Random Healing Potion")
        {
            std::cout << "Se apeleaza metoda Potion::use()" << std::endl;
            Player::addHp(inventory[index].getProp());
            std::cout << "Hp-ul tau dupa utilizarea potiunii:" << Player::getHp() << "hp." << std::endl;
        }
        else if (inventory[index].getName() == "Silver Sword" || inventory[index].getName() == "Custom Sword") {
            std::cout << "Se apeleaza metoda Sword::use()" << std::endl;
            Player::addAtk(inventory[index].getProp());
            std::cout << "Puterea ta dupa utilizarea sabiei:" << Player::getAtk() << "dmg." << std::endl;
        }

        inventory[index].setQuantity(inventory[index].getQuantity() - 1);

        if (inventory[index].getQuantity() == 0) {
            inventory.erase(inventory.begin() + index);
        }
    } else {
        std::cout << "Indexul itemului este invalid." << std::endl;
    }
}

//void Player::useItem(int index) {
//    if (index >= 0 && unsigned(index) < inventory.size()) {
//        std::cout << "Item selectat: " << inventory[index].getName() << std::endl; // Mesaj pentru afișarea numelui elementului selectat
//
//        if (inventory[index].getName() == "Small Health Potion" || inventory[index].getName() == "Medium Health Potion" || inventory[index].getName() == "Large Health Potion") {
//            std::cout << "Se apeleaza metoda Potion::use()" << std::endl; // Mesaj pentru a verifica dacă metoda Potion::use() este apelată
//            dynamic_cast<Potion&>(inventory[index]).use(*this);
//        } else if (inventory[index].getName() == "Sword") {
//            std::cout << "Se apeleaza metoda Sword::use()" << std::endl; // Mesaj pentru a verifica dacă metoda Sword::use() este apelată
//            dynamic_cast<Sword&>(inventory[index]).use(*this);
//        }
//
//        inventory[index].setQuantity(inventory[index].getQuantity() - 1);
//
//        if (inventory[index].getQuantity() == 0) {
//            inventory.erase(inventory.begin() + index);
//        }
//    } else {
//        std::cout << "Indexul itemului este invalid." << std::endl;
//    }
//}

//void Player::useItem(int index) {
//    if (index >= 0 && static_cast<size_t>(index) < inventory.size()) {
//        std::cout << "Item selectat: " << inventory[index].getName() << std::endl; // Mesaj pentru afișarea numelui elementului selectat
//
//        Potion* potion = dynamic_cast<Potion*>(&inventory[index]);
//        if (potion != nullptr) {
//            std::cout << "Se apeleaza metoda Potion::use()" << std::endl; // Mesaj pentru a verifica dacă metoda Potion::use() este apelată
//            potion->use(*this);
//        } else {
//            std::cout << "Elementul selectat nu este o potiune." << std::endl;
//            std::cout << "Item selectat: " << inventory[index].getName() << ", tip: " << typeid(inventory[index]).name() << std::endl;
//        }
//
//        inventory[index].setQuantity(inventory[index].getQuantity() - 1);
//
//        if (inventory[index].getQuantity() == 0) {
//            inventory.erase(inventory.begin() + index);
//        }
//    } else {
//        std::cout << "Indexul itemului este invalid." << std::endl;
//    }
//}

void Player::takeDmg(int damage)
{
    hp -= damage;
    if(hp < 0) hp = 0;
    std::cout << name << " a suferit " << damage << " damage. " << name << " are acum " << hp << " health." << std::endl;
}

bool Player::isAlive() const
{
    return hp > 0;
}

void Player::player_earn(int experience, int coins)
{
    exp += experience;
    gold += coins;
}

void Player::LevelUp_Player()
{
    const int expPerLvl = 1000;
    if (exp >= expPerLvl)
    {
        level++;
        exp -= expPerLvl;
        hp = lhp + 40;
        lhp = hp;
        atk += 5;
        Shop::resetShop();
        std::cout << "Felicitari! Ai acum nivelul: " << level << "!" << '\n';
        if(level == 1)
        {
            std::cout << '\n' << "        Ai deblocat un nou Skill!        " << '\n';
            std::cout << '\n' << "---------------LowHp Skill---------------" << '\n';
            std::cout << '\n' << "Se pare ca acest Skill are " << lhps << " utilizari." << '\n';
            std::cout << '\n' << "Nu te teme! Utilizarile Skill-ului se refac la fiecare level-up!" << '\n';
            std::cout << '\n' << "Totusi foloseste-l cu grija. Numai atunci cand ai cu adevarata nevoie!" << '\n';
            std::cout << '\n' << "Stats: Acest Skill iti dubleaza hp-ul ramas si iti creste atacul cu 5 puncte." << '\n';
            std::cout << '\n' << '\n';
        }
        if(level >= 2)
        {
            std::cout << '\n' << "Skill use resetat!" << '\n' << '\n';
            lhps = 2;
        }
    }
}