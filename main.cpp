#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include "item.h"
#include "potion.h"
#include "sword.h"
#include "shop.h"
#include "player.h"
#include "mob.h"
#include "attack.h"

//class Player;
//
//class Item {
//protected:
//    std::string name;
//    int price, quantity, prop;
//public:
//    Item(std::string name, int prop, int price, int quantity)
//            : name(std::move(name)), price(price), quantity(quantity), prop(prop) {}
//
//    [[nodiscard]] const std::string& getName() const { return name; }
//    [[nodiscard]] int getPrice() const { return price; }
//    [[nodiscard]] int getQuantity() const { return quantity; }
//    [[nodiscard]] int getProp() const { return prop; }
//    void setQuantity(int nQ) { quantity = nQ; }
//    virtual ~Item() = default;
//};
//
//
//class Potion : public Item {
//private:
//    int hp;
//public:
//    Potion(std::string name, int hp, int price, int quantity) : Item(name, hp, price, quantity), hp(hp) {}
//    void use(Player& player);
//};
//
//class Sword : public Item {
//private:
//    int atk;
//public:
//    Sword(std::string name, int atk, int price, int quantity) : Item(name, atk, price, quantity), atk(atk) {}
//    void use(Player& player);
//};
//
//class Shop{
//private:
//    std::vector<Item> items;
//public:
//    void addPotion(const Potion& potion) {
//        items.push_back(potion);
//    }
//
//    void addSword(const Sword& sword) {
//        items.push_back(sword);
//    }
//
//    void displayItems() const
//    {
//        std::cout << "Shop:\n" << '\n';
//        for (const auto& item : items)
//        {
//            std::cout << item.getName() << " (" << item.getProp() << " hp)" << " - Pret: " << item.getPrice() << " (Stoc: " << item.getQuantity() << ")" << '\n';
//        }
//        std::cout << '\n';
//    }
//
//    [[nodiscard]] std::vector<Item>& getItems() {return items;}
//};
//
//class Player{
//private:
//    int hp = 500, exp = 0, level = 0, gold = 100, atk = 20, lhp = hp, lhps = 2;
//    int verify = 0;
//    std::vector<Item>inventory;
//    std::string name;
//public:
//    Player(std::string name, int hp, int atk, int gold, int exp, int level)
//    {
//        this->name = std::move(name);
//        this->hp = hp;
//        this->atk = atk;
//        this->gold = gold;
//        this->exp = exp;
//        this->level = level;
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const Player& player);
//    friend std::istream& operator>>(std::istream& in, Player& pl);
//
//    [[nodiscard]] std::string getName()const{return name;}
//    //[[nodiscard]] int getHp()const{return hp;}
//    [[nodiscard]] int getAtk()const{return atk;}
//    [[nodiscard]] int getLvl()const{return level;}
//    [[nodiscard]] int getVerify()const{return verify;}
//    [[nodiscard]] std::vector<Item> getInv()const{return inventory;}
//    [[nodiscard]] int getGold()const{return gold;}
//
//    void LowHp_Skill()
//    {
//        if(level >= 1 && hp <= 50 && lhps != 0)
//        {
//            std::cout << '\n' << "Hey, "<< name << "...mai ai putin hp...ai putea sa mori daca continui batalia." << '\n';
//            std::cout << '\n' << "Totusi te poate ajuta skill-ul deblocat (LowHp Skill)!" << '\n';
//            std::cout << '\n' << "Mai ai: " << lhps << " folosiri!" << '\n';
//            std::cout << '\n' << "Ce alegi?" << '\n';
//            std::cout << "1.Use Skill" << '\n';
//            std::cout << "2.Fugi" << '\n';
//            int interact;
//            std::cin >> interact;
//            switch (interact) {
//                case 1:
//                    hp+=hp;
//                    atk+=5;
//                    lhps--;
//                    break;
//                case 2:
//                    verify = interact;
//                    break;
//                default:
//                    break;
//            }
//        }
//    }
//
//    void addToInventory(const Item& item)
//    {
//        bool found = false;
//        for(auto& eItem : inventory)
//        {
//            if(eItem.getName() == item.getName())
//            {
//                eItem.setQuantity(eItem.getQuantity() + 1);
//                found = true;
//                break;
//            }
//        }
//        if (!found) {
//            inventory.emplace_back(item.getName(), item.getProp(), item.getPrice(), 1);
//        }
//    }
//
//    void showInventory() const
//    {
//        std::cout << "Inventarul:\n";
//        for (int i = 0; i < inventory.size(); ++i)
//        {
//            std::cout << i + 1 << ". " << inventory[i].getName() << " (" << inventory[i].getQuantity() << ")" <<'\n';
//        }
//    }
//
//    std::vector<Item> getInventory() {
//        return inventory;
//    }
//
//    [[nodiscard]] int getInventorySize() const
//    {
//        return inventory.size();
//    }
//
//    [[nodiscard]] bool isInventoryEmpty() const
//    {
//        return inventory.empty();
//    }
//
//    void buyItem(const Item& item, Shop& shop)
//    {
//        if (gold >= item.getPrice() && item.getQuantity() != 0)
//        {
//            gold -= item.getPrice();
//            addToInventory(item);
//            std::cout << "Ai cumparat " << item.getName() << " cu succes!" << '\n' << '\n';
//
//            for (auto& shopItem : shop.getItems())
//            {
//                if (shopItem.getName() == item.getName())
//                {
//                    shopItem = Item(item.getName(), shopItem.getProp(), item.getPrice(), item.getQuantity() - 1);
//                    break;
//                }
//            }
//        }
//        else if(gold < item.getPrice())
//        {
//            std::cout << "Nu ai suficient aur pentru a cumpara " << item.getName() << "." << '\n' << '\n';
//        }
//        else if(item.getQuantity() == 0)
//        {
//            std:: cout << "Magazinul nu are stocuri suficiente. Ne pare rau!" << '\n' << '\n';
//        }
//    }
//
//    void useItem(int index)
//    {
//        if (index >= 0 && index < inventory.size())
//        {
//            if (inventory[index].getName() == "Potion")
//            {
//                Potion potion = dynamic_cast<Potion&>(inventory[index]);
//                potion.use(*this);
//
//                inventory[index].setQuantity(inventory[index].getQuantity() - 1);
//
//                if (inventory[index].getQuantity() == 0)
//                {
//                    inventory.erase(inventory.begin() + index);
//                }
//            }
//            else if (inventory[index].getName() == "Sword")
//            {
//                Sword sword = dynamic_cast<Sword&>(inventory[index]);
//                sword.use(*this);
//            }
//        }
//        else std::cout << "Indexul itemului este invalid." << std::endl;
//    }
//
//    void addHp(int hp)
//    {
//        this->hp += hp;
//    }
//
//    void addAtk(int atk)
//    {
//        this->atk += atk;
//    }
//
//    void takeDmg(int damage)
//    {
//        hp -= damage;
//        if(hp < 0) hp = 0;
//        std::cout << name << " a suferit " << damage << " damage. " << name << " are acum " << hp << " health." << std::endl;
//    }
//
//    [[nodiscard]] bool isAlive() const
//    {
//        return hp > 0;
//    }
//
//    void player_earn(int experience, int coins)
//    {
//        exp += experience;
//        gold += coins;
//    }
//
//    void LevelUp_Player()
//    {
//        const int expPerLvl = 1000;
//        if (exp >= expPerLvl)
//        {
//            level++;
//            exp -= expPerLvl;
//            hp = lhp + 40;
//            lhp = hp;
//            atk += 5;
//            std::cout << "Felicitari! Ai acum nivelul: " << level << "!" << '\n';
//            if(level == 1)
//            {
//                std::cout << '\n' << "        Ai deblocat un nou Skill!        " << '\n';
//                std::cout << '\n' << "---------------LowHp Skill---------------" << '\n';
//                std::cout << '\n' << "Se pare ca acest Skill are " << lhps << " utilizari." << '\n';
//                std::cout << '\n' << "Nu te teme! Utilizarile Skill-ului se refac la fiecare level-up!" << '\n';
//                std::cout << '\n' << "Totusi foloseste-l cu grija. Numai atunci cand ai cu adevarata nevoie!" << '\n';
//                std::cout << '\n' << "Stats: Acest Skill iti dubleaza hp-ul ramas si iti creste atacul cu 5 puncte." << '\n';
//                std::cout << '\n' << '\n';
//            }
//            if(level >= 2)
//            {
//                std::cout << '\n' << "Skill use resetat!" << '\n' << '\n';
//                lhps = 2;
//            }
//        }
//    }
//    ~Player()=default;
//};
//
//std::ostream& operator<<(std::ostream& out, const Player& player) {
//    out << "NAME: " << player.name << '\n';
//    out << "HP: " << player.hp << "; DMG: " << player.atk << "; GOLD: " << player.gold << "; EXP: " << player.exp<< "; LEVEL: " << player.level << '\n';
//    return out;
//}
//
//std::istream& operator>>(std::istream& in, Player& pl) {
//    in >> pl.name;
//    return in;
//}
//
//class Mob{
//private:
//    std::string name;
//    int hp, ihp, atk, gold, exp;
//public:
//    Mob(std::string name, int hp, int atk, int gold, int exp)
//            : name(std::move(name)), hp(hp), ihp(hp), atk(atk), gold(gold), exp(exp){}
//
//    Mob(const Mob& other) = default;
//    Mob& operator=(const Mob& aux) = default;
//
//    Mob& operator+(const Mob& mob) const {
//        Mob* result = new Mob(*this);
//        result->name = "Evolved " + name;
//        result->hp = mob.hp / 2 + hp;
//        result->atk = mob.atk / 2 + atk;
//        result->gold += gold;
//        result->exp = mob.exp / 5 + exp;
//        return *result;
//    }
//
//    friend std::ostream& operator<<(std::ostream& out, const Mob& mob);
//
//    [[nodiscard]] std::string getName()const{return name;}
//    [[nodiscard]] int getHp()const{return hp;}
//    [[nodiscard]] int getAtk()const{return atk;}
//    [[nodiscard]] int getGold()const{return gold;}
//    [[nodiscard]] int getExp()const{return exp;}
//
//    void takeDmg(int damage)
//    {
//        if(hp >= damage)
//            hp -= damage;
//        else hp = 0;
//        std::cout << name << " a suferit " << damage << " damage. " << name << " are acum " << hp << " health." << std::endl;
//    }
//
//    [[nodiscard]] bool isAlive() const
//    {
//        return hp > 0;
//    }
//
//    void reset_mob_hp()
//    {
//        hp = ihp;
//    }
//
//    ~Mob()=default;
//};
//
//std::ostream& operator<<(std::ostream& out, const Mob& mob) {
//    out << "NAME: " << mob.name << '\n';
//    out << "HP: " << mob.hp << "; DMG: " << mob.atk << "; EXP: " << mob.exp << '\n';
//    return out;
//}
//
//bool operator<(const Mob& mob1, const Mob& mob2) {
//    return mob1.getHp() < mob2.getHp();
//}

