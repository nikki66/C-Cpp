/*Name: Nicole El-Sayegh
  Student ID: 100960005
  Comp 2404B - Assignment 1
  Program: A small program which could be used by an automotive mechanic
           business to keep track of their customers and their vehicles. */


#include <stdio.h>
#include <string.h>

#define MAX_STR 32
#define MAX_VEHICLES 4
#define MAX_CUSTOMERS 6

typedef struct { //this structure contains all of the data for each car owned by the customers.

	char make[MAX_STR]; //string called "make" (Vehicles's make)
	char model[MAX_STR]; //string called "model" (Vehicles's model)
	char colour[MAX_STR];//string called "colour" (Vehicles's colour)
	int year; //int called "year" (Vehicles's year)
	int mileage; //int called "mileage" (Vehicles's mileage in KM)


} VehicleType;

typedef struct {//this structure contains all of the data regarding the individual customers.

	char first_name[MAX_STR];//string called "first_name" (Customer's first name)
	char last_name[MAX_STR];//string called "last_name" (Customer's last name)
	int vehicles_regist;//number of vehicles registered with the shop
	VehicleType owned[MAX_VEHICLES]; //a VehicleType array storing the individual vehicles owned by the customer (declared to have a length of MAX_VEHICLES

} CustomerType;

/* This function takes a pointer to a vehicle structure as a parameter and prints out all of the
information from the specific vehicle on a single line in a human readable manner.*/
void print_vehicle(VehicleType *v) {
	printf("%d %s %s, %s, %dKM\n", (*v).year, (*v).make, (*v).model, (*v).colour, (*v).mileage);

}

/*This function takes a pointer to a customer structure as a parameter and prints out all of
the information from the specific customer.*/
void print_customer(CustomerType *c) {
	printf("%s %s, %d vehicle(s)\n", (*c).first_name,(*c).last_name, (*c).vehicles_regist); //prints out customer (*c)'s full name & number of registered vehicles
	
	for (int i=0; i<(*c).vehicles_regist; i++){ //this for loop, loops over the registered vehicles of customer & prints them out
		print_vehicle(&(*c).owned[i]);	
	}
}

/* This function takes a pointer to a customer structure and a pointer to a vehicle structure. Vehicle will be added depending
on the number of vehicles the customer already added*/
int add_vehicle(CustomerType *customer, VehicleType *vehicle) {
	if((*customer).vehicles_regist >= MAX_VEHICLES){ //checks if the number of registered vehicles isn't less than the maximum allowed = no room
        return -1; //the function will return -1
    }

    else{ //the number of registered vehicles is less than the maximum allowed

    	(*customer).owned[(*customer).vehicles_regist] = *vehicle; //will add the vehicle to the array
    	(*customer).vehicles_regist++; //increment the vehicle counter

    	return 0; // function returns 0 
    }
}

/*This function takes a first name and last name (strings) as parameters and is used to
initialize an instance of the customer structure. */
CustomerType create_customer(char* fname, char* lname) {
	CustomerType c; //instance of customer structure
    strcpy(c.first_name, fname); //set the new instance first name
    strcpy(c.last_name, lname); //set the new instance last name

    c.vehicles_regist = 0;//set the number of registered vehicles to 0

    return c;//return the new instance
}


/*This function takes all of the required data to create an instance of the vehicle structure.*/
VehicleType create_vehicle(char* make, char* model, char* colour,
                            int year, int mileage) {
	VehicleType v; //instance of vehicle structure
    strcpy(v.make, make);//initialzie vehicle's make
    strcpy(v.model, model);//initialzie vehicle's model
    strcpy(v.colour, colour);//initialzie vehicle's colour
    v.year = year;//initialzie vehicle's year
    v.mileage = mileage;//initialzie vehicle's mileage

    return v; //return the newly created instance.

}


int main() {

    CustomerType customers[MAX_CUSTOMERS];

    CustomerType Maurice, Abigail, Brook, Ethan, Eve, Victor;//6 customers 

//6 different customers created which includes first and last names for each
    Maurice = create_customer("Maurice","Mooney");
    Abigail = create_customer("Abigail", "Atwood");
    Brook = create_customer("Brook ", "Banding");
    Ethan = create_customer("Ethan", "Esser");
    Eve = create_customer("Eve", "Engram");
    Victor = create_customer("Victor", "Vanvalkenburg");


    VehicleType v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12;//12 vehicles 

//12 different vehicles created which includes make, model, colour, year and mileage for each
    v1 = create_vehicle("Ford", "Fiesta", "Red", 2007, 100000);
    v2 = create_vehicle("Subaru","Forester", "Green", 2016, 40000);
    v3 = create_vehicle("Honda", "Accord", "White", 2018, 5000);
    v4 = create_vehicle("Volkswagen", "Beetle", "White", 1972, 5000);
    v5 = create_vehicle("Toyota", "Camry", "Black", 2010, 50000);
    v6 = create_vehicle("Toyota", "Corolla", "Green", 2013, 80000);
    v7 = create_vehicle("Toyota", "Rav4", "Gold", 2015, 20000);
    v8 = create_vehicle("Toyota", "Prius", "Blue", 2017, 10000);
    v9 = create_vehicle("GM", "Envoy", "Purple",2012, 60000);
    v10 = create_vehicle("GM", "Escalade", "Black", 2016, 40000);
    v11 = create_vehicle("GM", "Malibu", "Red", 2015, 20000);
    v12 = create_vehicle("GM", "Trailblazer", "Orange", 2012, 90000);

//use the add_vehicle ​function to add vehicle structures to the respective customer
    add_vehicle(&Maurice, &v1);
    add_vehicle(&Abigail, &v2);
    add_vehicle(&Brook, &v3);
    add_vehicle(&Brook, &v4);
    add_vehicle(&Ethan, &v5);
    add_vehicle(&Eve, &v6);
    add_vehicle(&Eve, &v7);
    add_vehicle(&Eve, &v8);
    add_vehicle(&Victor, &v9);
    add_vehicle(&Victor, &v10);
    add_vehicle(&Victor, &v11);
    add_vehicle(&Victor, &v12);

    add_vehicle(&Victor, &v8); /*check if add_vehicle function works since Victor already has 4 (MAX_VEHICLES) registered. 
    It will simply see that the vehicles array is full, do nothing and return -1. */

//all customers with their customer/vehicle info are added to the customers array
    customers[0] = Maurice;
    customers[1] = Abigail;
    customers[2] = Brook;
    customers[3] = Ethan;
    customers[4] = Eve;
    customers[5] = Victor;

/* this for loop, loops over all of the CustomerType structures in the customers array and uses the
print_customer​ function (which itself uses the print_vehicle ​function) to display all of the
customer data to the screen. */
    for(int i = 0; i < MAX_CUSTOMERS; i++) { 
        print_customer(&customers[i]);
        printf("\n");
    }

    return 0;
}



