#ifndef PASSENGERS_H
#define PASSENGERS_H
#include <iostream>
#include <vector>
#include <string>
#include "passenger.h"
using namespace std;

class PassengerS
{
	private:
		//creates the passengerlist vector
		 vector<Passenger> passengerlist;
	public:
		//passengerS functions
		void AddPass();
		void DeletePass(unsigned long int PASSID);
		void EditPass();
		void CleanPass();
		void PrintPassAllName();
		
		//print passenger function
		void PrintPassAllInfo();
		void PrintPassByID(unsigned long int PASSID);
		
		//file passenger function
		void LoadPass();
		void StorePass();
		
		//find passenger function
		Passenger FindPassByID(unsigned long int PASSID);
		Passenger FindPassByName(string PASSNAME);
		
		//gets the passengerlist
		vector<Passenger>& GetPassengerList();
};
#endif