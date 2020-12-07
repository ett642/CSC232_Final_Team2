#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "CD.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Accounts.h"
using namespace std;

//The User class is a child of the Accounts

class User : public Accounts
{
    private:
    	string phone;
	string address;
	CheckingAccount checking = CheckingAccount();
	SavingsAccount savings = SavingsAccount();
	CD cd = CD();


    public:

    	User(string num, string pass, string inName, string date, string inPhone, string inAddress) : Accounts(num, pass, inName, date) //Constructor for User Account class
    	{
        	phone = inPhone;
		address = inAddress;
		string temp = number+"transactions.txt";
		fstream file; file.open(temp);
		if(!file){
			ofstream createFile; createFile.open(temp);
		}
		file.close();
   	}

	void loggedIn(string date) //Options for the user after they log in
	{
		cout << "Successfully logged in! Last login was " << lastDate << endl;
		lastDate = date;

        	for(;;)
        	{
           		cout <<endl<< "What would you like to do\n" << "1 to access accounts\n" << "2 to access change password\n";
            		cout << "3 to access transactions\n" << "4 to exit\nChoose an option: ";
			int userInput;
			cin>>userInput;
            		switch(userInput)
            		{
               			case 1:
               			{
                    			accMenu(date);
					continue;
				}
				case 2:
				{
					changePass();
					continue;
				}
				case 3:
				{
					cout<<"Enter the date to search from (MM/DD/YYYY) : ";
					string inDate; cin>>inDate;
					transactionFile(inDate);
					continue;
				}
				case 4:
				{
					cout << "-------------------" << endl;
					cout << "Returning to Main Menu... " << endl;
					cout << "-------------------" << endl;
					return;
				}
				default: // error catching
				{ 
					cout << "Try another input!" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}

			}
		}
	}

	void accMenu(string date) // Menu for choosing to look at a checking, savings, or CD
	{
		while(true)
    		{
			int userInput;
			cout <<endl<< "What would you like to do\n" << "1 to access Checking\n" << "2 to access savings\n";
			cout << "3 to access CD\n" << "4 to exit\n";
			cin >> userInput;
			switch(userInput)
			{
				case 1:
				{
					checking.Menu(date,number);
					continue;
				}
				case 2:
				{
					savings.Menu(date, number);
					continue;
				}
				case 3:
				{
					cd.menu(date);
					continue;
				}
				case 4:
				{
					cout << "-------------------" << endl;
					cout << "Exiting Menu... " << endl;
					cout << "-------------------" << endl;
					return;
				}

				default: // error catching
				{ 
					cout << "Try another input!" << endl;
					cin.clear();
					cin.ignore();
					continue;
				}
			}
		}
	}
    
	void changePass() //Setter for the User password
	{
		string input,input2;
		cout << "Enter new password: ";
		cin >> input;
		cout << "Re-enter new password: ";
		cin >> input2;
		while(input != input2 )
		{
			cout << "Passwords do not match. Please Re-Enter new password. or enter 1 to restart password change.";
			cin >> input2;
			if(input2 == "1")
			{
				changePass();
				exit(0);
			}
		}
		password = input;
	}

	string printToFile () //Outputs a string that will be written to the file
	{
		string info;
		info = number+"*"+password+"*"+name+"*"+lastDate+"*"+phone+"*"+address+"*"+checking.printToFile()+"*"+savings.printToFile()+"*"+cd.printToFile();
		return info;
	}
	
	void getChecking() //Gets the Checking Account status and changes it
	{
		checking.setStatus();
	}

	void checkingMenu(string date) //Runs the Checking Account menu
	{
		checking.Menu(date, number);
	}
    
	void getSavings() //Gets the Savings Account status and changes it
	{
		savings.setStatus();
	}

	void savingsMenu(string date) //Runs the Savings Account Menu
	{
		savings.Menu(date, number);
	}

	void getCD() //Gets the CD status and changes it
	{
		cd.setStatus();
	}

	void cdMenu(string date) //Runs the CD menu
	{
		cd.menu(date);
	}
	
	void fileInput(string text) //Receives a string from the file and and sets teh info from that string
	{
		double bal; string stat; double interest; string term;
		bal = stod(text.substr(0, text.find("*")));
		text = text.substr(text.find("*")+1);
		
		stat = text.substr(0, text.find("*"));
		text = text.substr(text.find("*")+1);
		
		checking.fileInfo(bal, stat);
		
		bal = stod(text.substr(0, text.find("*")));
		text = text.substr(text.find("*")+1);
		
		stat = text.substr(0, text.find("*"));
		text = text.substr(text.find("*")+1);
		
		interest = stod(text.substr(0, text.find("*")));
		text = text.substr(text.find("*")+1);
		
		savings.fileInfo(bal, stat, interest);
		
		bal = stod(text.substr(0, text.find("*")));
		text = text.substr(text.find("*")+1);
		
		stat = text.substr(0, text.find("*"));
		text = text.substr(text.find("*")+1);
		
		term = text;
		
		cd.fileInfo(bal, stat, term);
	}
	
	void transactionFile(string date) //Receives a date from the user and reads dates info from dates later than the input from the user-specific transaction file
	{
		int month; int day; int year; int fileMonth; int fileDay; int fileYear; string text;
		getDate(date, &month, &day, &year);
		string temp = number+"transactions.txt";
		ifstream file; file.open(temp, fstream::in);
		while(getline(file, text))
		{
			string temp = text.substr(0, text.find("*"));
			getDate(temp, &fileMonth,&fileDay,&fileYear);
			if (fileYear > year)
            		{
				cout<<text<<endl;
            		}
			else if (fileYear == year)
			{
				if(fileMonth > month)
				{
					cout<<text<<endl;
				}
				else if(fileMonth == month)
				{
					if(fileDay >= day)
					{
						cout<<text<<endl;
					}
				}
			}
		}
		file.close();
	}
	
	void getDate(string date, int *month, int *day, int *year) //Takes the inputted date in a MM/DD/YYYY format and converts them to integers
	{
		*month = stoi(date.substr(0,date.find("/")));
		date = date.substr(date.find("/")+1);
		*day = stoi(date.substr(0,date.find("/")));
		date = date.substr(date.find("/")+1);
		*year = stoi(date);
	}
	
	void changePhone(string inPhone) //Setter for phone number
	{
		phone = inPhone;
	}

	void changeAddress(string inAddress) //Setter for address
	{
		address = inAddress;
	}

};
#endif
