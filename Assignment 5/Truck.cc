#include <iostream>
using namespace std;
#include "Truck.h"

/*Constructor*/
Truck::Truck(string make, string model, string colour, int year, int mileage, int numAx) : 
        Vehicle(make,model,colour,year,mileage), numAxies(numAx){ }

/*getter*/
int           Truck::getNumAxies() const           { return numAxies; }

/*Truck objects can easily be printed to screen.*/
void Truck::toString(ostream& output) const{

	ostringstream make_model;
    make_model << make << " " << model;

    output << "\t" << "TRUCK: " << setw(12) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km), " << numAxies << " axies" <<endl;

}