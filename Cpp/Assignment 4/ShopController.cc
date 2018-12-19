#include "ShopController.h"

ShopController::ShopController() {

    initShop();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);
        
        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } else if (choice == 2) {
            string fname, lname, address, phone;
            view.promptUserInfo(fname, lname, address, phone);
            mechanicShop+=(new Customer(fname, lname, address, phone)); //addCustomer()
            view.pause();
        } else if (choice == 3) {
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                string make, model, colour;
                int year, milage;
                view.promptVehicleInfo(make, model, colour, year, milage);
                cust->getVehicles()+=(new Vehicle(make, model, colour, year, milage)); //addVehicle()
            } else {
                view.displayInvalid();
            }
            view.pause();
        } else if (choice == 4) {//Removes Cutomers
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                mechanicShop-= cust; //removeCustomer()
                
            } else {
                view.displayInvalid();
            }
            view.pause();
      
        } else if (choice == 5) {//Removes Vehicles
            int id;
            view.promptUserId(id);
            Customer* cust = mechanicShop.getCustomer(id);
            if (cust != 0) {
                view.promptVehicleNumber(cust->getNumVehicles() - 1);
                int num;
                view.pickNumber(num);
                if(num < 0 || num >= cust->getNumVehicles()){
                    view.displayInvalid();
                }
                else{
                    cust->getVehicles()-= cust->getVehicles()[num]; //removeVehicle()
                }
                
            } 
            else {
                view.displayInvalid();
            }
            view.pause();

        }else if (choice == 6){//prints Mechanics
            view.printTitle();
            for(int i=0; i< mechanicShop.getSize(); i++){
                view.printMechanic(*mechanicShop.getMechanic(i));
                
            }
            view.pause();
        }else {
            break;
        }

    }
}



void ShopController::initShop() { //intCustomers;

    Customer* newCustomer;
    Vehicle* newVehicle;
    Mechanic* newMechanic; //added

    //3 new Mechanics:
    newMechanic = new Mechanic("Bill", "Taylor","54 Park Place","(613)826-9847", 75000);
    mechanicShop+=(newMechanic);

    newMechanic = new Mechanic("Steve", "Bane","77 Oak St.","(613)223-4653", 60000);
    mechanicShop+=(newMechanic);

    newMechanic = new Mechanic("Jane", "Smyth","10 5th Ave.","(613)762-4678", 71000);
    mechanicShop+=(newMechanic);

    newCustomer = new Customer("Maurice", "Mooney", "2600 Colonel By Dr.", 
                                        "(613)728-9568");
    newVehicle = new Vehicle("Ford", "Fiesta", "Red", 2007, 100000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    mechanicShop+=(newCustomer); //addCustomer()

    
    newCustomer = new Customer("Abigail", "Atwood", "43 Carling Dr.", 
                                        "(613)345-6743");
    newVehicle = new Vehicle("Subaru", "Forester", "Green", 2016, 40000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    mechanicShop+=(newCustomer); //addCustomer()


    newCustomer = new Customer("Brook", "Banding", "1 Bayshore Dr.", 
                                        "(613)123-7456");
    newVehicle = new Vehicle("Honda", "Accord", "White", 2018, 5000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    newVehicle = new Vehicle("Volkswagon", "Beetle", "White", 1972, 5000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    mechanicShop+=(newCustomer); //addCustomer()


    newCustomer = new Customer("Ethan", "Esser", "245 Rideau St.", 
                                        "(613)234-9677");
    newVehicle = new Vehicle("Toyota", "Camery", "Black", 2010, 50000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    mechanicShop+=(newCustomer);//addCustomer()
    

    newCustomer = new Customer("Eve", "Engram", "75 Bronson Ave.", 
                                        "(613)456-2345");
    newVehicle = new Vehicle("Toyota", "Corolla", "Green", 2013, 80000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    newVehicle = new Vehicle("Toyota", "Rav4", "Gold", 2015, 20000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    newVehicle = new Vehicle("Toyota", "Prius", "Blue", 2017, 10000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    mechanicShop+=(newCustomer);//addCustomer()

    
    newCustomer = new Customer("Victor", "Vanvalkenburg", "425 O'Connor St.", 
                                        "(613)432-7622");
    newVehicle = new Vehicle("GM", "Envoy", "Purple", 2012, 60000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    newVehicle = new Vehicle("GM", "Escalade", "Black", 2016, 40000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    newVehicle = new Vehicle("GM", "Malibu", "Red", 2015, 20000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    newVehicle = new Vehicle("GM", "Trailblazer", "Orange", 2012, 90000);
    newCustomer->getVehicles()+=(newVehicle); //addVehicle()
    //newVehicle = new Vehicle("GM", "Vue", "Blue", 2015, 20000);
    //newCustomer->getVehicles()+=(newVehicle);
    mechanicShop+=(newCustomer);//addCustomer()

}
