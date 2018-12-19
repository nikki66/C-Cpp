#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h" //collection of customers

class CustomerList {
	class Node{
		friend class CustomerList; //frclass to class

		private:
			Customer* c;
			Node* next; 

	};

	public:
		CustomerList();
		~CustomerList();
		void add(Customer*);
		int getSize() const;
		Customer* get(int) const;

		void toString(string&) const;


	private:
		Node* head;



};

#endif 