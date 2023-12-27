#include "ride.h"
#include <iostream>
#include <string>

using namespace std;

	//initializes ride variable
	Ride::Ride()
	{
			rideID = 0;
			rideploc = "";
			ridedloc = "";
			rideptime = "";
			ridedtime = "";
			ridesize = 0;
			ridepets = 0;
			ridestatus = "";
			riderating = 0.0;
			ridehand = 0;
			passid = 0;
			driverid = 0;
			ridecount = 0;
	}
	
	//can add a ride with this function
	Ride::Ride(unsigned long int RID, string Rstatus, unsigned long int PassID, unsigned long int DriverID, string Rploc,string Rptime, string Rdloc, string Rdtime, int Rsize, bool Rpets,  float Rrating, bool Rhand, int Rcount)
	{
			rideID = RID;
			ridestatus =Rstatus;
			passid = PassID;
			driverid = DriverID;
			rideploc = Rploc;
			rideptime = Rptime;
			ridedloc = Rdloc;
			ridedtime = Rdtime;
			ridesize = Rsize;
			ridepets = Rpets;
			riderating = Rrating;
			ridehand = Rhand;
			ridecount = Rcount;
	}

	//sets ride variables
	void Ride::SetRideID(unsigned long int RID)
	{
		rideID = RID;
	}
		void Ride::SetRideStatus (string Rstatus)
	{
		ridestatus =Rstatus;     
	}
	void Ride::SetPassID (unsigned long int PassID)
	{
		passid = PassID;
	}

	void Ride::SetDriverID (unsigned long int DriverID)
	{
		driverid = DriverID;
	}
	void Ride::SetRidePLoc(string Rploc)
	{
		rideploc = Rploc;
	}
	void Ride::SetRidePTime(string Rptime)
	{
		rideptime = Rptime;
	}
	void Ride::SetRideDLoc(string Rdloc)
	{
		ridedloc =Rdloc;
	}
	void Ride::SetRideDTime(string Rdtime)
	{
		ridedtime = Rdtime;       
	}
	void Ride::SetRideSize(int Rsize)
	{
		ridesize = Rsize;
	}
	void Ride::SetRidePets(bool Rpets)
	{
		ridepets = Rpets;
	}
	void Ride::SetRideRating (float Rrating)
	{
		riderating = Rrating;
	}
	void Ride::SetRideHand (bool Rhand)
	{
		ridehand = Rhand;
	}
	void Ride::SetRideDeCount()
	{
		ridecount -= 1;
	}
	void Ride::SetRideIncCount()
	{
		ridecount += 1;
	}
	
	//get ride variables
	int Ride::GetRideID() const
	{
			return rideID;
	}
		string Ride::GetRideStatus () const
	{
			return ridestatus;
	}
		int Ride::GetPassID () const
	{
		return passid;
	}
	int Ride::GetDriverID () const
	{
		return driverid;
	}

	string Ride::GetRidePLoc() const
	{
			return rideploc;
	}
	string Ride::GetRidePTime() const
	{
			return rideptime;
	}
	string Ride::GetRideDLoc() const
	{
			return ridedloc;
	}
	string Ride::GetRideDTime() const
	{
			return ridedtime;
	}
	int Ride::GetRideSize() const
	{
			return ridesize;
	}
	bool Ride::GetRidePets() const
	{
			return ridepets;
	}
	float Ride::GetRideRating () const
	{
			return riderating;
	}
	bool Ride::GetRideHand () const
	{
			return ridehand;
	}
	int Ride::GetRideCount() const
	{
		return ridecount;
	}