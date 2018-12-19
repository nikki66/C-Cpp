#include <iostream>
using namespace std;
#include <string>

#include <sstream> //added
#include <iomanip> //added

#include <sstream> //added

#include "VehicleList.h"

/*Constructor*/
VehicleList::VehicleList() : head(0){}

/*Destructor*/
VehicleList::~VehicleList(){

	Node *currNode, *nextNode;

	currNode = head;

	while (currNode !=0 ){
		nextNode = currNode->next;
		delete currNode->v;
		delete currNode;
		currNode = nextNode;
	}
}

/*an add function that takes a Vehicle pointer and adds the object in its
correct place in the VehicleList class*/
void VehicleList::add(Vehicle* newVehicle){ //change int to void

	Node *currNode, *prevNode;
	Node* newNode = new Node;
	newNode->v = newVehicle;
	newNode->next = 0;

	currNode = head;
	prevNode = 0;

	while (currNode != 0) {
	if (newNode->v->getYear() > currNode->v->getYear())
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
int VehicleList::getSize() const{

	if(head!=NULL){

		int s = 1;

		for(Node* n = head; n->next != 0; n = n->next){
			s++;
		}

		return s; 
	}
	return 0;
} 

/*OutStr parameter is the result of the function concatenating all the object’s data formatted into
one long string. This long string will contain all data found by traversing the linked list. The UI class will
invoke the formatting function on the List objects, and then output the resulting formatted string to the
screen.*/
void VehicleList::toString(string& outStr) const{

	Node* currNode;
	stringstream ss;
	
    
    for (Node* currNode=head; currNode!=0; currNode = currNode->next) {

        ostringstream make_model;
        make_model << currNode->v->getMake() << " " << currNode->v->getModel();

    	ss << setw(13) << currNode->v->getColour() << " " 
           << currNode->v->getYear() << " " << setw(17) << make_model.str() << " (" 
           << currNode->v->getMilage() << "km)" << endl;
    }


    ss << endl << endl; 

    outStr = ss.str();  

}