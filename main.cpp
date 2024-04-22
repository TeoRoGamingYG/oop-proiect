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