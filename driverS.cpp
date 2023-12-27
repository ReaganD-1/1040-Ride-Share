#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "driver.h"
#include "driverS.h"

using namespace std;
	
	//initalizes global variables
	unsigned long int Drid = 300000;
	unsigned int DriverCount = 0;

	void DriverS::AddDriver() 
	{
		//function variables
		string name;
		int vehcap;
		bool hand;
		string vehtype;
		bool pets;
		string notes;
		bool ava;
		float rating = 0.0;
		bool open = 1;
		int count = 0;
		time_t start = 0;
		Driver driver;
			
		//creates driver
		Drid = Drid + DriverCount;
		
		cout<<"Enter new driver name: "<<endl;
		cin.ignore();
		getline(cin, name);
		cout<<"Enter new driver vehicle capacity: "<<endl;
		cin >> vehcap;
		cin.ignore();
		cout<< "Enter new driver handicapped capabilities (1 for yes or 0 for no): "<<endl;
		cin >> hand;
		cout<< "Enter new driver vehicle type: "<<endl;
		cin.ignore();
		getline(cin, vehtype);
		cout<< "Enter new driver pets capabilites (1 for yes or 0 for no): "<<endl;
		cin >> pets;
		cout<< "Enter new driver notes: "<<endl;
		cin.ignore();
		getline(cin, notes);
		cout<<"Enter new driver avalibilty: "<<endl;
		cin >> ava;
		cout<< endl;
		
		//addes new driver to driverlist
		Driver temp (Drid, name, vehcap, hand, vehtype, rating, ava, pets, notes, open, count, start, DriverCount);
		
		driverlist.push_back(temp);
		
		driver.SetDriverIncCount();
		
		PrintDriverByID(Drid);

		DriverCount +=1;
	}
	
	//delete driver from driverlist
	void DriverS::DeleteDriver(unsigned long int DRIVERID)
	{
		Driver driver;
		
		for (int i = 0; i < driverlist.size(); i++)
		{
			if (driverlist[i].GetDriverID() == DRIVERID)
			{
				driverlist.erase(driverlist.begin() + i);
			}
		}
		
		driver.SetDriverDeCount();
	}
	
	//edits driver
	void DriverS::EditDriver()
	{
		char choice;
		string name;
		unsigned long int ID;
		int vehcap;
		bool hand;
		string vehtype;
		bool pets;
		string notes;
		bool ava;
		Driver driver;
		
		cout<<"Enter the ID of the driver you want to edit: "<<endl;
		cin>>ID;
		
		for (int i = 0; i < driverlist.size(); i++)
		{
			if(ID == driverlist[i].GetDriverID())
			{
				do{
					cout<<"Edit Menu: "<<endl;
					cout<<"n - Edit Name: "<<endl;
					cout<<"c - Edit Vehicle Capacity: "<<endl;
					cout<< "h - Edit Handicapped Capabilites: "<<endl;
					cout<<"t - Edit Vehicle Type: "<<endl;
					cout<<"p - Edit Pet Capabilites: "<<endl;
					cout<<"o - Edit Notes: "<<endl;
					cout<<"a - Edit avalibilty: "<<endl;
					cout<<"q - quit:"<<endl;
					cout<<"Please enter your choice: "<<endl;
					cin>>choice;
					cout<<endl<<endl;
			
					switch (choice)
					{
						case 'n':
						cout<<"Please enter new name: "<<endl;
						cin.ignore();
						getline(cin, name);
						driverlist[i].SetDriverName(name);
						cout<<endl;
						break;
						
						case 'c':
						cout<<"Please enter new vehicle capacity: "<<endl;
						cin>>vehcap;
						driverlist[i].SetDriverVehCap(vehcap);
						cout<<endl;
						break;
						
						case 'h':
						cout<<"Please enter new handicapped capabilites:"<<endl;
						cin>> hand;
						driverlist[i].SetDriverHand(hand);
						cout<<endl;
						break;
						
						case 't':
						cout<<"Please enter new vehicle type: "<<endl;
						cin.ignore();
						getline(cin, vehtype);
						driverlist[i].SetDriverVehType(vehtype);
						cout<<endl;
						break;
						
						case 'p':
						cout<<"Please enter new pet capabilites: "<<endl;
						cin>>pets;
						driverlist[i].SetDriverPets(pets);
						cout<<endl;
						break;
						
						case 'o':
						cout<<"Please enter new notes: "<<endl;
						cin.ignore();
						getline(cin, notes);
						driverlist[i].SetDriverNotes(notes);
						cout<<endl;
						break;
						
						case 'a':
						cout<<"Please enter new avalibilty: "<<endl;
						cin>> ava;
						driverlist[i].SetDriverAva(ava);
						cout<<endl;
						break;
						
						case 'q':
						cout<<"Goodbye"<<endl;
						break;
						
						default:
						cout<<"Please enter vaild choice."<<endl;
						break;
					}
				}while(choice != 'q');
			}
		}
	}
		
	//clears the driverlist
	void DriverS::CleanDriver()
	{
		driverlist.clear();
	}
	
	//prints all drivers names
	void DriverS::PrintDriverAllName()
	{
		cout<< "Drivers names:"<<endl;
		
		if (driverlist.size() != 0)
		{
			for (int i = 0; i < driverlist.size(); ++i)
			{
				cout<< driverlist[i].GetDriverName()<<endl;
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
		cout<<endl;
	}
		
		
	//prints all info for all drivers
	void DriverS::PrintDriverAllInfo()
	{
		string temp;
		if (driverlist.size() != 0)
		{
			for (int i = 0; i < driverlist.size(); ++i)
			{
				cout<< "Driver id: "<<driverlist[i].GetDriverID()<<endl;
				cout<<"Driver name: "<<driverlist[i].GetDriverName()<<endl;
				cout<<"Driver vehicle capacity: "<<driverlist[i].GetDriverVehCap()<<endl;
				cout<<"Driver handicapped capabilites: "<<driverlist[i].GetDriverHand()<<endl;
				cout<<"Driver vehicle type: "<<driverlist[i].GetDriverVehType()<<endl;
				if (driverlist[i].GetDriverHand() == 1)
				{
					temp = "True";
				}
				else if (driverlist[i].GetDriverHand() == 0)
				{
					temp = "False";
				}
				cout<< "Driver handicapped status: "<<temp<<endl;
				cout<<"Driver rating: "<< driverlist[i].GetDriverRating ()<<endl;
				if (driverlist[i].GetDriverPets() == 1)
				{
					temp = "True";
				}
				else if (driverlist[i].GetDriverPets() == 0)
				{
					temp = "False";
				}
				cout<< "Driver pet status: "<< temp <<endl;
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
			
	//loads driverlist from file
	void DriverS::LoadDriver()
	{
		unsigned long int id=0;
		string name="";
		int vehcap=0;
		bool hand=0;
		string vehtype="";
		bool pets=0;
		string notes="";
		float rating=0;
		bool ava=0;
		bool open=0;
		int count=0;
		time_t start=0;
		Driver driver;
		ifstream fin;
		int Dcount=0;
		fin.open("driverS.dat");		
				
		driverlist.clear();
		
		if (!fin.is_open()) 
		{
			cout << "Error: Cannot open the file." << endl;
			return; // or handle the error as appropriate
		}
		
		fin >> Dcount;
		
		if (Dcount != 0)
		{
			for (int i = 0; i < Dcount; ++i)
			{
				fin >> id;
				fin.ignore();
				getline(fin, name, '\n');
				fin >> vehcap;
				fin >> hand;
				fin.ignore();
				getline(fin, vehtype, '\n');
				fin >>rating;
				fin>>ava;
				fin>>pets;
				fin.ignore();
				getline(fin, notes, '\n');
				fin >>open>>count >> start;
				Driver temp(id, name, vehcap, hand, vehtype, rating, ava, pets, notes, open, count, start, Dcount);
				driverlist.push_back(temp);
				DriverCount += 1;
			}
		}
		else
		{
			cout<<"No data in the driver file"<<endl;
		}
		fin.close();
	}
		
	//stores driverlist into file
	void DriverS::StoreDriver()
	{
		ofstream fout;
		fout.open("driverS.dat");
		
		Driver driver;
		
		if (!fout.is_open()) 
		{
			cout << "Error: Cannot open the file." << endl;
			return; // or handle the error as appropriate
		}
		else
		{
		
			fout << driverlist.size() << "\n";
			
			if (driverlist.size() != 0)
			{
				for (int i = 0; i < driverlist.size(); ++i)
				{
					fout<< driverlist[i].GetDriverID()<< "\n";
					fout<<driverlist[i].GetDriverName()<< "\n";
					fout << driverlist[i].GetDriverVehCap()<< "\n";
					fout<<driverlist[i].GetDriverHand()<< "\n";
					fout<<driverlist[i].GetDriverVehType()<< "\n";
					fout<<driverlist[i].GetDriverRating()<< "\n";
					fout<<driverlist[i].GetDriverAva()<< "\n";
					fout<<driverlist[i].GetDriverPets()<< "\n";
					fout<<driverlist[i].GetDriverNotes()<< "\n";
					fout<< driverlist[i].GetDriverOpen()<< "\n";
					fout<< driverlist[i].GetDriverCount()<< "\n";
					fout << driverlist[i].GetDriverAvailablityStart() << endl;
				}
			}
			else
			{
				cout<<"There is no driver data."<<endl;
			}
		}
		fout.close();
	}
		
	//prints driver by ID function
	void DriverS::PrintDriverByID(unsigned long int DRIVERID)
	{
		string temp;
		if (driverlist.size() != 0)
		{
			for (int i = 0; i < driverlist.size(); i++)
			{
				if (driverlist[i].GetDriverID() == DRIVERID)
				{
					cout<< "Driver id: "<<driverlist[i].GetDriverID()<<endl;
					cout<<"Driver name: "<<driverlist[i].GetDriverName()<<endl;
					cout<<"Driver vehicle capacity: "<<driverlist[i].GetDriverVehCap()<<endl;
					cout<<"Driver handicapped capabilites: "<<driverlist[i].GetDriverHand()<<endl;
					cout<<"Driver vehicle type: "<<driverlist[i].GetDriverVehType()<<endl;
					if (driverlist[i].GetDriverHand() == 1)
					{
						temp = "True";
					}
					else if (driverlist[i].GetDriverHand() == 0)
					{
						temp = "False";
					}
					cout<< "Driver handicapped status: "<<temp<<endl;
					cout<<"Driver rating: "<< driverlist[i].GetDriverRating()<<endl;
					if (driverlist[i].GetDriverPets() == 1)
					{
						temp = "True";
					}
					else if (driverlist[i].GetDriverPets() == 0)
					{
						temp = "False";
					}
					cout<< "Driver pet status: "<< temp <<endl;
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}
		
	//finds driver by ID function
	Driver DriverS::FindDriverByID(unsigned long int DRIVERID)
	{
		Driver temp;
		if (driverlist.size() != 0)
		{
			for (int i = 0; i < driverlist.size(); ++i)
			{
				if (DRIVERID == driverlist[i].GetDriverID())
				{
					temp = driverlist[i];
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
		return temp;
	}
	
	//finds driver by name functions
	Driver DriverS::FindDriverByName(string DRIVERNAME)
	{
		Driver temp;
		if (driverlist.size() != 0)
		{
			for (int i = 0; i< driverlist.size(); ++i)
			{
				if (driverlist[i].GetDriverName() == DRIVERNAME)
				{
						temp = driverlist[i];
				}
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
		return temp;
	}
	
	//gets driverlist
	vector<Driver>& DriverS::GetDriverList()
	{
		return driverlist;
	}