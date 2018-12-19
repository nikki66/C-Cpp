#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;
#include <string>

/*a LinkedList.h file contains the class definition as well as the
function definitions.*/
template<class T>
class LinkedList{

	template<class N>
	class Node{
		friend class LinkedList<N>;
		N* data;
		Node<N>* next;
	};

	template<typename V> 
	friend ostream& operator<<(ostream&, LinkedList<V>&);

	public:
		LinkedList();
		~LinkedList();

		int getSize() const;
		LinkedList<T>& operator+=(T*);
		LinkedList<T>& operator-=(T*);
		T* operator[](int);

	private:
		Node<T>* head;


	
};
template<class T>
LinkedList<T>::LinkedList() : head(0) { }

template<class T>
LinkedList<T>::~LinkedList()
{
  Node<T> *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator+=(T* newT)
{
  Node<T> *currNode, *prevNode;
  Node<T>* newNode = new Node<T>;
  newNode->data = newT;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) < *(currNode->data))
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

  return *this;
}

template<class T>
LinkedList<T>& LinkedList<T>::operator-=(T* t)
{
  Node<T> *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == t)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
    return *this;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode;

  return *this;
}

/*Note: There is one function that we will not provide in our generic template, the get​ function.*/

template<class T>
int LinkedList<T>::getSize() const {
  Node<T> *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

template<class T>
T* LinkedList<T>::operator[](int i) {
    if(i < 0 || i > (getSize()-1)) {
        return 0;
    } else {

        Node<T> *currNode = head;

        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }

        return currNode->data;
    }
}

template<class T>
ostream& operator<<(ostream& output, LinkedList<T>& ll)
{
  
  for (int i = 0; i < ll.getSize(); i++)  {
    output << (*(ll[i]));
  }
    
  return output;

}

#endif