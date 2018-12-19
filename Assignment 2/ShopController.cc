#include "ShopController.h"

ShopController::ShopController() {

    initCustomers();

}

void ShopController::launch() {

    int choice;

    while (1) {
        choice = -1;
        view.mainMenu(choice);
        
        if (choice == 1) {
            view.printCustomers(mechanicShop.getCustomers());
            view.pause();
        } /*else if (choice == 2) {

        } else if (choice == 3) {

        } else if (choice == 4) {
      
        } ... */
        
        else {
            break;
        }
    }
}

/*The ShopController class contains a function called initCustomers which we will use to populate
the program with data. This function will create dynamically allocated objects. It will work as
follows. First it will create a Customer object followed by several Vehicle objects. Adds the
Vehicle objects to the Customer using the Customer’s addVehicle member function. Once a
Customer object has had all of its Vehicles added, Adds the Customer to the Shop
object using its addCustomer member function. This is done until the data fill requirements
have been met.*/

void ShopController::initCustomers() {

    //add data fill here
    Customer* newCustomer;
    Vehicle* newVehicle;


    //6 Customers including all details (added to CustomerArray)
    newCustomer = new Customer("Maurice", "Maurice", "2600 Colonel By Dr.","(613)728-9568");
    mechanicShop.addCustomer(newCustomer);

    newCustomer = new Customer("Abigail", "Abigail", "43 Carling Dr.","(613)345-6743"); 
    mechanicShop.addCustomer(newCustomer);

    newCustomer = new Customer("Brook", "Brook", "1 Bayshore Dr.","(613)123-7456");
    mechanicShop.addCustomer(newCustomer);

    newCustomer = new Customer("Ethan", "Ethan", "245 Rideau St.","(613)234-9677");
    mechanicShop.addCustomer(newCustomer);

    newCustomer = new Customer("Eve", "Eve", "75 Bronson Ave.","(613)456-2345");
    mechanicShop.addCustomer(newCustomer);

    newCustomer = new Customer("Victor", "Victor", "425 O'Connor St.","(613)432-7622");
    mechanicShop.addCustomer(newCustomer);


    //Vehicles including all details added to the assigned customer using indices
    newVehicle = new Vehicle("Ford","Fiesta","Red", 2007, 100000);
    mechanicShop.getCustomer(0).addVehicle(newVehicle); //for customer 1

    newVehicle = new Vehicle("Subaru","Forester","Green", 2016, 40000);
    mechanicShop.getCustomer(1).addVehicle(newVehicle); //for customer 2

    newVehicle = new Vehicle("Honda","Accord","White", 2018, 5000);
    mechanicShop.getCustomer(2).addVehicle(newVehicle); //for customer 3
    newVehicle = new Vehicle("Volkswagon","Beetle","White", 1972, 5000);
    mechanicShop.getCustomer(2).addVehicle(newVehicle); //for customer 3

    newVehicle = new Vehicle("Toyota","Camery" ,"Black", 2010, 50000);
    mechanicShop.getCustomer(3).addVehicle(newVehicle); //for customer 4

    newVehicle = new Vehicle("Toyota","Corolla","Green", 2013, 80000);
    mechanicShop.getCustomer(4).addVehicle(newVehicle); //for customer 5
    newVehicle = new Vehicle("Toyota","Rav4","Gold", 2015, 20000);
    mechanicShop.getCustomer(4).addVehicle(newVehicle); //for customer 5
    newVehicle = new Vehicle("Toyota","Prius","Blue", 2017, 10000);
    mechanicShop.getCustomer(4).addVehicle(newVehicle); //for customer 5

    newVehicle = new Vehicle("GM","Envoy" ,"Purple", 2012, 60000);
    mechanicShop.getCustomer(5).addVehicle(newVehicle); //for customer 6
    newVehicle = new Vehicle("GM","Escalade" ,"Black", 2016, 40000);
    mechanicShop.getCustomer(5).addVehicle(newVehicle); //for customer 6
    newVehicle = new Vehicle("GM","Malibu" ,"Red", 2015, 20000);
    mechanicShop.getCustomer(5).addVehicle(newVehicle); //for customer 6
    newVehicle = new Vehicle("GM","Trailblazer" ,"Orange", 2012, 90000);
    mechanicShop.getCustomer(5).addVehicle(newVehicle); //for customer 6

}
