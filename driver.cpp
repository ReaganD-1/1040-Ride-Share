#include <iostream>
#include <string>
#include "driver.h"
using namespace std;

	//initalizes driver variables
	Driver::Driver()
	{
	driverID = 0;
	drivername = "";
	drivervehcap = 0;
	driverhand = 0;
	drivervehtype = "";
	driverrating = 0.0;
	driverava = 0;
	driverpets = 0;
	drivernotes = "";
	driveropen = 1;
	drivercount = 0;
	driverstart = 0;
	drivercount2 = 0;
	}
	
	//helps creates driver function
	Driver::Driver(unsigned long int DID, string Dname, int Dvehcap, bool Dhand, string Dvehtype, float Drating, bool Dava, bool Dpets, string Dnotes, bool Dopen, int Dcount, time_t Dstart, int Dcount2)
	{
		driverID = DID;
		drivername = Dname;
		drivervehcap = Dvehcap;
		driverhand = Dhand;
		drivervehtype = Dvehtype;
		driverrating = Drating;
		driverava = Dava;
		driverpets = Dpets;
		drivernotes = Dnotes;
		driveropen = Dopen;
		drivercount = Dcount;
		driverstart = Dstart;
		drivercount2 = Dcount2;
	}
	
	//sets driver variables
	void Driver::SetDriverID(unsigned long int DID)
	{
		driverID = DID;
	}
	void Driver::SetDriverName(string Dname)
	{
		drivername = Dname;
	}
	void Driver::SetDriverVehCap(int Dvehcap)
	{
		drivervehcap = Dvehcap;
	}
	void Driver::SetDriverHand(bool Dhand)
	{
		driverhand = Dhand;
	}
	void Driver::SetDriverVehType(string Dvehtype)
	{
		drivervehtype = Dvehtype; 
	}
	void Driver::SetDriverRating (float Drating)
	{
		driverrating = Drating;
		
	}
	void Driver::SetDriverAva(bool Dava)
	{
		driverava = Dava;
		
	}
	void Driver::SetDriverPets(bool Dpets)
	{
		driverpets = Dpets;
		
	}
	void Driver::SetDriverNotes(string Dnotes)
	{
		drivernotes = Dnotes;
	}
	void Driver::SetDriverOpen(bool Dopen)
	{
		drivernotes = Dopen;
	}
	void Driver::SetDriverCount(int Dcount)
	{
		drivercount = Dcount;
	}
	
	void Driver::SetDriverAvailablityStart(time_t Dstart)
	{
		driverstart = Dstart;
	}
	
	void Driver::SetDriverDeCount()
	{
		drivercount2 -= 1;
	}
	
	void Driver::SetDriverIncCount()
	{
		drivercount2 += 1;
	}
	
	//gets driver variables
	unsigned long int Driver::GetDriverID() const
	{
		return driverID;
	}
	string Driver::GetDriverName() const
	{
		return drivername;
	}
	int Driver::GetDriverVehCap() const
	{
		return drivervehcap;
	}
	bool Driver::GetDriverHand() const
	{
		return driverhand;
	}
	string Driver::GetDriverVehType() const
	{
		return drivervehtype;
	}
	float Driver::GetDriverRating() const
	{
		return driverrating;
	}
	bool Driver::GetDriverAva() const
	{
		return driverava;
	}
	bool Driver::GetDriverPets() const
	{
		return driverpets;
	}
	string Driver::GetDriverNotes() const
	{
		return drivernotes;
	}
	bool Driver::GetDriverOpen() const
	{
		return driveropen;
	}
	int Driver::GetDriverCount() const
	{
		return drivercount;
	}
	
	time_t Driver::GetDriverAvailablityStart() const
	{
		return driverstart;
	}
	
	int Driver::GetDriverCount2() const
	{
		return drivercount2;
	}