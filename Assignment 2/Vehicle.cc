#include "Vehicle.h"

//added

/*Constructor for Vehicle*/
Vehicle:: Vehicle(string aMake, string aModel, string aColour, int aYear, int aMileage){
    make = aMake;
    model = aModel;
    colour = aColour;
    year = aYear;
    mileage = aMileage;
}

/*Getters*/

string   Vehicle::getMake()     { return make; }
string   Vehicle::getModel()  { return model; }
string   Vehicle::getColour() { return colour; }
int      Vehicle::getYear() { return year; }
int      Vehicle::getMilage() { return mileage; }
