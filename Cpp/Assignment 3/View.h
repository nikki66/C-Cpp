#ifndef VIEW_H
#define VIEW_H

#include "CustomerList.h" 

class View {

    public:
        void mainMenu(int&);
        void printCustomers(CustomerList&) const; 
        void pause() const;

        void requestId(int&) const;
        void printError() const;

        /*print/receive details for customer*/
        void getFirstName(string&)const;
        void getLastName(string&)const;
        void getAddress(string&)const;
        void getPhoneNumber(string&)const;

		/*print/receive details for vehicle*/
        void getMake(string&)const;
        void getModel(string&)const;
        void getColour(string&)const;
        void getYear(int&)const;
        void getMileage(int&)const;


    private:
        int readInt();
};

#endif
