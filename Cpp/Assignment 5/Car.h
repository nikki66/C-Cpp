#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "Vehicle.h"

using namespace std;

class Car : public Vehicle{ //inherits Vehicle
    public:
        Car(string="", string="", string="", int=0, int=0);
        void toString(ostream&) const;
};


#endif
