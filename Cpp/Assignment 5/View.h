#ifndef VIEW_H
#define VIEW_H

#include "LinkedList.h" //added
#include "Mechanic.h"
#include "Customer.h" //added

class View {

    public:
        void mainMenu(int&);
        void printCustomers(LinkedList<Customer>&) const;
        void pause() const;
        void promptUserInfo(string&, string&, string&, string&);
        void promptUserId(int&);
        void displayInvalid();
        void promptVehicleInfo(string&, string&, string&, int&, int&);
        void promptVehicle(int, int&);
        void printMechanics(LinkedList<Mechanic>&, int) const;

        void vehicleType(int&); //added
        void promptVehicleInfo(string&, string&, string&, int&, int&, int&);//added
        void promptVehicleInfo(string&, string&, string&, int&, int&, bool&);//added

    private:
        int readInt() const;
        bool readBool() const; //added
};

#endif
