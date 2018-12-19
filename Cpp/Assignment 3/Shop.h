#ifndef SHOP_H
#define SHOP_H

#include "Customer.h"
#include "CustomerList.h" 

class Shop{

    public:
        void addCustomer(Customer*); //changed int to void
        Customer* getCustomer(int) const;
        CustomerList& getCustomers();
        Customer* newCustomer(string, string, string, string); 
         


    private:
        CustomerList customers; 

};

#endif
