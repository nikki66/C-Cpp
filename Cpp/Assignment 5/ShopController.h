#ifndef SHOPCONTROLLER_H
#define SHOPCONTROLLER_H

#include "View.h"
#include "Shop.h"
#include "VehicleFactory.h" //added

class ShopController {

    public:
        ShopController();
        void launch();
    private:
        Shop mechanicShop;
        View view;
        void initShop();
        VehicleFactory factory; //included a VehicleFactory​ data member
};

#endif