void input_mobi(int n)
{
    std::vector<Mob> mobs;
    for(int i = 0; i < n; i++)
    {
        std::string name;
        int hp = 0, atk = 0, gold = 0, exp = 0;
        std::cout<<'\n';
        std::cout<<"NAME: ";
        std::cin>>name;
        std::cout<<" HP: ";
        std::cin>>hp;
        std::cout<<" DMG: ";
        std::cin>>atk;
        std::cout<<" GOLD: ";
        std::cin>>gold;
        std::cout<<" EXP: ";
        std::cin>>exp;

        Mob x(name,hp,atk,gold,exp);
        mobs.push_back(x);
    }
    std::cout<<'\n';
    for(int i = 0; i < n; i++)
    {
        std::cout<<mobs[i]<<'\n';
    }
}

//class Attack {
//public:
//    static void performAttack(Player& player, Mob& mob)
//    {
//        mob.takeDmg(player.getAtk());
//        if (mob.isAlive())
//        {
//            player.takeDmg(mob.getAtk());
//        }
//    }
//    ~Attack()=default;
//};

void fightEnemy(Player& player, Mob& currentEnemy)
{
    while (player.isAlive() && currentEnemy.isAlive() && player.getVerify() != 2) {
        Attack::performAttack(player, currentEnemy);
        player.LowHp_Skill();
    }
    if (player.getVerify() == 2) {
        std::cout << '\n' << "Felicitari! Ai reusit sa scapi de: " << currentEnemy.getName() << '\n' << '\n';
    } else if (player.isAlive()) {
        std::cout << '\n' << '\n';
        std::cout << player.getName() << " wins!" << std::endl;
        std::cout << '\n' << '\n';
        currentEnemy.reset_mob_hp();
        player.player_earn(currentEnemy.getExp(), currentEnemy.getGold());
        player.LevelUp_Player();
        std::cout << "Informatii despre jucator:\n";
        std::cout << player << '\n' << '\n';
    } else {
        std::cout << currentEnemy.getName() << " wins!" << std::endl;
        std::cout << '\n' << '\n';
        std::cout << "--------GAME OVER--------";
        std::cout << '\n' << '\n';
        exit(0);
    }
}

