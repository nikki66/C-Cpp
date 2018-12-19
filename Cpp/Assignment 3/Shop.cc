#include "Shop.h"
#include "defs.h"

void Shop::addCustomer(Customer* c) { return customers.add(c); } //changed int to void

Customer* Shop::getCustomer(int i) const { return (customers.get(i)); } 

CustomerList& Shop::getCustomers() { return customers; } 

/*creates a new customer with the info received from user*/
Customer* Shop::newCustomer(string fn, string ln, string add, string num){
	Customer* newCust = new Customer(fn,ln,add,num);
	return newCust;
}

