#ifndef MECHANIC_H
#define MECHANIC_H

#include <string>
#include "Person.h" //inheritance

using namespace std;

class Mechanic : public Person {

    public:
    
        Mechanic(string="", string="", string="", string="", int= 0);
        int getId() const;
        int getSalary() const;
        friend ostream& operator<< (ostream&, Mechanic&);
        
        
    private:
        static int nextId;
        const int id;
        int salary;


};

#endif
