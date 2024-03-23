    #include <iostream>
    #include <cstdlib>
    #include <string>
    #include <ctime>
    #include <utility>
    #include <vector>

    class Player{
    private:
        int hp = 500, exp = 0, level = 0, gold = 100, atk = 20, lhp = hp;
        std::string name;
    public:
        Player(std::string name, int hp, int atk, int gold, int exp, int level)
        {
            this->name = std::move(name);
            this->hp = hp;
            this->atk = atk;
            this->gold = gold;
            this->exp = exp;
            this->level = level;
        }

        friend std::ostream& operator<<(std::ostream& out, const Player& player);
        friend std::istream& operator>>(std::istream& in, Player& pl);

        [[nodiscard]] std::string getName()const{return name;}
        [[nodiscard]] int getAtk()const{return atk;}

        void takeDmg(int damage)
        {
            hp -= damage;
            if(hp < 0) hp = 0;
            std::cout << name << " a suferit " << damage << " damage. " << name << " are acum " << hp << " health." << std::endl;
        }

        [[nodiscard]] bool isAlive() const
        {
            return hp > 0;
        }

        void player_earn(int experience, int coins)
        {
            exp += experience;
            gold += coins;
        }

        void LevelUp_Player()
        {
            const int expPerLvl = 1000;
            if (exp >= expPerLvl)
            {
                level++;
                exp -= expPerLvl;
                hp = lhp + 40;
                lhp = hp;
                atk += 10;
                std::cout << "Felicitari! Ai acum nivelul: " << level << "!" << '\n';
            }
        }
        ~Player()=default;
    };

    std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << "Name: " << player.name << '\n';
        out << "HP: " << player.hp << "; DMG: " << player.atk << "; GOLD: " << player.gold << "; EXP: " << player.exp<< "; LEVEL: " << player.level << '\n';
        return out;
    }

    std::istream& operator>>(std::istream& in, Player& pl) {
        in >> pl.name;
        return in;
    }

    class Mob{
    private:
        std::string name;
        int hp, ihp, atk, gold, exp, level;
    public:
        Mob(std::string name, int hp, int atk, int gold, int exp, int level)
                : name(std::move(name)), hp(hp), ihp(hp), atk(atk), gold(gold), exp(exp), level(level) {}

        Mob(const Mob& other) = default;
        Mob& operator=(const Mob& aux) = default;

        Mob& operator+(const Mob& mob) {
            this->name = "Evolved " + name;
            this->hp = mob.hp / 2 + hp;
            this->atk = mob.atk / 2 + atk;
            this->gold += gold;
            this->exp = mob.exp / 5 + exp;
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& out, const Mob& mob);

        [[nodiscard]] std::string getName()const{return name;}
        [[nodiscard]] int getAtk()const{return atk;}
        [[nodiscard]] int getGold()const{return gold;}
        [[nodiscard]] int getExp()const{return exp;}

        void takeDmg(int damage)
        {
            hp -= damage;
            if(hp < 0) hp = 0;
            std::cout << name << " a suferit " << damage << " damage. " << name << " are acum " << hp << " health." << std::endl;
        }

        [[nodiscard]] bool isAlive() const
        {
            return hp > 0;
        }

        void reset_mob_hp()
        {
            hp = ihp;
        }

        void LevelUp_Mob()
        {
            level++;
            hp = ihp + 25;
            ihp = hp;
            atk += 10;
        }

        ~Mob()=default;
    };

    std::ostream& operator<<(std::ostream& out, const Mob& mob) {
        out << "Name: " << mob.name << '\n';
        out << "HP: " << mob.hp << "; DMG: " << mob.atk << "; EXP: " << mob.exp << '\n';
        return out;
    }

    class Attack {
    public:
        static void performAttack(Player& player, Mob& mob)
        {
            mob.takeDmg(player.getAtk());
            if (mob.isAlive())
            {
                player.takeDmg(mob.getAtk());
            }
        }
        ~Attack()=default;
    };

    //class Shop{
    //private:
    //    int hp_pot_small, hp_pot_medium, hp_pot_big;
    //public:
    //
    //};

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
        std::cin>>player;
        std::cout<<'\n'<<'\n'<<"Salut "<< player.getName() <<'\n';
        std::cout<<'\n'<<'\n';
        std::cout<<"Acum cu interactiunile:"<<'\n';
        std::cout<<"1.Start"<<'\n';
        std::cout<<"2.Exit"<<'\n';
        std::vector<Mob> enemies;
        enemies.emplace_back("Cave Zombie", 100, 10, 45, 150, 0);
        enemies.emplace_back("McWolf", 60, 10, 25, 100, 0);
        enemies.emplace_back("Gorlock the Destroyer", 250, 20, 75, 200, 0);

        Mob mob_evo_zombie = enemies[0] + enemies[0];
        Mob mob_evo_mcwolf = enemies[1] + enemies[1];
        Mob mob_evo_gorlock = enemies[2] + enemies[2];
        enemies.push_back(mob_evo_zombie);
        enemies.push_back(mob_evo_mcwolf);
        enemies.push_back(mob_evo_gorlock);

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
            std::cout<<"    Este primul monstru cu care te intalnesti? Daca da, ai patru posibilitati in momentul de fata. Ce alegi?";
            std::cout<<'\n'<<'\n'<<"................"<<'\n'<<'\n';
            int interact2 = 1;
            int v[3];
            v[0]=v[1]=v[2]=0;
            while(interact2 != 0)
            {
                //int mobIndex = rand() % enemies.size();
                int mobIndex = rand() % 6;
                Mob& currentEnemy = enemies[mobIndex];
                std::cout<<"Ai in fata ta un "<<currentEnemy.getName()<<'\n'<<'\n';
                std::cout << "1.Ataca" << '\n';
                std::cout << "2.Mob Stats" << '\n';
                std::cout << "3.Fugi" << '\n';
                std::cout << "0.Exit Cave" << '\n';
                std::cin >> interact2;
                switch (interact2) {
                    case 1:
                        while (player.isAlive() && currentEnemy.isAlive()) {
                            Attack::performAttack(player, currentEnemy);
                        }
                        v[mobIndex]++;
                        if (player.isAlive()) {
                            std::cout << '\n' << '\n';
                            std::cout << player.getName() << " wins!" << std::endl;
                            std::cout << '\n' << '\n';
                            currentEnemy.reset_mob_hp();
                            if(v[mobIndex] % 4 == 0)
                                currentEnemy.LevelUp_Mob();
                            player.player_earn(currentEnemy.getExp(),currentEnemy.getGold());
                            player.LevelUp_Player();
                            std::cout << "Informatii despre jucator:\n";
                            std::cout << player << '\n' << '\n';
                        }
                        else {
                            std::cout << currentEnemy.getName() << " wins!" << std::endl;
                            std::cout << '\n' << '\n';
                            std::cout << "--------GAME OVER--------";
                            std::cout << '\n' << '\n';
                            interact2 = 0;
                        }

                        break;
                    case 2:
                        std::cout << '\n' << '\n';
                        std::cout << "Informatii despre monstru:\n";
                        std::cout << enemies[mobIndex] << '\n' << '\n';
                        std::cout << "1.Ataca" << '\n';
                        std::cout << "2.Fugi" << '\n';
                        std::cout << "0.Exit Cave" << '\n';
                        std::cin >> interact2;
                        switch (interact2) {
                            case 1:
                                while (player.isAlive() && currentEnemy.isAlive()) {
                                    Attack::performAttack(player, currentEnemy);
                                }
                                v[mobIndex]++;
                                if (player.isAlive()) {
                                    std::cout << '\n' << '\n';
                                    std::cout << player.getName() << " wins!" << std::endl;
                                    std::cout << '\n' << '\n';
                                    currentEnemy.reset_mob_hp();
                                    if(v[mobIndex] % 4 == 0)
                                        currentEnemy.LevelUp_Mob();
                                    player.player_earn(currentEnemy.getExp(),currentEnemy.getGold());
                                    player.LevelUp_Player();
                                    std::cout << "Informatii despre jucator:\n";
                                    std::cout << player << '\n' << '\n';
                                }
                                else {
                                    std::cout << currentEnemy.getName() << " wins!" << std::endl;
                                    std::cout << '\n' << '\n';
                                    std::cout << "--------GAME OVER--------";
                                    std::cout << '\n' << '\n';
                                    interact2 = 0;
                                }
                                break;
                            case 2:
                                break;
                        }
                        break;
                    case 3:
                        break;
                }
            }
        }
        return 0;
    }
