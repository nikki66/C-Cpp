#include "Shop.h"
#include "defs.h"

Shop& Shop::operator+=(Customer* c) { 
    customers += c; 
    return *this;
}

Shop& Shop::operator-=(Customer* c) { 
    customers -= c; 
    return *this;
}

/*Modified the getCustomer​ function in the Shop​ class
that calls this get​ function so the functionality is preserved */
Customer* Shop::getCustomer(int i)  {
    for(int j =0; j< customers.getSize(); j++){
        if(customers[j]->getId() == i){
            return customers[j];
        }
    } //customers.get(i) 
}

LinkedList<Customer>& Shop::getCustomers() { return customers; }

/*Stores pointers to the Mechanic​ objects in the Shop​ class in a LinkedList*/
Shop& Shop::operator+=(Mechanic* m) {    
    mechanics += m; 
    return *this;
}

LinkedList<Mechanic>& Shop::getMechanics()  { return mechanics; }


/*Below are data members or member functions that are no longer needed in the
Shop​ class*/
/*Shop::Shop() : numMechanics(0) { }

Shop::~Shop() {
    for (int i=0; i < numMechanics; i++) 
        delete mechanics[i];
}
void Shop::addCustomer(Customer* c) { customers += c; }
int Shop::getNumMechanics()     { return numMechanics; }*/