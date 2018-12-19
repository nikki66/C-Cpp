#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include "Vehicle.h"


class VehicleList
{
  class Node
  {
    friend class VehicleList;
    private:
      Vehicle* data;
      Node*    next;
  };

  public:
    VehicleList();
    ~VehicleList();

    int getSize() const;

    friend ostream& operator<< (ostream&, VehicleList&); //added

    void operator+=(Vehicle*); //added
    void operator-=(Vehicle*); //added
    Vehicle* operator[](int); //added

  private:
    Node* head;
};

#endif
