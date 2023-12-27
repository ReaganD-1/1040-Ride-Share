#ifndef PASSENGER_H
#define PASSENGER_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Passenger
{
	private:
	//passenger variables
	unsigned long int passID;
	string passname;
	string passpayment;
	bool passhand;
	float passderating;
	bool passpet;
	int passcount;
	
	public:
	//passenger functions
	Passenger();
	Passenger(unsigned long int PID, string Pname, string Ppayment, bool Phand, float Pderating, bool Ppet, int Pcount);
	
	//passenger set functions
	void SetPassID(unsigned long int PID);
	void SetPassName(string Pname);
	void SetPassPayment(string Ppayment);
	void SetPassHand(bool Phand);
	void SetPassDeRating(float Pderating);
	void SetPassPet(bool Ppet);
	
	void SetPassDeCount();
	void SetPassIncCount();
	
	//passenger get functions
	unsigned long int GetPassID() const;
	string GetPassName() const;
	string GetPassPayment() const;
	bool GetPassHand() const;
	float GetPassDeRating() const;
	bool GetPassPet() const;
	int GetPassCount() const;
	
};

#endif