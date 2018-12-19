#include <iostream>
using namespace std;
#include "Customer.h"

//added

/*The static member nextId is used to give all of the Customer objects unique IDs. Initialize
it to 1000.*/
int Customer::nextId = 1000; //static member should be inizialized at the beginning

/*The constructor sets the id member to the current value of the static member nextId ,
increments nextId and then simply sets all of other data members to the parameters
passed in.*/
Customer:: Customer(string f_name, string l_name, string aAddress, string phoneNum){
	firstName = f_name;
    lastName = l_name;
    address = aAddress;
    phoneNumber = phoneNum;

    id = nextId++;
}

/*Getters*/

int      Customer::getId()     { return id; }
string   Customer::getFname()  { return firstName; }
string   Customer::getLname() { return lastName; }
string   Customer::getAddress() { return address; }
string   Customer::getPhoneNumber() { return phoneNumber; }

int 	      Customer::getNumVehicles(){return vehicles.getSize();}
VehicleArray& Customer::getVehicles(){return vehicles;}

/*The addVehicle function simply called the add function in the VehicleArray class. 
It returns what this add function returns.*/
int Customer::addVehicle(Vehicle* v){ 
	return vehicles.add(v); // call from VehicleArray class
}






