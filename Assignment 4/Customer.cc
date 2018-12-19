#include <iostream>
using namespace std;
#include "Customer.h"

//added
#include <sstream>
#include <iomanip>

int Customer::nextId = 1000;

Customer::Customer(string fname, string lname, string add, string pnum) : 
				Person(fname,lname, add, pnum), id(Customer::nextId++) { 

}

int           Customer::getId() const           { return id; }
int           Customer::getNumVehicles() const  { return vehicles.getSize(); }
VehicleList&  Customer::getVehicles()           { return vehicles; }

/* Overload the +=​ operator that takes a Vehicle​ pointer and adds it to the VehicleList​*/
void          Customer::operator+=(Vehicle* v)  {vehicles+=v;} //added

/* Overload the <<​ operator so that it prints the contents of the Customer​ object i*/
ostream& operator<< (ostream& output, Customer& c){ //added
        ostringstream name;
        name << c.getFname() << " " << c.getLname();

        output << "Customer ID " << c.getId() << endl << endl
               << "    Name: " << setw(40) << name.str() << endl 
               << "    Address: " << setw(37) << c.getAddress() << endl
               << "    Phone Number: " << setw(32) <<  c.getPhoneNumber() << endl;
        
        if (c.getNumVehicles() > 0) {
            output << endl << "    " << c.getNumVehicles() 
                      << " vehicle(s): " << endl << endl;
        	output << c.getVehicles() << endl<<endl;
    }
    return output;
}

/* Overload the <​ and >​ operators to compare Customer​ objects based on their last name.
*/
bool Customer::operator<(Customer& c) const{ //added
  return (getLname() < c.getLname());

}

bool Customer::operator>(Customer& c) const{ //added
  return (getLname() > c.getLname());
}
