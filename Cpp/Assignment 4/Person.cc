#include <iostream>
using namespace std;
#include "Person.h"

/*Constructor*/
Person::Person(string fname, string lname, string add, string pnum) : 
		firstName(fname), lastName (lname), address(add), phoneNumber(pnum){ 

}

/*Getters*/
string        Person::getFname() const        { return firstName; }
string        Person::getLname() const        { return lastName; }
string        Person::getAddress() const      { return address; }
string        Person::getPhoneNumber() const  { return phoneNumber; }