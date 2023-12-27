#include <iostream>
#include <vector>
#include <string>
#include "driver.h"
#include "passenger.h"
#include "ride.h"
#include "driverS.h"
#include "passengerS.h"
#include "rideS.h"
using namespace std;

int main()
{
	//main functions
	char choice;
	char pchoice;
	char dchoice;
	char rchoice;
	
	unsigned long int pid;
	unsigned long int did;
	unsigned long int rid;
	
	PassengerS pass;
	DriverS driver;
	RideS ride;

	vector<Driver>&driverlist = driver.GetDriverList();
	vector<Passenger>&passengerlist = pass.GetPassengerList();
	
	//loads lists from files
	pass.LoadPass();
	driver.LoadDriver();
	ride.LoadRide();

	//opens scrappy rides menu for user use
	cout<< "Welcome to Scrappy Rides!"<<endl;
	
	do
	{
		cout<< "Menu Types:"<<endl;
		cout<< "p - Passenger Menu "<<endl;
		cout<< "d - Driver Menu "<<endl;
		cout << "r - Ride Menu "<<endl;
		cout << "q - Quit" <<endl;
		cout<< "Please enter the menu you want to see: "<<endl;
		cin >> choice;
		cout<< endl<<endl;
		
		switch(choice) 
		{
			case 'p':
				do
				{
					//passenger menu and options
					cout<< "Welcome to Passenger Menu"<<endl;
					cout<< "a - Add Passenger: "<<endl;
					cout<< "e - Edit Passenger: "<<endl;
					cout<< "d- Delete Passenger: "<<endl;
					cout<< "p - Print All Passenger Information: "<<endl;
					cout<< "n - Print All Passenger Names: "<<endl;
					cout<< "i - Print Passenger's Information by ID: "<<endl;
					cout<< "q - Quit"<<endl;
					cout<< "Please enter menu choice: "<<endl;
					cin >> pchoice;
					cout<< endl<<endl;
					
					switch (pchoice)
					{
						case 'a':
						pass.AddPass();
						cout<<endl;
						break;
						
						case 'e':
						pass.EditPass();
						cout<<endl;
						break;
						
						case 'd':
						cout<<"Please enter passenger ID: "<<endl;
						cin >> pid;
						pass.DeletePass(pid);
						cout<<endl;
						break;
						
						case 'p':
						pass.PrintPassAllInfo();
						cout<<endl;
						break;
						
						case 'n':
						pass.PrintPassAllName();
						cout<<endl;
						break;
						
						case 'i':
						cout<<"Please enter passenger ID: "<<endl;
						cin >> pid;
						pass.PrintPassByID(pid);
						cout<<endl;
						break;
						
						case 'q':
						cout<<"Goodbye."<<endl;
						break;
						
						default:
						cout<< "Please enter vaild menu choice."<<endl;
						break;
					}
				}while(pchoice != 'q');
			
			break;
			
			case 'd': 
			do
				{
					//driver menu and options
					cout<< "Welcome to Driver Menu"<<endl;
					cout<< "a - Add Driver: "<<endl;
					cout<< "e - Edit Driver: "<<endl;
					cout<< "d- Delete Driver: "<<endl;
					cout<< "p - Print All Driver Information: "<<endl;
					cout<< "n - Print All Driver Names: "<<endl;
					cout<< "i - Print Driver's Information by ID: "<<endl;
					cout<< "q - Quit"<<endl;
					cout<< "Please enter menu choice: "<<endl;
					cin >> dchoice;
					cout<< endl <<endl;
					
					switch (dchoice)
					{
						case 'a':
						driver.AddDriver();
						cout<<endl;
						break;
						
						case 'e':
						driver.EditDriver();
						cout<<endl;
						break;
						
						case 'd':
						cout<<"Please enter driver ID:"<<endl;
						cin >> did;
						driver.DeleteDriver(did);
						cout<<endl;
						break;
						
						case 'p':
						driver.PrintDriverAllInfo();
						cout<<endl;
						break;
						
						case 'n':
						driver.PrintDriverAllName();
						cout<<endl;
						break;
						
						case 'i':
						cout<<"Please enter driver ID:"<<endl;
						cin >> did;
						driver.PrintDriverByID(did);
						cout<<endl;
						break;
						
						case 'q':
						cout<<"Goodbye."<<endl;
						break;
						
						default:
						cout<< "Please enter vaild menu choice."<<endl;
						break;
					}
				}while(dchoice != 'q');
			break;
			
			case 'r':
			do
			{
				//ride menu and options
				cout<<"Welcome to Ride Menu:"<<endl;
				cout<< "a- Add Ride"<<endl;
				cout<<"e - Edit Ride"<<endl;
				cout<<"d - Delete Ride"<<endl;
				cout<<"p - Print All Rides"<<endl;
				cout<< "i - Print a Ride by ID"<<endl;
				cout<<"c - Print All Active Rides"<<endl;
				cout<<"o - Print All Completed Rides"<<endl;
				cout<<"n - Print All Canceled Rides"<<endl;
				cout<<"s - Print All Rides by Passenger ID"<<endl;
				cout<<"r - Print All Rides by Driver ID"<<endl;
				cout<<"q - Quit"<<endl;
				cout<<"Please enter menu choice:"<<endl;
				cin >> rchoice;
				cout<<endl<<endl;
				
				switch(rchoice)
				{
					case 'a':
					ride.AddRide(driverlist, passengerlist);
					cout<<endl;
					break;
					
					case 'e':
					ride.EditRide();
					cout<<endl;
					break;
					
					case 'd':
					cout<<"Please enter ride ID:"<<endl;
					cin >> rid;
					ride.DeleteRide(rid);
					cout<<endl;
					break;
					
					case 'p':
					ride.PrintAllRide();
					cout<<endl;
					break;
					
					case 'i':
					cout<<"Please enter ride ID:"<<endl;
					cin>>rid;
					ride.PrintRideByID(rid);
					cout<<endl;
					break;
					
					case 'c':
					ride.PrintAllActive(driverlist, passengerlist);
					cout<<endl;
					break;
					
					case 'o':
					ride.PrintAllPast(driverlist, passengerlist);
					cout<<endl;
					break;
					
					case 'n':
					ride.PrintAllCancelled(driverlist, passengerlist);
					cout<<endl;
					break;
					
					case 's':
					cout<<"Please enter passenger ID:"<<endl;
					cin >> pid;
					ride.PrintRidesForPassenger(pid);
					cout<<endl;
					break;
					
					case 'r':
					cout<<"Please enter driver ID:"<<endl;
					cin>>did;
					ride.PrintRideForDriver(did);
					cout<<endl;
					break;
					
					case 'q':
					cout<<"Goodbye"<<endl;
					break;
					
					default:
					cout<<"Please enter vaild menu option."<<endl;
					break;
				}

			}while(rchoice != 'q');
			break;
			
			case 'q':
			cout<<"Goodbye."<<endl;
			break;
			
			default:
				cout<< "Please enter vaild menu choice."<<endl;
			break;
		}
	}while(choice != 'q');
	
	//store files from lists
	ride.StoreRide();
	driver.StoreDriver();
	pass.StorePass();
	
	//clear lists
	ride.CleanRide();
	pass.CleanPass();
	driver.CleanDriver();
	
return 0;
}