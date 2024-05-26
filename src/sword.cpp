//#include "sword.h"
//#include "player.h"
//
//template <typename N, typename P>
//
//Sword<N, P>::Sword(N name, P atk, P price, P quantity, P initQuantity)
//    : Item<N, P>(std::move(name), atk, price, quantity, initQuantity), atk(atk) {}
//
//    template <typename N, typename P>
//void Sword<N, P>::use(Player& player) {
//    int atkToAdd = getAtk();
//    std::cout << "Ai echipat sabia " << getName() << ".\n";
//    player.addAtk(atkToAdd);
//}
//
//template <typename N, typename P>
//P Sword<N, P>::getAtk() {
//    return atk;
//}
//
//template <typename N, typename P>
//N Sword<N, P>::getName() {
//    return name;
//}