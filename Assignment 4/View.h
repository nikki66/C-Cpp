#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h"
#include "Mechanic.h" //added

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);

        friend ostream& operator<< (ostream&, VehicleList&); //added
        void pickNumber(int&); //added
        void printMechanic(Mechanic&); //added
        void printTitle(); //added
        void promptVehicleNumber(int); //added

    private:
        int readInt() const;
};

#endif
