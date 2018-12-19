#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "CustomerList.h"

#include "Mechanic.h" //added

class Shop{

    public:
        Shop();
        ~Shop();
        int getSize() const; //added

        Customer* getCustomer(int);
        CustomerList& getCustomers();

        void operator+=(Customer*); //added
        void operator-=(Customer*); //added
        void operator+=(Mechanic*);//added

        
        Mechanic* getMechanic(int); //added

    private:
        CustomerList customers;
        Mechanic* elements[5]; //added
        int size;

};

#endif
