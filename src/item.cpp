//#include "item.h"
//
//template <typename N, typename P>
//
//Item<N, P>::Item(N name, P prop, P price, P quantity, P initQuantity)
//        : name(std::move(name)), price(price), quantity(quantity), prop(prop), initQuantity(initQuantity) {}
//
//template <typename N, typename P>
//    N& Item<N, P>::getName() { return name; }
//template <typename N, typename P>
//    P Item<N, P>::getPrice() { return price; }
//template <typename N, typename P>
//    P Item<N, P>::getQuantity() { return quantity; }
//template <typename N, typename P>
//    P Item<N, P>::getinitQuantity() { return initQuantity; }
//template <typename N, typename P>
//    P Item<N, P>::getProp() { return prop; }
//template <typename N, typename P>
//    void Item<N, P>::setQuantity(int nQ) { quantity = nQ; }
//template <typename N, typename P>
//    void Item<N, P>::resetQuantity()
//    {
//        quantity = initQuantity;
//    }