//void Potion::use(Player& player) {
//    int hpToAdd = getProp();
//    std::cout << "Ai folosit potiunea " << getName() << ". Aceasta iti adauga " << hpToAdd << " hp." << std::endl;
//    player.addHp(hpToAdd);
//}
//
//void Sword::use(Player& player) {
//    int atkToAdd = getProp();
//    std::cout << "Ai echipat sabia " << getName() << ".\n";
//    player.addAtk(atkToAdd);
//}

int main()
{
    srand(time(nullptr));
    std::cout<<"    Bine te-am gasit!"<<'\n';
    std::cout<<"    Incepem printr-un mic tutorial, asa de inceput. In mare parte tu vei apasa doar pe niste butoane,"<<'\n';
    std::cout<<"nimic mai mult! Dar trebuie sa ai mare grija pe ce apesi ca vei putea muri si pierde tot progresul :("<<'\n';
    std::cout<<"Joculetul este asemanator cu Greedy Cave. Ai un jucator, mobi cu care sa te lupti si poti obtine dropuri."<<'\n';
    std::cout<<"Dropurile te vor ajuta pe parcursul drumului deoarece iti vor imbunatatii stats-urile si astfel sa iesi"<<'\n';
    std::cout<<"victorios din grota!"<<'\n';
    std::cout<<"    P.S: Ai grija sa nu opresti rularea programului ca te ai dus...pierzi tot progresul din pacate ://"<<'\n';
    std::cout<<'\n'<<'\n';
    std::cout<<"Alege numele tau: ";
    Player player("", 500, 20, 100, 0, 0);
    Potion healthPotionSmall("Small Health Potion", 25, 100, 3);
    Potion healthPotionMedium("Medium Health Potion", 40, 150, 3);
    Potion healthPotionLarge("Large Health Potion", 75, 225, 3);
    Sword silverSword("Silver Sword", 20, 500, 1);
    Shop shop;
    shop.addPotion(healthPotionSmall);
    shop.addPotion(healthPotionMedium);
    shop.addPotion(healthPotionLarge);
    shop.addSword(silverSword);
    std::cin>>player;
    std::cout<<'\n'<<'\n'<<"Salut "<< player.getName() <<'\n';
    std::cout<<'\n'<<'\n';
    std::cout<<"Acum cu interactiunile:"<<'\n';
    std::cout<<"1.Start"<<'\n';
    std::cout<<"2.Exit"<<'\n';
    std::cout<<'\n'<<'\n'<<"--------O MICA PARANTEZA--------"<<'\n'<<'\n';
    std::cout<<"Sa ne distram cu inputul si outputul de mobi:"<<'\n'<<'\n';
    std::cout<<"Da un numar de mobi: ";
    int n;
    std::cin>>n;
    std::cout<<'\n';
    input_mobi(n);
    std::cout<<'\n'<<"Revenim la joc (1.Start; 2.Exit;) ... ";
    std::vector<Mob> enemies = {
            Mob("Cave Zombie", 100, 10, 35, 150),
            Mob("McWolf", 60, 10, 25, 100),
            Mob("Gorlock the Destroyer", 250, 20, 50, 200)
    };
    Mob mob_evo_zombie = enemies[0] + enemies[0];
    Mob mob_evo_mcwolf = enemies[1] + enemies[1];
    Mob mob_evo_gorlock = enemies[2] + enemies[2];
    enemies.insert(enemies.begin()+3,mob_evo_zombie);
    enemies.insert(enemies.begin()+4,mob_evo_mcwolf);
    enemies.insert(enemies.begin()+5,mob_evo_gorlock);
    int interact1;
    std::cin>>interact1;
    if(interact1 == 1)
    {
        std::cout<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n'<<'\n';
        std::cout<<"    Esti un calator doritor de aventura. Ai citit cartea pe care bunicul tau ti-a lasat-o inainte ca acesta sa moara"<<'\n';
        std::cout<<"si afli de un oras numit Evanghelion cu o istorie spectaculoasa si care contine o pestera intunecata plina de monstri"<<'\n';
        std::cout<<"infricosatori care cel mai probabil doresc sa-ti manance creierul...hehe. Desigur, daca reusesti sa-i omori vei capata"<<'\n';
        std::cout<<"iteme de valoare sau care te vor ajuta in noi aventuri periculoase."<<'\n';
        std::cout<<"    Te decizi sa pornesti in aceasta calatorie de unul singur spre asa numitul 'Solo Leveling Cave'."<<'\n';
        std::cout<<"    Dupa o lunga calatorie, de o zi si o noapte, ajungi in Evanghelion, iar niste localnici de treaba iti arata drumul"<<'\n';
        std::cout<<"spre pestera intunecata."<<'\n';
        std::cout<<"    Iti iei inima-n dinti si faci primul pas in pestera. Aprinzi o torta si continui sa avansezi."<<'\n';
        std::cout<<"    'Am vrut pestera eu...da...cu putoarea asta mai bine-mi iau direct viata si termin mai repede...'"<<'\n';
        std::cout<<"    Lasand la o parte dorintele de suicid, continui sa inaintezi si auzi in departare un raget puternic.";
        std::cout<<'\n'<<'\n'<<"................"<<'\n'<<'\n';
        std::cout<<"    Este primul monstru cu care te intalnesti? Daca da, ai mai multe posibilitati in momentul de fata. Ce alegi?";
        std::cout<<'\n'<<'\n'<<"................"<<'\n'<<'\n';
        int interact2 = 1;
        int mobIndex;
        while (interact2 != 0)
        {
            if(player.getLvl() == 0) mobIndex = rand() % 3;
            else mobIndex = rand() % 6;
            Mob& currentEnemy = enemies[mobIndex];
            std::cout << "Ai in fata ta un " << currentEnemy.getName() << '\n' << '\n';
            std::cout << "Informatii despre monstru:\n";
            std::cout << enemies[mobIndex] << '\n';
            std::cout << "1.Ataca" << '\n';
            std::cout << "2.Inventory" << '\n';
            std::cout << "3.Shop" << '\n';
            std::cout << "4.Fugi" << '\n';
            std::cout << "0.Exit Cave" << '\n';
            std::cin >> interact2;
            switch (interact2)
            {
                case 0:
                    return 0;
                case 1:
                    fightEnemy(player, currentEnemy);
                    break;
                case 2:
                    if (!player.isInventoryEmpty())
                    {
                        player.showInventory();
                        std::cout << "Ce item vrei sa folosesti?" << '\n';
                        int choice;
                        std::cin >> choice;
                        if (choice >= 1 && choice <= player.getInventorySize()) {
                            player.useItem(choice - 1);
                        } else {
                            std::cout << "Selectare invalida." << '\n';
                        }
                    }
                    else {
                        std::cout << "Inventarul este gol." << std::endl;
                    }
                    std::cout << "Vrei sa accesezi shopul?" << '\n';
                    std::cout << "1.DA" << '\n';
                    std::cout << "2.NU" << '\n';
                    int interact3;
                    std::cin >> interact3;
                    if(interact3 == 1)
                    {
                        shop.displayItems();
                        const std::vector<Item>& shopItems = shop.getItems();
                        if(player.getGold() < shopItems[0].getPrice())
                            std::cout << "Ai fonduri insuficiente pentru a mai putea cumpara din magazin!" << '\n' << '\n';
                        else
                        {
                            std::cout << "Alege ce potiune doresti sa achizitionezi: " << '\n';
                            int ok = 1;
                            while(player.getGold() >= shopItems[0].getPrice() && ok == 1)
                            {
                                std::cout << "1." << shopItems[0].getName() << " (" << shopItems[0].getQuantity() << ")" << '\n';
                                std::cout << "2." << shopItems[1].getName() << " (" << shopItems[1].getQuantity() << ")" << '\n';
                                std::cout << "3." << shopItems[2].getName() << " (" << shopItems[2].getQuantity() << ")" << '\n';
                                std::cout << "4." << shopItems[3].getName() << " (" << shopItems[3].getQuantity() << ")" << '\n';
                                std::cout << "0.Exit Shop" << '\n';
                                int i;
                                std::cin >> i;
                                if(i == 0) break;
                                if(!shopItems.empty())
                                {
                                    const Item& itemToBuy = shopItems[i-1];
                                    player.buyItem(itemToBuy, shop);
                                }
                                if(player.getGold() < shopItems[0].getPrice())
                                {
                                    std::cout << "Ai fonduri insuficiente pentru a mai putea cumpara din magazin!" << '\n' << '\n';
                                    ok = 0;
                                }
                                else
                                {
                                    std::cout << "Continui cumparaturile?" << '\n';
                                    std::cout << "1.DA" << '\n';
                                    std::cout << "2.NU" << '\n';
                                    int j;
                                    std::cin >> j;
                                    if(j == 2) ok = 0;
                                }
                            }
                        }
                        std::cout << "Continui lupta sau fugi?" << '\n';
                        std::cout << "1.Continui" << '\n';
                        std::cout << "2.Fugi" << '\n';
                        std::cout << "0.Exit Cave" << '\n';
                        int interact4;
                        std::cin >> interact4;
                        if(interact4 == 1) fightEnemy(player, currentEnemy);
                        else if(interact4 == 2)
                        {
                            std::cout << '\n' << "Ai fugit de " << currentEnemy.getName() << "!" << '\n';
                            break;
                        }
                        else if(interact4 == 0) return 0;
                    }
                    else if(interact3 == 2)
                    {
                        std::cout << "Continui lupta sau fugi?" << '\n';
                        std::cout << "1.Continui" << '\n';
                        std::cout << "2.Fugi" << '\n';
                        std::cout << "0.Exit Cave" << '\n';
                        int interact4;
                        std::cin >> interact4;
                        if(interact4 == 1) fightEnemy(player, currentEnemy);
                        else if(interact4 == 2)
                        {
                            std::cout << '\n' << "Ai fugit de " << currentEnemy.getName() << "!" << '\n';
                            break;
                        }
                        else if(interact4 == 0) return 0;
                    }
                    break;
                case 4:
                    std::cout << '\n' << "Ai fugit de " << currentEnemy.getName() << "!" << '\n';
                    break;
                case 3:
                    shop.displayItems();
                    const std::vector<Item>& shopItems = shop.getItems();
                    if(player.getGold() < shopItems[0].getPrice())
                        std::cout << "Ai fonduri insuficiente pentru a putea cumpara din magazin!" << '\n' << '\n';
                    else
                    {
                        std::cout << "Alege ce potiune doresti sa achizitionezi: " << '\n';
                        int ok = 1;
                        while(player.getGold() >= shopItems[0].getPrice() && ok == 1)
                        {
                            std::cout << "1." << shopItems[0].getName() << " (" << shopItems[0].getQuantity() << ")" << '\n';
                            std::cout << "2." << shopItems[1].getName() << " (" << shopItems[1].getQuantity() << ")" << '\n';
                            std::cout << "3." << shopItems[2].getName() << " (" << shopItems[2].getQuantity() << ")" << '\n';
                            std::cout << "4." << shopItems[3].getName() << " (" << shopItems[3].getQuantity() << ")" << '\n';
                            std::cout << "0.Exit Shop" << '\n';
                            int i;
                            std::cin >> i;
                            if(i == 0) break;
                            if(!shopItems.empty())
                            {
                                const Item& itemToBuy = shopItems[i-1];
                                player.buyItem(itemToBuy, shop);
                            }
                            if(player.getGold() < shopItems[0].getPrice())
                            {
                                std::cout << "Ai fonduri insuficiente pentru a putea cumpara din magazin!" << '\n' << '\n';
                                ok = 0;
                            }
                            else
                            {
                                std::cout << "Continui cumparaturile?" << '\n';
                                std::cout << "1.DA" << '\n';
                                std::cout << "2.NU" << '\n';
                                int j;
                                std::cin >> j;
                                if(j == 2) ok = 0;
                            }
                        }
                    }
                    std::cout << "Continui lupta sau fugi?" << '\n';
                    std::cout << "1.Continui" << '\n';
                    std::cout << "2.Fugi" << '\n';
                    std::cout << "0.Exit Cave" << '\n';
                    int interact4;
                    std::cin >> interact4;
                    if(interact4 == 1) fightEnemy(player, currentEnemy);
                    else if(interact4 == 2)
                    {
                        std::cout << '\n' << "Ai fugit de " << currentEnemy.getName() << "!" << '\n';
                        break;
                    }
                    else if(interact4 == 0) return 0;
                    break;
            }
        }
    }
    return 0;
}