#include <iostream>
using namespace std;
#include "Mechanic.h"

//added
#include <sstream>
#include <iomanip>

int Mechanic::nextId = 5000; //static int

/*Constructor*/
Mechanic::Mechanic(string fname, string lname, string add, string pnum, int s) : 
				Person(fname,lname, add, pnum), id(Mechanic::nextId++){ 

	salary = s;
}

/*Getters*/
int           Mechanic::getId() const           { return id; }
int           Mechanic::getSalary() const       { return salary; }

/*Overloaded <<​ operator which prints a Mechanic ​object*/
ostream& operator<< (ostream& output, Mechanic& m){ //added
        ostringstream name;
        name << m.getFname() << " " << m.getLname();

        output << "Customer ID " << m.getId() << endl << endl
               << "    Name: " << setw(40) << name.str() << endl 
               << "    Address: " << setw(37) << m.getAddress() << endl
               << "    Phone Number: " << setw(32) <<  m.getPhoneNumber() <<endl
               << "    Salary: "<< setw(38) <<  m.getSalary() << endl;
    
    return output;
}