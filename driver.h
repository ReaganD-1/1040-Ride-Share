#ifndef DRIVER_H
#define DRIVER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Driver
{
	private:
	//driver variables
	unsigned long int driverID;
	string drivername;
	int drivervehcap;
	bool driverhand;
	string drivervehtype;
	float driverrating;
	bool driverava;
	bool driverpets;
	string drivernotes;
	bool driveropen;
	int drivercount;
	time_t driverstart;
	int drivercount2;
	
	public:
	//driver function
	Driver();
	Driver(unsigned long int DID, string Dname, int Dvehcap, bool Dhand, string Dvehtype, float Drating, bool Dava, bool Dpets, string Dnotes, bool Dopen, int Dcount, time_t Dstart, int Dcount2);
	
	//set driver functions
	void SetDriverID(unsigned long int DID);
	void SetDriverName(string Dname);
	void SetDriverVehCap(int Dvehcap);
	void SetDriverHand(bool Dhand);
	void SetDriverVehType(string Dvehtype);
	void SetDriverRating (float Drating);
	void SetDriverAva(bool Dava);
	void SetDriverPets(bool Dpets);
	void SetDriverNotes(string Dnotes);
	void SetDriverOpen(bool Dopen);
	void SetDriverCount(int Dcount);
	void SetDriverAvailablityStart(time_t start);
	
	void SetDriverDeCount();
	void SetDriverIncCount();
	
	//get driver functions
	unsigned long int GetDriverID() const;
	string GetDriverName() const;
	int GetDriverVehCap() const;
	bool GetDriverHand() const;
	string GetDriverVehType() const;
	float GetDriverRating() const;
	bool GetDriverAva() const;
	bool GetDriverPets() const;
	string GetDriverNotes() const;
	bool GetDriverOpen() const;
	int GetDriverCount() const;
	time_t GetDriverAvailablityStart() const;
	
	int GetDriverCount2() const;
	
};

#endif