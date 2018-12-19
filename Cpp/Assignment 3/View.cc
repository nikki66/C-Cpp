#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

#include "View.h"
#include "CustomerList.h"
#include "Customer.h"
#include "VehicleList.h"
#include "Vehicle.h"


void View::mainMenu(int& choice) {
    string str;

    choice = -1;

    cout<< "\n\n\n         **** Toby's Auto Mechanic Information Management System ****\n\n";
    cout<< "                                 MAIN MENU\n\n";
    cout<< "        1. Print Customer Database\n\n";
    cout<< "        2. Add Customer\n\n"; //added
    cout<< "        3. Add Vehicle\n\n"; //added
    cout<< "        0. Exit\n\n";

    while (choice < 0 || choice > 3) { //modified
        cout << "Enter your selection:  ";
        choice = readInt();
    }

    if (choice == 0) { cout << endl; }
}


void View::printCustomers(CustomerList& arr) const { 
    string str = "";
    arr.toString(str);
    
    cout << str << endl; 
 
}

void View::pause() const{
    string str;

    cout << "Press enter to continue...";
    getline(cin, str);
}

int View::readInt() {
    string str;
    int    num;

    getline(cin, str);
    stringstream ss(str);
    ss >> num;

    return num;
}

//added
/*the program will prompt the use for all of the relevant information, create a customer
object and add it to the Customer list. Following 4 functions are to get input for customer required info.*/

void View::getFirstName(string& fs) const{
    string  str; 
    cout << endl << "ADD CUSTOMER: " << endl << endl;
    cout << endl<< "    First Name: ";
    getline(cin, str);
    stringstream ss(str);
    ss>>fs;
}
void View::getLastName(string& ls) const{
    string str;
    cout << endl<< "    Last Name: ";
    getline(cin, str);
    stringstream ss(str);
    ss>>ls;
}
void View::getAddress(string& address) const {
    string str;
    cout << endl<< "    Address: ";
    getline(cin, str);
    stringstream ss(str);
    ss>>address;

    address = ss.str();

}
void View::getPhoneNumber(string& phone) const {
    string str;
    cout << endl<< "    Phone Number: ";
    getline(cin, str); 
    stringstream ss(str);
    ss>>phone;

    phone = ss.str();
}

//added
/*program will prompt the user for a customer id. */
void View:: requestId(int& id) const{
    string str;
    cout << "Customer ID: ";
    getline(cin, str);
    stringstream ss(str);
    ss>>id;
}

//added
/*If ID is invalid, tell the user */
void View:: printError() const{
    cout<< "Invalid choice.\n";
}

//added
/*If ID valid, prompt the user for all of the relevant information, create a vehicle object and add it
to the customer’s vehicle list. Following 5 functions are to get input for vehicle required info.*/

void View::getMake(string& mk) const{
    string  str; 
    cout << endl << "ADD VEHICLE: " << endl << endl;
    cout << endl<< "    Make: ";
    getline(cin, str);
    stringstream ss(str);
    ss>>mk;
}
void View::getModel(string& ml) const{
    string str;
    cout << endl<< "    Model: ";
    getline(cin, str); 
    stringstream ss(str);
    ss>>ml;
}
void View::getColour(string& col) const{
    string str;
    cout << endl<< "    Colour: ";
    getline(cin, str); 
    stringstream ss(str);
    ss>>col;
}
void View::getYear(int& yr) const{
    string str;
    cout << endl<< "    Year: ";
    getline(cin, str); 
    stringstream ss(str);
    ss>>yr;
}
void View::getMileage(int& mil) const{
    string str;
    cout << endl<< "    Mileage: ";
    getline(cin, str); 
    stringstream ss(str);
    ss>>mil;
}


