#ifndef TRUCK_H
#define TRUCK_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Vehicle.h"

using namespace std;

class Truck : public Vehicle{ //inherits Vehicle
    public:
        Truck(string="", string="", string="", int=0, int=0, int =0);
        void toString(ostream&) const;
        int getNumAxies() const;

    private:
    	int numAxies;
};

#endif