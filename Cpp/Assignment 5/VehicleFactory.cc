#include <sstream>
#include <iomanip>
#include <iostream>
#include "VehicleFactory.h"

using namespace std;

VehicleFactory::VehicleFactory() {}

VehicleFactory::~VehicleFactory() {}

/*create function for car*/
Vehicle* VehicleFactory::create(string make, string model, string colour, int year, int mileage){
  
  ostringstream ss;
  Car* newCar = new Car(make, model, colour, year, mileage);
  newCar->toString(ss);

  return newCar;
}

/*create function for truck*/
Vehicle* VehicleFactory::create(string make, string model, string colour, int year, int mileage,
  int numAx){

  ostringstream ss;
  Truck* newTruck = new Truck(make, model, colour, year, mileage, numAx);
  newTruck->toString(ss);

  return newTruck;
}

/*create function for motorcycle*/
Vehicle* VehicleFactory::create(string make, string model, string colour, int year, int mileage,
  bool hasSide){

  ostringstream ss;
  Motorcycle* newMotor = new Motorcycle(make, model, colour, year, mileage, hasSide);
  newMotor->toString(ss);
  
  return newMotor;
}
