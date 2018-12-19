#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Vehicle.h"

using namespace std;

class Motorcycle : public Vehicle{//inherits Vehicle
    public:
        Motorcycle(string="", string="", string="", int=0, int=0, bool = false);
        void toString(ostream&) const;
        bool getHasSide() const;

    private:
    	bool hasSide;
};

#endif

