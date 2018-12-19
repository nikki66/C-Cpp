#include "Vehicle.h"
//added
#include <sstream>
#include <iomanip>

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

/*Overload the <​ and >​ operators to compare Vehicle​ objects based on their year.
*/
bool Vehicle::operator<(Vehicle& v) const{ //added
  return (getYear() < v.getYear());

}

bool Vehicle::operator>(Vehicle& v) const{ //added
  return (getYear() > v.getYear());
}
/*Overload the <<​ operator so that it prints the contents of the Vehicle​ object*/
ostream& operator<< (ostream& output, Vehicle& v){ //added
    	
      ostringstream make_model;
      make_model << v.getMake() << " " << v.getModel();

      output << "\t" << setw(7) << v.getColour() << " " 
                   << v.getYear() << " " << setw(17) << make_model.str() << " (" 
                   << v.getMilage() << "km)";


    return output;
}


