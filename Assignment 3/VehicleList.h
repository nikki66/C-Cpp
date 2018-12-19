#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h" //collection of Vehicles

class VehicleList {
	class Node{
		friend class VehicleList;//frclass to class

		private:
			Vehicle* v;
			Node* next; 

	};

	public:
		VehicleList();
		~VehicleList();
		void add(Vehicle*);
		int getSize() const;

		void toString(string&) const;

	private:
		Node* head;



};

#endif 