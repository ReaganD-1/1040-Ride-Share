#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "passenger.h"
#include "passengerS.h"

using namespace std;

	//initalizes global variables
	unsigned long int Paid = 100000;
	unsigned int PassCount = 0;

	//adds a passengerS
	void PassengerS::AddPass()
	{
		//function variables
		string name;
		string payment;
		bool hand;
		float rating;
		bool pet;
		unsigned long int temppid;
		
		Passenger pass;
		
		//creates passenger id
		Paid = Paid + PassCount;
    
		//creates passenger 
		cout << "Enter new passenger name: "<<endl;
		cin.ignore();
		getline(cin, name);
		
		do
		{
		cout<<"Enter new passenger payment method (cash, credit, debit): "<<endl;
		getline(cin,payment);
		}while(payment !="cash" && payment != "Cash" && payment != "credit" && payment != "Credit" && payment != "debit" && payment != "Debit");
		
		cout<<"Enter new passenger handicapped status (1 for yes or 0 for no): "<<endl;
		cin >> hand;
		cout<<"Enter new passenger default rating: "<<endl;
		cin >> rating;
		cout<< "Enter new passenger pet status (1 for yes or 0 for no): "<<endl;
		cin >> pet;
		cout<<endl;
	
		//adds the passenger to passengerlist
		Passenger temp(Paid,name, payment, hand, rating,pet,PassCount);
    
		passengerlist.push_back(temp);
		
		pass.SetPassIncCount();
		
		PrintPassByID(Paid);

		PassCount += 1;

	}
	
	//deletes passenger from passengerlist
	void PassengerS::DeletePass(unsigned long int PASSID)
	{
		Passenger pass;
		for (int i = 0; i < passengerlist.size(); i++)
		{
			if (passengerlist[i].GetPassID() == PASSID)
			{
				passengerlist.erase(passengerlist.begin() + i);
			}
		}
		
		pass.SetPassDeCount();
	}

	//edits passenger
	void PassengerS::EditPass()
	{
		unsigned long int ID;
		
		
		char choice;
		string name;
		string payment;
		bool hand;
		float rating;
		bool pet;
		Passenger pass;
		
		cout<<"Enter the ID of the passenger you want to edit: "<<endl;
		cin>>ID;
		
		for (int i = 0; i < passengerlist.size(); i++)
		{
			if(ID == passengerlist[i].GetPassID())
			{
		
		
				do{
					cout<<"Edit Menu: "<<endl;
					cout<<"n - Edit Name"<<endl;
					cout<<"p - Edit Payment Method"<<endl;
					cout<<"h - Edit Handicapped Status"<<endl;
					cout<<"r - Edit Default Rating"<<endl;
					cout<<"a - Edit Pet Status"<<endl;
					cout<<"q - Quit"<<endl;
					cout<<"Please enter your choice: "<<endl;
					cin >> choice;
					cout<<endl<<endl;
				
					switch (choice)
					{
						case 'n':
						cout<<"Please enter new name:"<<endl;
						cin.ignore();
						getline(cin,name);
						passengerlist[i].SetPassName(name);
						cout<<endl;
						break;
					
						case 'p':
						do
						{
							cout<<"Please enter new payment method (cash, credit, debit):"<<endl;
							cin.ignore();
							getline(cin,payment);
						}while(payment !="cash" && payment != "Cash" && payment != "credit" && payment != "Credit" && payment != "debit" && payment != "Debit");

						passengerlist[i].SetPassPayment(payment);
						cout<<endl;
						break;
					
						case 'h':
						cout<<"Please enter new handicapped status:"<<endl;
						cin>> hand;
						passengerlist[i].SetPassHand(hand);
						cout<<endl;
						break;
					
						case 'r':
						cout<<"Please enter new default rating:"<<endl;
						cin>> rating;
						passengerlist[i].SetPassDeRating(rating);
						cout<<endl;
						break;
					
						case 'a':
						cout<<"Please enter new pet status:"<<endl;
						cin>> pet;
						passengerlist[i].SetPassPet(pet);
						cout<<endl;
						break;
					
						case 'q':
						cout<<"goodbye"<<endl;
						return;
						break;
					
						default:
						cout<<"Please enter vaild choice."<<endl;
						break;
					}
				}while(choice != 'q');
			}
		}
	}
	
	//clear passengerlist function
	void PassengerS::CleanPass()
	{
		 passengerlist.clear();
	}
	
	//prints all passenger name function
	void PassengerS::PrintPassAllName()
	{
		Passenger pass;
		cout << "Passengers names: " <<endl;
		if (passengerlist.size() != 0)
		{
			for (int i = 0; i < passengerlist.size(); i++)
			{
				cout<< passengerlist[i].GetPassName() <<endl;
			}
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
		cout<<endl;
	}	
	
	//prints all passenger function
	void PassengerS::PrintPassAllInfo()
	{
		if (passengerlist.size() > 0)
		{
			string temp;
			for (int i = 0; i < passengerlist.size(); i++)
			{
				cout << "Passenger id: " << passengerlist[i].GetPassID() <<endl;
				cout << "Passenger name: " << passengerlist[i].GetPassName() <<endl;
				cout<< "Passenger payment method: " << passengerlist[i].GetPassPayment() <<endl;
				if (passengerlist[i].GetPassHand() == 1)
				{
					temp = "True";
				}
				else if(passengerlist[i].GetPassHand() == 0)
				{
					temp = "False";
				}
				cout<< "Passenger handicapped status: "<<temp<<endl;
				cout<<"Passenger rating: "<< passengerlist[i].GetPassDeRating ()<<endl;
				if (passengerlist[i].GetPassPet() == 1)
				{
					temp = "True";
				}
				else if (passengerlist[i].GetPassPet() == 0)
				{
					temp = "False";
				}
				cout<< "Passenger pet status: "<< temp <<endl;
			}
		}			
		else
		{
			cout<<"There is no data."<<endl;
		}
	}

	//loads passengerlist from file
	void PassengerS::LoadPass()
	{
		ifstream fin;
		unsigned long int id=0;
		string name = "";
		string payment = "";
		bool hand = 0;
		float rating = 0;
		Passenger pass;
		bool pet = 0;
		int Pcount =0;	
		fin.open("passengerS.dat");
		
		passengerlist.clear();
		
		if (!fin.is_open()) 
		{
			cout << "Error: Cannot open the file." << endl;
			return; // or handle the error as appropriate
		}
		else
		{
			fin >> Pcount;			
			if (Pcount > 0)
			{
				for (int i=0; i < Pcount; i++)
				{
					fin >> id;
					fin.ignore();
					getline(fin, name, '\n');
					getline(fin, payment, '\n');
					fin>>hand;
					fin >> rating;
					fin >> pet;
					Passenger temp(id,name,payment,hand, rating, pet, Pcount);
					passengerlist.push_back(temp);
					PassCount += 1;
				}
			}
			else
			{
				cout<<"No data in the passenger file"<<endl;
			}
		}
		fin.close();
	}
	
	//stores passengerlist into file
	void PassengerS::StorePass()
	{
		ofstream fout;
		fout.open("passengerS.dat");
		
		Passenger pass;
		
		if (!fout.is_open()) 
		{
			cout << "Error: Cannot open the file." << endl;
			return; // or handle the error as appropriate
		}
			fout <<  passengerlist.size() << "\n";
			
			if (passengerlist.size() != 0)
			{
				for (int i =0; i < passengerlist.size(); ++i)
				{
					fout << passengerlist[i].GetPassID() << endl;
					fout<<  passengerlist[i].GetPassName()<< endl;
					fout << passengerlist[i].GetPassPayment()<< endl;
					fout <<  passengerlist[i].GetPassHand()<< endl;
					fout <<  passengerlist[i].GetPassDeRating()<< endl;
					fout <<  passengerlist[i].GetPassPet() << endl;
				}
			}
			else
			{
				cout<<"There is no passenger data."<<endl;
			}
		fout.close();
	}	
	
	//print passenger by ID function
	void PassengerS::PrintPassByID(unsigned long int PASSID)
	{
		string temp;
		if (passengerlist.size() != 0)
		{
			for(int i =0; i < passengerlist.size(); i++)
			{
				if (passengerlist[i].GetPassID() == PASSID)
				{
					cout << "Passenger id: " << passengerlist[i].GetPassID() <<endl;
					cout << "Passenger name: " << passengerlist[i].GetPassName() <<endl;
					cout<< "Passenger payment method: " << passengerlist[i].GetPassPayment() <<endl;
					if (passengerlist[i].GetPassHand() == 1)
					{
						temp = "True";
					}
					else if (passengerlist[i].GetPassHand() == 0)
					{
						temp = "False";
					}
					cout<< "Passenger handicapped status: "<<temp<<endl;
					cout<<"Passenger rating: "<< passengerlist[i].GetPassDeRating ()<<endl;
					if (passengerlist[i].GetPassPet() == 1)
					{
						temp = "True";
					}
					else if (passengerlist[i].GetPassPet() == 0)
					{
						temp = "False";
					}
					cout<< "Passenger pet status: "<< temp <<endl;
					return;
				}
			}
			cout<<"Passenger with ID "<<PASSID<< " not found." <<endl;
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
	}	
	
	//find passenger by ID function
	Passenger PassengerS::FindPassByID(unsigned long int PASSID)
	{
		Passenger temp;
		if (passengerlist.size() != 0)
		{
			for (int i =0; i < passengerlist.size(); i++)
			{
				if (passengerlist[i].GetPassID() == PASSID)
				{
					temp = passengerlist[i];
				}
				cout<<"Passenger with ID "<<PASSID<< " not found." <<endl;
			}	
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
  
		return temp;
	}
	
	//find passenger by name function
	Passenger PassengerS::FindPassByName(string PASSNAME)
	{
		Passenger temp;
		if (passengerlist.size() != 0)
		{
			for (int i =0;i < passengerlist.size(); i++)
			{
				if (passengerlist[i].GetPassName() == PASSNAME)
				{
					temp = passengerlist[i];
				}
				
			}	
		}
		else
		{
			cout<<"There is no data."<<endl;
		}
  
		return temp;
	}
		
	//get passengerlist
	vector<Passenger>& PassengerS::GetPassengerList()
	{
		return passengerlist;
	}