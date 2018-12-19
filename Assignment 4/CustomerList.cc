#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

#include "CustomerList.h"

CustomerList::CustomerList() : head(0) { }


CustomerList::~CustomerList()
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

Customer* CustomerList::get(int id) 
{
  Node *currNode = head;

  while (currNode != 0) {
    if(currNode->data->getId() == id) {
      return currNode->data;
    }
    currNode = currNode->next;
  }

  return 0;
}

int CustomerList::getSize() const {
  Node *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

/* Overload the +=​ operator that takes a Customer​ pointer and adds it to the
CustomerList​.*/
void CustomerList::operator+=(Customer* newCust){ //added
  Node *currNode, *prevNode;
  Node* newNode = new Node;
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) < *(currNode->data)) // modified- getLname()
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
/*Overload the -= ​so that it takes a Customer​ pointer and removes it from the
CustomerList​.*/
void CustomerList::operator-=(Customer* oldCust){ //added
  Node *currNode, *prevNode;

  prevNode = 0;
  currNode = head;

  while (currNode != 0) {
    if (currNode->data->getId() == oldCust->getId())
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
  for(int i = 0; i < currNode->data->getNumVehicles(); i++){
    currNode->data->getVehicles()-= currNode->data->getVehicles()[i];
  }
  delete currNode->data;
  delete currNode;
}
/*Overload the [] ​operator so that it takes an integer subscript as a parameter and returns
a pointer to the Customer​ object at that position in the list.*/
Customer* CustomerList::operator[](int i){ //added
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
/*Overload the <<​ operator so that it prints the contents of the CustomerList​. */
ostream& operator<< (ostream& output, CustomerList& list){ //added
  output<<endl;
  for (int i=0; i < list.getSize(); ++i){
    output << *list[i] <<endl;
  } 
  output<<endl;
  return output;
}


