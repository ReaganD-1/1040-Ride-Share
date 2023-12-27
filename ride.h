#ifndef RIDE_H
#define RIDE_H
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

class Ride
{
	private:
		//ride variables
        unsigned long int rideID;
        string rideploc;
        string ridedloc;
        string rideptime;
        string ridedtime;
        int ridesize;
        bool ridepets;
        string ridestatus;
        float riderating;
        bool ridehand;
		unsigned long int passid;
		unsigned long int driverid;
		int ridecount;
		
    public:
		
		//ride functions
        Ride();
        Ride(unsigned long int RID, string Rstatus, unsigned long int PassID, unsigned long int DriverID, string Rploc, string Rptime, string Rdloc, string Rdtime, int Rsize, bool Rpets, float Rrating, bool Rhand, int count);
		
		//ride set function
        void SetRideID(unsigned long int RID);
		 void SetRideStatus (string Rstatus);
		void SetPassID(unsigned long int PassID);
		void SetDriverID(unsigned long int DriverID);
        void SetRidePLoc(string Rploc);
        void SetRidePTime(string Rptime);
        void SetRideDLoc(string Rdloc);  
		void SetRideDTime(string Rdtime);
        void SetRideSize(int Rsize);
        void SetRidePets(bool Rpets);
        void SetRideRating (float Rrating);
        void SetRideHand(bool Rhand);
		
		void SetRideDeCount();
		void SetRideIncCount();
		
		//ride get functions
        int GetRideID() const;
        string GetRideStatus () const;
		int GetPassID() const;
		int GetDriverID() const;
        string GetRidePLoc() const;
        string GetRidePTime() const;
        string GetRideDLoc() const;
		string GetRideDTime() const;
        int GetRideSize() const;
        bool GetRidePets() const;
        float GetRideRating () const;
        bool GetRideHand () const;
		int GetRideCount() const;
};

#endif