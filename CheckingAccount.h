#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
#include <fstream>
#include "AbAccount.h"
#include <limits>
using namespace std;

//Child class of AbAccounts, used to manage user checking accounts 
class CheckingAccount : public AbAccount 
{
	protected:
   		bool flag;
	public:
   
		// Default constructor
		CheckingAccount() : AbAccount()
		{
		flag = false;
		}
		
    		//Constructor
		CheckingAccount (string num, string date, double balance, bool status, bool flag): AbAccount(num, date, balance,status)
		{
		flag = false;
		}
   
		//function for logged in menu
		void Menu(string date, string number)
		{
			if(!status)
			{
				cout<<"You don't have a checking account! Contact a Bank Official to open one.\n";
				return;
			}
			lastDate = date;
			while(true) 
			{ // menu for  loop
				cout << "-------------------" << endl;
				cout << "What would you like to do? \n" << endl;
				cout << "[1] Deposit Funds" << endl;
				cout << "[2] Withdraw Funds" << endl;
				cout << "[3] Check Account Balance" << endl;
				cout << "[4] Return to Main Menu" << endl;
				cout << "-------------------" << endl;
				int userInput;
				cin >> userInput;
				switch(userInput) 
				{
					case 1: 
					{
					  cout << "-------------------" << endl;
					  cout << "How much would you like to deposit?" << endl;
					  cout << "-------------------" << endl;
					  long double depositAmt;
					  cin >> depositAmt;
					  deposit(depositAmt, number, date);

					  //deposit amount using depositAmt?

					  cout << "-------------------" << endl;
					  cout << "Your new balance is: " << balance << endl;
					  cout << "-------------------" << endl;
					  continue;
					}
					case 2: 
					{
					  cout << "-------------------" << endl;
					  cout << "How much would you like to Withdraw?" << endl;
					  cout << "-------------------" << endl;
					  long double withdrawAmt;
					  cin >> withdrawAmt;
					  withdraw(withdrawAmt, number, date);

					  //withdraw amount using withdrawAmt?

					  cout << "-------------------" << endl;
					  cout << "Your new balance is: " << balance << endl;
					  cout << "-------------------" << endl;
					  continue;
					}
					case 3:
					{
					  cout << "-------------------" << endl;
					  cout << "Your Current Balance is: " << balance << endl;
					  cout << "-------------------" << endl;
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

		//Deposits amount specified into account
		void deposit(long double amount, string number, string date) 
		{
			if(amount > 0.00) 
			{
				balance += amount; // deposit the amount
				fstream file; file.open(number+"transactions.txt", fstream::app);
				file<<date+"*Deposited "<<amount<<" into checking"<<endl;
				file.close();
			}
			else 
			{
				cout << "Invalid deposit" << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				for(;;) 
				{// error checking
					cout << "Please enter a valid deposit: " << endl;
					double amt;
					cin >> amt;
					deposit(amt, number, date);
					break;
			     	}
			}    
		}
     		
		//Withdraws amount specified from account
		void withdraw(long double amount, string number, string date) 
		{
			if(amount < 0.00) 
			{
			  	cout << "Invalid withdraw" << endl;
				cin.clear();	
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				for(;;) 
				{ // error checking
					cout << "Please enter a valid withdraw: " << endl;
					double amt;
					cin >> amt;
					withdraw(amt, number, date);
					break;
			    	}
			}
			if(balance >= amount) 
			{
				balance -= amount; // subtract the amount if it's in the balance
				 fstream file; file.open(number+"transactions.txt", fstream::app);
				 file<<date+"*Withdrew "<<amount<<" from checking"<<endl;
				 file.close();
			}
			else 
			{
				cout << "Invalid funds " << endl;
				if(balance < 0.00) 
				{ // if account balance is below 0 let the user know and do not allow withdraw
					cout << "Your balance fell below $0.";
				}
			}
		}
		
		//Returns status string for appending to file
		string changeStatus()
		{
			if(status)
			{
				return"t";
			}
			else
			{
				return"f";
			}
		}
		
		//Returns info for appending to file
		string printToFile ()
		{
			string info;
			info = to_string(balance)+"*"+changeStatus();
			return info;
		}
   		
		// Recieves info from file and updates account info
		void fileInfo(double bal, string stat)
		{
			balance = bal;
			if(stat == "t")
				status = true;
			else
				status = false; 
		}
   		
		//Changes account status to open or closed
		void setStatus()
		{
			while(true)
			{
				int input;
				cout <<endl<<"1 to activate account.\n" << "2 to deactivate account.\n";
				cin >> input;
				switch(input)
				{
					case 1:
					{
						status = true;
						cout<<"Account status changed to true!\n\n";
						return;
					}
					case 2:
					{
						status = false;
						cout<<"Account status changed to false!\n\n";
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
   
};
#endif
