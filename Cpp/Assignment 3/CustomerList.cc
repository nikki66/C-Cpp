#include <iostream>
using namespace std;
#include <string>

#include <sstream> //added
#include <iomanip> //added

#include <sstream> //added

#include "CustomerList.h"

/*Constructor*/
CustomerList::CustomerList() : head(0){} //size shouldn't be stored

/*Destructor*/
CustomerList::~CustomerList(){

	Node *currNode, *nextNode;

	currNode = head;

	while (currNode !=0 ){
		nextNode = currNode->next;
		delete currNode->c;
		delete currNode;
		currNode = nextNode;
	}
}
/*an add function that takes a Customer pointer and adds the object in its
correct place in the CustomerList class*/
void CustomerList::add(Customer* newCustomer){ //change int to void
	
	Node *currNode, *prevNode;
	Node* newNode = new Node;
	newNode->c = newCustomer;
	newNode->next = 0;

	currNode = head;
	prevNode = 0;

	while (currNode != 0) {
	if (newNode->c->getLname() < currNode->c->getLname())
	  break;
	prevNode = currNode;
	currNode = currNode->next;
	}

	if (prevNode == 0) {
	head = newNode;
	}
	else {
	prevNode->next = newNode;
	}

	newNode->next = currNode;


	getSize(); //increments size


}

/*a getSize function that returns the size of the list.*/
int CustomerList::getSize() const{ 
	if(head!=NULL){

		int s = 1;

		for(Node* n = head; n->next != 0; n = n->next){
			s++;
		}

		return s; 
	}
	return 0;
} 

/*takes an integer parameter (id) and returns a
pointer to the Customer object in the list with that id. If no such object exists, return null*/
Customer* CustomerList::get(int id) const { 

	Node* currNode;
	currNode = head;

	for(int i = 0; i<getSize(); i++){
		if(currNode->c->getId() == id){
			return currNode->c;
		}
		else{
			currNode = currNode->next;
		}
	}

	return NULL;
	
}

/*OutStr parameter is the result of the function concatenating all the object’s data formatted into
one long string. This long string will contain all data found by traversing the linked list. The UI class will
invoke the formatting function on the List objects, and then output the resulting formatted string to the
screen.*/
void CustomerList::toString(string& outStr) const{

	stringstream ss;
	string emptystr = "";

	Node* currNode;

	ss << endl << "CUSTOMERS: " << endl << endl;

    for (Node* currNode=head; currNode!=0; currNode = currNode->next) {
        
        ostringstream name;
        name << currNode->c->getFname() << " " << currNode->c->getLname();

        ss << "Customer ID " << currNode->c->getId() << endl << endl
            << "    Name: " << setw(40) << name.str() << endl 
            << "    Address: " << setw(37) << currNode->c->getAddress() << endl
            << "    Phone Number: " << setw(32) <<  currNode->c->getPhoneNumber() << endl;
             
        if (currNode->c->getNumVehicles() > 0) {
            ss << endl << "    " << currNode->c->getNumVehicles() 
                << " vehicle(s): " << endl << endl;
            currNode->c->getVehicles().toString(emptystr);
            ss << emptystr << endl;

        }

    }
    outStr = ss.str();
    ss << endl << endl; 


}