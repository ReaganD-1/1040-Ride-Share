#ifndef RIDES_H
#define RIDES_H
#include <iostream>
#include <vector>
#include <string>
#include "ride.h"
#include "driver.h"
#include "passenger.h"
using namespace std;
	
class RideS
{
	private:
		//creates the ridelist vector
		vector<Ride>ridelist;
		
	public:
		//rides functions
		void AddRide(vector<Driver>&driverlist, vector<Passenger>&passengerlist);
		void DeleteRide(unsigned long int RIDEID);
		void EditRide();
		void CleanRide();
		
		//rides file functions
		void LoadRide();
		void StoreRide();
		
		//rides find function
		Ride FindRideByID(unsigned long int RIDEID);
		
		//rides print function
		void PrintAllRide();
		void PrintRideByID(unsigned long int RID);
		void PrintAllActive(vector<Driver>&driverlist, vector<Passenger>&passengerlist);
		void PrintAllPast(vector<Driver>&driverlist, vector<Passenger>&passengerlist);
		void PrintAllCancelled(vector<Driver>&driverlist, vector<Passenger>&passengerlist);
		void PrintRidesForPassenger(unsigned long int PID);
		void PrintRideForDriver(unsigned long int DID);
		
		//rides get ridelist function
		vector<Ride>& GetRideList();
};
#endif