#include <iostream>
using namespace std;
#include "Car.h"

/*Constructor*/
Car::Car(string make, string model, string colour, int year, int mileage) : 
        Vehicle(make,model,colour,year,mileage){ }

/*Car objects can easily be printed to screen*/
void Car::toString(ostream& output) const{

	ostringstream make_model;
    make_model << make << " " << model;

    output << "\t" << "CAR: " << setw(14) << colour << " " << year << " " << setw(17);
    output << make_model.str() << " (" << mileage << "km)" << endl;
}
