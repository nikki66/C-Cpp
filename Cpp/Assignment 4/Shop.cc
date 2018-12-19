#include "Shop.h"
#include "defs.h"

/*The constructor simply initializes the size data member properly*/
Shop::Shop(){
	size = 0;
}

/*The destructor must iterate over the stored objects (which are to be dynamically
allocated), freeing the allocated memory for each one.*/
Shop::~Shop(){
	for(int i=0; i<size; i++){
		delete elements[i];
	}
}

/*Getter to keep track of Size*/
int Shop::getSize() const { return size; }

/*Overload the +=​ operator that takes a Customer​ pointer and adds it to the
CustomerList​ stored in the Shop​.*/
void Shop::operator+=(Customer* c) { customers+=c; } //.add(c)

/*● Overload the -= ​so that it takes a Customer​ pointer and removes it from the
CustomerList​ stored in the Shop​.*/
void Shop::operator-=(Customer* c) { customers-=c; } // remove(c)

Customer* Shop::getCustomer(int i) { return customers.get(i); } 

CustomerList& Shop::getCustomers() { return customers; }

Mechanic* Shop::getMechanic(int i){return elements[i];} //added

/*Overload the +=​ operator in the Shop
class to take a pointer to a Mechanic​ object and add it to this array, if there is room.*/
void Shop::operator+=(Mechanic* m){ //added
	if(size < MAX_MECHANICS){
		elements[size] = m;
		size++;
	}
}
