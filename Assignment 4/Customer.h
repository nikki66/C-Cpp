#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Vehicle.h"
#include "VehicleList.h"

using namespace std;
#include "Person.h" //inheritance


class Customer : public Person{

    public:
    
        Customer(string="", string="", string="", string="");
        friend ostream& operator<< (ostream&, Customer&); //added
    
        int getId() const;
        int getNumVehicles() const;
        VehicleList& getVehicles();

        void operator+=(Vehicle*); //added
        bool operator<(Customer&) const; //added
        bool operator>(Customer&) const; //added
        
    private:

        static int nextId;
        
        const int id;
        VehicleList vehicles;
};

#endif
