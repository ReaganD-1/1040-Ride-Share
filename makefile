Library: main.o passenger.o passengerS.o driver.o driverS.o ride.o rideS.o 
		g++ main.o passenger.o passengerS.o driver.o driverS.o ride.o rideS.o -o Library

main.o: main.cpp passenger.h passengerS.h driver.h driverS.h ride.h rideS.h
		g++ -c main.cpp

passenger.o: passenger.cpp passenger.h
		g++ -c passenger.cpp
		
passengerS.o: passengerS.cpp passengerS.h
		g++ -c passengerS.cpp
		
ride.o: ride.cpp ride.h
		g++ -c ride.cpp
		
rideS.o: rideS.cpp rideS.h
		g++ -c rideS.cpp
		
driver.o: driver.cpp driver.h
		g++ -c driver.cpp

driverS.o: driverS.cpp driverS.h
		g++ -c driverS.cpp
		
clean: rm *.o Library
		