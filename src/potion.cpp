//#include "potion.h"
//#include "player.h"
//
//template <typename N, typename P>
//
//Potion<N, P>::Potion(N name, P hp, P price, P quantity, P initQuantity)
//    : Item<N, P>(std::move(name), hp, price, quantity, initQuantity), hp(hp) {}
//
//template <typename N, typename P>
//    void Potion<N, P>::use(Player& player)
//    {
//        int hpToAdd = getHp();
//        std::cout << "Valoare hpToAdd: " << hpToAdd << std::endl;
//        std::cout << "HP-ul jucătorului înainte de utilizare: " << player.getHp() << std::endl;
//        player.addHp(hpToAdd);
//        std::cout << "HP-ul jucătorului după utilizare: " << player.getHp() << std::endl;
//        std::cout << "Ai folosit potiunea " << getName() << ". Aceasta iti adauga " << hpToAdd << " hp." << std::endl;
//    }
//
//template <typename N, typename P>
//P Potion<N, P>::getHp(){
//    return hp;
//}
//
//template <typename N, typename P>
//N Potion<N, P>::getName(){
//    return name;
//}