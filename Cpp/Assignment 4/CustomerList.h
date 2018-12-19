#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"


class CustomerList
{
  class Node
  {
    friend class CustomerList;
    private:
      Customer* data;
      Node*    next;
  };

  public:
    CustomerList();
    ~CustomerList();
    int getSize() const;
    Customer* get(int);

    friend ostream& operator<< (ostream&, CustomerList&); //added

    void operator+=(Customer*); //added
    void operator-=(Customer*); //added
    Customer* operator[](int); //added

  private:
    Node* head;
};

#endif
