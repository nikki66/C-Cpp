#include "CustomerArray.h"
#include "Customer.h"
#include "defs.h"


//added

/*The constructor simply initializes the size data member properly*/
CustomerArray::CustomerArray(){
	size = 0;
}

/*The destructor must iterate over the stored objects (which are to be dynamically
allocated), freeing the allocated memory for each one.*/
CustomerArray::~CustomerArray(){
	for(int i=0; i<getSize(); i++){
		delete elements[i];
		elements[i] = NULL;
	}
}

/*getSize Getter*/
int      CustomerArray::getSize()     { return size; }

/*The add function takes a pointer to a dynamically allocated object. It checks if there is
room in the array of pointers for this object. If not, it returns C_NOK (defined in defs.h). If
there is, it sets the appropriate pointer in the array to point at the same object as the
parameter, increments the size data member and returns C_OK (also defined in
defs.h).*/
int CustomerArray::add(Customer* c){
	if(getSize() != MAX_CUSTOMERS){
		elements[size++] = c;
		return C_OK;
	}else{
		return C_NOK;
	}

}

/*The get function takes an index value. If this index is not valid (ie. it is outside of the
range of valid objects being stored), the function returns 0. Otherwise it returns the
pointer at index i.*/
Customer* CustomerArray::get(int postion){
	if(postion < 0 || postion >= getSize()){
		return 0;
	}else{
		return elements[postion];
	}
}