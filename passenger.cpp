#include <iostream>
#include <string>
#include "passenger.h"
using namespace std;

	//initalizes passenger variables
	Passenger::Passenger()
	{
		passID = 0;
		passname = "";
		passpayment = "";
		passhand = 0;
		passderating = 0.0;
		passpet = 0;
		passcount =0;
	}
	
	//helps creates new passenger
	Passenger::Passenger(unsigned long int PID, string Pname, string Ppayment, bool Phand, float Pderating, bool Ppet, int Pcount)
	{
		passID = PID;
		passname = Pname;
		passpayment = Ppayment;
		passhand = Phand;
		passderating = Pderating;
		passpet = Ppet;
		passcount = Pcount;
	}
	
	//set passenger variables
	void Passenger::SetPassID(unsigned long int PID)
	{
		passID = PID;
		
	}
	void Passenger::SetPassName(string Pname)
	{
		passname = Pname;
		
	}
	void Passenger::SetPassPayment(string Ppayment)
	{
		passpayment = Ppayment;
		
	}
	void Passenger::SetPassHand(bool Phand)
	{
		passhand = Phand;
		
	}
	void Passenger::SetPassDeRating(float Pderating)
	{
		passderating = Pderating;
		
	}
	void Passenger::SetPassPet(bool Ppet)
	{
		passpet = Ppet;
	}
	
	void Passenger::SetPassDeCount()
	{
		passcount -= 1;
	}
	
	void Passenger::SetPassIncCount()
	{
		passcount += 1;
	}
	
	
	//gets passenger variables
	unsigned long int Passenger::GetPassID() const
	{
		return passID;
	}
	string Passenger::GetPassName() const
	{
		return passname;
	}
	string Passenger::GetPassPayment() const
	{
		return passpayment;
	}
	bool Passenger::GetPassHand() const
	{
		return passhand;
	}
	float Passenger::GetPassDeRating() const
	{
		return passderating;
	}
	bool Passenger::GetPassPet() const
	{
		return passpet;
	}
	int Passenger::GetPassCount() const
	{
		return passcount;
	}