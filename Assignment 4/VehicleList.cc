#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include <string>

#include "VehicleList.h"

#include <cstdlib> //added

VehicleList::VehicleList() : head(0) { }


VehicleList::~VehicleList()
{
  Node *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}


int VehicleList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

/*Overload the +=​ operator that takes a Vehicle​ pointer and adds it to the VehicleList​.
*/
void VehicleList::operator+= (Vehicle* newVeh){//added
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newVeh;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) > *(currNode->data)) //modified-getYear()
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

}
/*Overload the -= ​so that it takes a Vehicle​ pointer and removes it from the VehicleList*/
void VehicleList::operator-=(Vehicle* oldVeh){//added
  Node *currNode, *prevNode;

  prevNode = 0;
  currNode = head;

  while (currNode != 0) {
    if (currNode->data == oldVeh)//check
        break;
    
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
    return;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode->data;
  delete currNode; 
}
/*Overload the [] ​operator so that it takes an integer subscript as a parameter and returns
a pointer to the Vehicle​ object at that position in the list.*/
Vehicle* VehicleList::operator[](int i){ //added
  if(i< 0 || i > getSize()){
    cerr<< "OverFlow" <<endl;
    return 0;
  }
  Node *tmpNode = head;
  int j = 0;

  if(head == 0){
    return NULL;
  }
  tmpNode = head;
  while(j < i){
    tmpNode = tmpNode->next;
    j++;
  }
  return tmpNode->data;

}
/*Overload the <<​ operator so that it prints the contents of the VehicleList*/
ostream& operator<< (ostream& output, VehicleList& list){ //added
  output<<endl;
  for (int i=0; i < list.getSize(); ++i){
    output << *list[i] <<endl;
  } 
  output<<endl;
  return output;
}



