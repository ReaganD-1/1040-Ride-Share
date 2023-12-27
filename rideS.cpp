#include<ctime>
#include<vector>
#include<string>
#include<iostream>
#include<fstream>
#include<time.h>
#include "rideS.h"
#include "ride.h"
#include "driverS.h"
#include "driver.h"
#include "passengerS.h"
#include "passenger.h"
using namespace std;

	//initalize global functions
	unsigned long int Rid = 600000;
	unsigned int Ridecount = 0;
	
	//add ride function
	void RideS::AddRide(vector<Driver>&driverlist, vector<Passenger>&passengerlist)
	{
		//function variables
		string status = "active";
		unsigned long int passid;
		unsigned long int driverid;
        string ploc;
		string ptime;
        string dloc;
        string dtime;
        int size;
        bool pets;
        float derating;
        bool hand;
		bool open = 1;
		
		bool passtrue = 0;
		
		unsigned long int Tpassid;
		
		Passenger pass;
		Driver driver;
		Ride ride;
		
		//creates ride id
		Rid = Rid + Ridecount;
		
		//creates ride
		do{
			cout<<"Enter passenger ID: "<<endl;
			cin >> Tpassid;
		
			for (int i = 0; i < passengerlist.size(); ++i)
			{
				if (Tpassid == passengerlist[i].GetPassID())
				{
					passid = Tpassid;
					pets = pass.GetPassPet();
					derating = pass.GetPassDeRating();
					hand = pass.GetPassHand();
					passtrue = 1;
				}
				else if (i == passengerlist.size())
				{
					cout<< "Please enter vaild passenger id: " <<endl;
				}
			}
		}while(passtrue != 1);
		
		cin.ignore();
		
		cout<<"Enter pickup location: "<<endl;
		getline(cin, ploc);

		cout<<"Enter pick up time (MM/DD/YY HH:MM AM/PM)"<<endl;
		getline(cin,ptime);
		
		cout<< "Enter drop off location: "<<endl;
		getline(cin,dloc);

		cout<<"Enter drop off time (MM/DD/YY HH:MM AM/PM)"<<endl;
		getline(cin, dtime);
		
		cout<<"Enter ride size: "<<endl;
		cin>> size;
		
		//find a driver for the ride
		for (int i = 0; i < driverlist.size(); ++i)
		{
			if (hand == driverlist[i].GetDriverHand() || driverlist[i].GetDriverHand() == 1)
			{
				if (derating <= driverlist[i].GetDriverRating())
				{
					if (pets == driverlist[i].GetDriverPets() || driverlist[i].GetDriverPets() == 1)
					{
						if (size <= driverlist[i].GetDriverVehCap())
						{
							if (driverlist[i].GetDriverOpen() == 1)
							{
								if (driverlist[i].GetDriverAva() == 1)
								{
									cout<<"Driver has been found!"<<endl<<endl;
									driverid = driverlist[i].GetDriverID();
									open = 0;
									driverlist[i].SetDriverOpen(open);
								}
							}
						}
					}
				}
			}
		}
				
		//adds the new ride to ridelist
		Ride temp(Rid, status, passid, driverid, ploc, ptime, dloc, dtime, size, pets, derating, hand, Ridecount);
		ridelist.push_back(temp);
		
		//prints ride is added and instructions for user after the ride
		cout<<"Ride is added!"<<endl;
		cout<<"Once ride is complete or you want to cancell the ride please edit the ride status in the edit ride menu."<<endl;
		cout<<"Once ride is complete please enter the drivers rating in the edit ride menu."<<endl;
		
		//increases ride count
		ride.SetRideIncCount();
		
		//prints the new ride
		PrintRideByID(Rid);
		
		//increases ride count
		Ridecount += 1;
	}
	
	//ride delete function
	void RideS::DeleteRide(unsigned long int RIDEID)
	{
		Ride ride;
		for (int i = 0; i < ridelist.size(); i++)
		{
			if (ridelist[i].GetRideID() == RIDEID)
			{
				ridelist.erase(ridelist.begin() + i);
			}
		}
		
		//decreases ride count
		ride.SetRideDeCount();
	}
	
	//ride edit function
	void RideS::EditRide()
	{
		//function variables
		char choice;
		unsigned long int ID;
		string status = "active";
		unsigned long int passid;
		unsigned long int driverid;
        string ploc;
		string ptime;
        string dloc;
        string dtime;
        int size;
        bool pets;
        float derating;
        bool hand;
		float rating;
		float drating;
		int count;
		
		bool open;
		unsigned long int tempid;
		DriverS driver;
		Driver driver2;
		
		cout<<"Enter the ID of the ride you want to edit: "<<endl;
		cin >> ID;
		
		for (int i =0; i < ridelist.size(); ++i)
		{
			if (ID == ridelist[i].GetRideID())
			{
				do
				{
					cout << "Edit menu: "<<endl;
					cout<< "s - Edit Status: " <<endl;
					cout << "a - Edit Pickup Location: " <<endl;
					cout << "b - Edit Pickup Time: "<<endl;
					cout << "c - Edit Dropoff Location: "<<endl;
					cout << "d - Edit Dropoff Time: "<<endl;
					cout<< "r - Rating Your Driver: "<<endl;
					cout<< "q - Quit: "<<endl;
					cout<< "Please enter your choice: "<<endl;
					cin >> choice;
					cout << endl<<endl;
					
					switch(choice)
					{
						case 's':
						cout<< "Please enter new status (Completed or Cancelled): "<<endl;
						cin.ignore();
						getline(cin, status);
						
						if (status == "Complete" || status == "complete" || status == "Cancelled" || status == "cancelled")
						{
							open = 1;
							tempid = ridelist[i].GetDriverID();
							driver2 = driver.FindDriverByID(tempid);
							driver2.SetDriverOpen(open);
						}
						
						ridelist[i].SetRideStatus(status);
						cout<<endl;
						break;
						
						case 'a':
						cout<< "Please enter new pickup location: "<<endl;
						cin.ignore();
						getline(cin, ploc);
						ridelist[i].SetRidePLoc(ploc);
						cout<<endl;
						break;
						
						case 'b':
						cout<< "Please enter new pickup time: "<<endl;
						cin.ignore();
						getline(cin, ptime);
						ridelist[i].SetRidePTime(ptime);
						cout<<endl;
						break;
						
						case 'c':
						cout<< "Please enter new dropoff location: "<<endl;
						cin.ignore();
						getline(cin, dloc);
						ridelist[i].SetRideDLoc(dloc);
						cout<<endl;
						break;
						
						case 'd':
						cout<< "Please enter new dropoff time: "<<endl;
						cin.ignore();
						getline(cin, dtime);
						ridelist[i].SetRideDTime(dtime);
						cout<<endl;
						break;
						
						case 'r':
						cout<<"Please enter the rating you give your driver: "<<endl;
						if (ridelist[i].GetRideStatus() == "completed" || ridelist[i].GetRideStatus() == "Completed")
						{
						cin >> rating;
						tempid = ridelist[i].GetDriverID();
						driver2 = driver.FindDriverByID(tempid);
						
						count = driver2.GetDriverCount();
						count += 1;
						driver2.SetDriverCount(count);
						count = driver2.GetDriverCount();
						
						drating = driver2.GetDriverRating();
						drating = (drating + rating) / (count);
						driver2.SetDriverRating(drating);
						}
						else
						{
							cout<<"Ride status is cancelled or active."<<endl;
						}
						cout<<endl;
						break;
						
						case 'q':
						cout<<"Goodbye"<<endl;
						break;
						
						default:
						cout<<"Please enter vaild choice."<<endl;
					}
				}while(choice != 'q');
			}
		}
	}
	
	//ride clear ridelist function
	void RideS::CleanRide()
	{
		ridelist.clear();
	}
		
	//ride load file function
	void RideS::LoadRide()
	{
		ifstream fin;
		int ID = 0;
		string status ="";
		int Passid = 0;
		int Driverid =0;
        string ploc="";
        string dloc="";
        string ptime="";
        string dtime="";
        int size =0;
        bool pets =0;
        float rating =0;
        bool hand=0;
		Ride ride;
		int Rcount=0;
		
		fin.open("rideS.dat");
		
		
		ridelist.clear();
		
		if (!fin.is_open()) 
		{
			cout << "Error: Cannot open the file." << endl;
			return; // or handle the error as appropriate
		}
		else
		{
		
			fin >> Rcount;
		
			if (Rcount != 0)
			{
				for ( int i=0; i < Rcount; i++)
				{
					fin >> ID;
					fin.ignore();
					getline(fin,status,'\n');
					fin >> Passid;
					fin>> Driverid;
					fin.ignore();
					getline(fin,ploc, '\n');
					getline(fin, ptime, '\n');
					getline(fin, dloc, '\n'); 
					getline(fin,dtime,'\n'); 
					fin >> size>> pets >> rating >> hand;
					Ride temp(ID,status,Passid,Driverid, ploc, ptime, dloc, dtime,  size, pets, rating, hand, Rcount);
					ridelist.push_back(temp);
					
					Ridecount += 1;
				}
			}
			else
			{
				cout<<"No data in the ride file"<<endl;
			}
		}
		fin.close();
	}
	
	//ride store file function
	void RideS::StoreRide()
	{
		ofstream fout;
		fout.open("rideS.dat");
		
		Ride ride;
		Passenger pass;
		Driver driver;
		
		if (!fout.is_open()) 
		{
			cout << "Error: Cannot open the file." << endl;
			return; // or handle the error as appropriate
		}
		
		fout <<  ridelist.size() << "\n";
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
			{
				fout << ridelist[i].GetRideID()<< "\n";
				fout<<  ridelist[i].GetRideStatus()<< "\n";
				fout<<  ridelist[i].GetPassID()<< "\n";
				fout<<  ridelist[i].GetDriverID()<< "\n";
				fout<<  ridelist[i].GetRidePLoc()<< "\n";
				fout<<  ridelist[i].GetRidePTime()<< "\n";
				fout<<  ridelist[i].GetRideDLoc()<< "\n";
				fout<<  ridelist[i].GetRideDTime()<< "\n";
				fout<<  ridelist[i].GetRideSize()<< "\n";
				fout<<  ridelist[i].GetRidePets()<< "\n";
				fout<<  ridelist[i].GetRideRating()<< "\n";
				fout<<  ridelist[i].GetRideHand() << endl;
			}
		}
		else
		{
			cout<<"There is no ride data."<<endl;
		}
		fout.close();
	}
		
	//ride find ride by ID function
	Ride RideS::FindRideByID(unsigned long int RIDEID)
	{
		Ride temp;
		if (ridelist.size() != 0)
		{
			for (int i =0; ridelist.size(); i++)
			{
				if (ridelist[i].GetRideID() == RIDEID) 
				{
					temp = ridelist[i];
				}
			}

		}			
		else
		{
			cout<<"There is no data."<<endl;
		}
  
			return temp;
	}
	
	//ride print function
	void RideS::PrintAllRide()
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
			{
				cout<< "Ride ID: "<< ridelist[i].GetRideID() <<endl;
				cout << "Ride status: "<< ridelist[i].GetRideStatus () <<endl;
				cout << "Passenger ID for this ride: "<< ridelist[i].GetPassID() <<endl;
				cout<<"Driver ID for this ride: "<< ridelist[i].GetDriverID() <<endl;
				cout<<"Ride pickup location: " << ridelist[i].GetRidePLoc() <<endl;
				cout << "Ride pickup time: " << ridelist[i].GetRidePTime() <<endl;
				cout<<"Ride dropoff location: "<<ridelist[i].GetRideDLoc() <<endl;
				cout<<"Ride drop off time: " << ridelist[i].GetRideDTime() <<endl;
				cout<<"Ride size: " << ridelist[i].GetRideSize() <<endl;
				if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
			
	}
	
	//ride print ride by ID function
	void RideS::PrintRideByID(unsigned long int RID)
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for ( int i =0; i < ridelist.size(); ++i)
			{
				if (ridelist[i].GetRideID() == RID)
				{
					cout<< "Ride Status: " <<ridelist[i].GetRideStatus()<<endl;
					cout<< "Ride ID: "<<ridelist[i].GetRideID()<<endl;
					cout<< "Ride Passenger ID: "<<ridelist[i].GetPassID()<<endl;
					cout<< "Ride Driver ID: "<<ridelist[i].GetDriverID()<<endl;
					cout<< "Ride Pickup Location: "<<ridelist[i].GetRidePLoc()<<endl;
					cout<< "Ride Pickup Time: "<<ridelist[i].GetRidePTime()<<endl;
					cout<<"Ride Dropoff Location: "<<ridelist[i].GetRideDLoc()<<endl;
					cout<<"Ride Dropoff Time: "<<ridelist[i].GetRideDTime()<<endl;
					cout<< "Ride Size Status: "<<ridelist[i].GetRideSize()<<endl;
					if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
	
	//ride print active rides function
	void RideS::PrintAllActive(vector<Driver>&driverlist, vector<Passenger>&passengerlist)
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
			{
				if (ridelist[i].GetRideStatus() == "active" || ridelist[i].GetRideStatus() == "Active")
				{
					cout<< "Ride Status: " <<ridelist[i].GetRideStatus()<<endl;
					cout<< "Ride ID: "<<ridelist[i].GetRideID()<<endl;
					cout<< "Ride Passenger ID: "<<ridelist[i].GetPassID()<<endl;
					cout<< "Ride Driver ID: "<<ridelist[i].GetDriverID()<<endl;
					cout<< "Ride Pickup Location: "<<ridelist[i].GetRidePLoc()<<endl;
					cout<< "Ride Pickup Time: "<<ridelist[i].GetRidePTime()<<endl;
					cout<<"Ride Dropoff Location: "<<ridelist[i].GetRideDLoc()<<endl;
					cout<<"Ride Dropoff Time: "<<ridelist[i].GetRideDTime()<<endl;
					cout<< "Ride Size Status: "<<ridelist[i].GetRideSize()<<endl;
					if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
	
	//print all past rides function
	void RideS::PrintAllPast(vector<Driver>&driverlist, vector<Passenger>&passengerlist)
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
			{
				if (ridelist[i].GetRideStatus() == "completed" || ridelist[i].GetRideStatus() == "Completed")
				{
					cout<< "Ride Status: " <<ridelist[i].GetRideStatus()<<endl;
					cout<< "Ride ID: "<<ridelist[i].GetRideID()<<endl;
					cout<< "Ride Passenger ID: "<<ridelist[i].GetPassID()<<endl;
					cout<< "Ride Driver ID: "<<ridelist[i].GetDriverID()<<endl;
					cout<< "Ride Pickup Location: "<<ridelist[i].GetRidePLoc()<<endl;
					cout<< "Ride Pickup Time: "<<ridelist[i].GetRidePTime()<<endl;
					cout<<"Ride Dropoff Location: "<<ridelist[i].GetRideDLoc()<<endl;
					cout<<"Ride Dropoff Time: "<<ridelist[i].GetRideDTime()<<endl;
					cout<< "Ride Size Status: "<<ridelist[i].GetRideSize()<<endl;
					if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
	
	//prints ride cancelled function
	void RideS::PrintAllCancelled(vector<Driver>&driverlist, vector<Passenger>&passengerlist)
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
			{
				if (ridelist[i].GetRideStatus() == "cancelled" || ridelist[i].GetRideStatus() == "Cancelled")
				{
					cout<< "Ride Status: " <<ridelist[i].GetRideStatus()<<endl;
					cout<< "Ride ID: "<<ridelist[i].GetRideID()<<endl;
					cout<< "Ride Passenger ID: "<<ridelist[i].GetPassID()<<endl;
					cout<< "Ride Driver ID: "<<ridelist[i].GetDriverID()<<endl;
					cout<< "Ride Pickup Location: "<<ridelist[i].GetRidePLoc()<<endl;
					cout<< "Ride Pickup Time: "<<ridelist[i].GetRidePTime()<<endl;
					cout<<"Ride Dropoff Location: "<<ridelist[i].GetRideDLoc()<<endl;
					cout<<"Ride Dropoff Time: "<<ridelist[i].GetRideDTime()<<endl;
					cout<< "Ride Size Status: "<<ridelist[i].GetRideSize()<<endl;
					if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
	
	//prints rides for passenger function
	void RideS::PrintRidesForPassenger(unsigned long int PID)
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
				{
					if (ridelist[i].GetPassID() == PID)
					{
						cout<< "Ride Status: " <<ridelist[i].GetRideStatus()<<endl;
						cout<< "Ride ID: "<<ridelist[i].GetRideID()<<endl;
						cout<< "Ride Passenger ID: "<<ridelist[i].GetPassID()<<endl;
						cout<< "Ride Driver ID: "<<ridelist[i].GetDriverID()<<endl;
						cout<< "Ride Pickup Location: "<<ridelist[i].GetRidePLoc()<<endl;
						cout<< "Ride Pickup Time: "<<ridelist[i].GetRidePTime()<<endl;
						cout<<"Ride Dropoff Location: "<<ridelist[i].GetRideDLoc()<<endl;
						cout<<"Ride Dropoff Time: "<<ridelist[i].GetRideDTime()<<endl;
						cout<< "Ride Size Status: "<<ridelist[i].GetRideSize()<<endl;
						if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
					}
				}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
	
	//prints rides for driver function
	void RideS::PrintRideForDriver(unsigned long int DID)
	{
		string temp;
		if (ridelist.size() != 0)
		{
			for (int i = 0; i < ridelist.size(); ++i)
			{
				if (ridelist[i].GetDriverID() == DID)
				{
					cout<< "Ride Status: " <<ridelist[i].GetRideStatus()<<endl;
					cout<< "Ride ID: "<<ridelist[i].GetRideID()<<endl;
					cout<< "Ride Passenger ID: "<<ridelist[i].GetPassID()<<endl;
					cout<< "Ride Driver ID: "<<ridelist[i].GetDriverID()<<endl;
					cout<< "Ride Pickup Location: "<<ridelist[i].GetRidePLoc()<<endl;
					cout<< "Ride Pickup Time: "<<ridelist[i].GetRidePTime()<<endl;
					cout<<"Ride Dropoff Location: "<<ridelist[i].GetRideDLoc()<<endl;
					cout<<"Ride Dropoff Time: "<<ridelist[i].GetRideDTime()<<endl;
					cout<< "Ride Size Status: "<<ridelist[i].GetRideSize()<<endl;
					if (ridelist[i].GetRidePets() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRidePets() == 0)
					{
						temp = "False";
					}
					cout<< "Ride pet status: "<< temp <<endl;
					cout<<"Ride rating: "<< ridelist[i].GetRideRating()<<endl;
					if (ridelist[i].GetRideHand() == 1)
					{
						temp = "True";
					}
					else if(ridelist[i].GetRideHand() == 0)
					{
						temp = "False";
					}
				cout<< "Ride handicapped status: "<<temp<<endl;
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
	
	//returns the ridelist
	vector<Ride>& RideS::GetRideList()
	{
		return ridelist;
	}