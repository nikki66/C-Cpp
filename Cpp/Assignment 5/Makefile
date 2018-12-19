OBJ = main.o ShopController.o View.o Shop.o Customer.o Vehicle.o Mechanic.o Person.o Car.o Truck.o Motorcycle.o VehicleFactory.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h
	g++ -c ShopController.cc

View.o:	View.cc View.h 
	g++ -c View.cc

Shop.o:	Shop.cc Shop.h LinkedList.h Mechanic.h
	g++ -c Shop.cc

Customer.o:	Customer.cc Customer.h Person.h Vehicle.h
	g++ -c Customer.cc

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -c Vehicle.cc

Mechanic.o: Mechanic.cc Mechanic.h Person.h
	g++ -c Mechanic.cc

Person.o: Person.h Person.cc
	g++ -c Person.cc

Car.o: Car.h Car.cc
	g++ -c Car.cc

Truck.o: Truck.h Truck.cc
	g++ -c Truck.cc

Motorcycle.o: Motorcycle.h Motorcycle.cc
	g++ -c Motorcycle.cc

VehicleFactory.o: VehicleFactory.h VehicleFactory.cc
	g++ -c VehicleFactory.cc


clean:
	rm -f $(OBJ) mechanicshop
