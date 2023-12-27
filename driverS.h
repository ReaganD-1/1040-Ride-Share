#ifndef DRIVERS_H
#define DRIVERS_H
#include <iostream>
#include <vector>
#include <string>
#include "driver.h"
using namespace std;

	

class DriverS
{
	private:
		//creates driverlist
		vector<Driver> driverlist;
	public:
		//driver functions
		void AddDriver(); 
		void DeleteDriver(unsigned long int DRIVERID);
		void EditDriver();
		void CleanDriver();
		
		//print driver functions
		void PrintDriverAllName();
		void PrintDriverAllInfo();
		void PrintDriverByID(unsigned long int DRIVERID);
		
		//driver files functions
		void LoadDriver();
		void StoreDriver();
		
		//find driver functions
		Driver FindDriverByID(unsigned long int DRIVERID);
		Driver FindDriverByName(string DRIVERNAME);
		
		//gets driver functions
		vector<Driver>& GetDriverList();
};
		
#endif