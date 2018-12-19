#include <iostream>
using namespace std;
#include "Motorcycle.h"

/*constructor*/
Motorcycle::Motorcycle(string make, string model, string colour, int year, int mileage, bool aSide) : 
        Vehicle(make,model,colour,year,mileage), hasSide(aSide){ }

/*getter*/
bool           Motorcycle::getHasSide() const           { return hasSide; }

/*Motorcycle objects can easily be printed to screen.*/
void Motorcycle::toString(ostream& output) const{
	ostringstream make_model;
    make_model << make << " " << model;

    output << "\t" << "MOTORCYCLE: " << setw(7) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km), ";
    if(hasSide){//true
    	output<< "has sidecar" <<endl;
    }
    else{
    	output<< "doesn't have sidecar" << endl;
    }

}