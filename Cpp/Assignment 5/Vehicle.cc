#include "Vehicle.h"
#include <sstream>

Vehicle::Vehicle(string ma, string mo, string col, int y, int m) { 
    make = ma;
    model = mo;
    colour = col;
    year = y;
    mileage = m;
}

string  Vehicle::getMake() const     { return make; }
string  Vehicle::getModel() const    { return model; }
string  Vehicle::getColour() const   { return colour; }
int     Vehicle::getYear() const     { return year; }
int     Vehicle::getMilage() const   { return mileage; }

/*updated overloaded output stream insertion operator to call to call the toString​ function as
opposed to accessing the member variables directly*/
ostream& operator<<(ostream& output, Vehicle& v)
{
    v.toString(output);
    return output;
}
/*Pure virtual called toString​ that will return a string*/
void Vehicle::toString(ostream& output) const{
    output << "";
}

bool Vehicle::operator<(Vehicle& v)
{
    return year < v.year;
}

bool Vehicle::operator>(Vehicle& v)
{
    return year > v.year;
}
