#ifndef OFFICIAL_H
#define OFFICIAL_H
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Accounts.h"
using namespace std;

class Official : public Accounts{
private:
	string stat;
	bool status;
	
public:
	Official(string num, string pass, string inName, string date, string s):Accounts(num,pass,inName,date){
		stat = s;
		createStatus(stat);
	}
	
	void createStatus(string s){
		if(s=="t")
			status = true;
		else
			status = false;
	}
	
	void loggedIn(string date, vector<User> &user){
		lastDate = date;
		if(status){
			cout<<"Status: Active"<<endl;
			cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
			lastDate = date;
			while(true){
				cout<<endl<<"[1] Open/close accounts\n[2] Deposit/Withdraw from account\n[3] Search account\n[4] Exit\nChoose an option: ";
				int input;
				cin>>input;
				switch(input){
					case 1:
					{
						openClose(user);
						continue;
					}
					case 2:
					{
						accountDeposit(user);
						continue;
					}
					case 3:
					{
						searchAccount(user);
						continue;
					}
					case 4:
					{
						return;
					}
					default:
					{
						cout << "Try another input!" << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
				}
			}
		}
		else{
			cout<<"Status: Inactive"<<endl;
			cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
			lastDate = date;
			return;
		}
	}
	
	void openClose(vector<User> &user)
	{
		string input;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(User &i: user)
		{
			if(i.getNumber() == input)
			{
				
				for(;;)
				{
					cout <<endl<< "Which account type would you like to access?\n" << "1 for Checking\n" << "2 for Savings\n";
					cout <<"3 for CD\n" << "4 to exit\n";
					cin >> sNum;
					switch(sNum)
					{
						case 1:
						{
							i.getChecking();
							continue;
						}
						case 2:
						{
							i.getSavings();
							continue;
						}
						case 3:
						{
							i.getCD();
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
		}
		cout << "Customer not found.\n";
		
	}

	void accountDeposit(vector<User> &user)
	{
		string input;
		CheckingAccount c;
		SavingsAccount s;
		CD cd;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(User &i: user)
		{
			
			if((i.getNumber() == input))
			{
				cout << "Allow the Customer to enter their password.\n";
				cin >> input;
				if(i.getPassword() == input)
				{
					for(;;)
					{
						cout <<endl <<"Which account type would you like to access?\n" << "1 for Checking\n" << "2 for Savings\n";
						cout <<"3 for CD\n" << "4 to exit\n";
						cin >> sNum;
						switch(sNum)
						{
							case 1:
							{
								i.checkingMenu(lastDate);
								continue;
							}
							case 2:
							{
								i.savingsMenu(lastDate);
								continue;
							}
							case 3:
							{
								i.cdMenu(lastDate);
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
				else
				{
					cout << "Password incorrect.\n";
					return;
				}
				
			}
		}
		cout << "Customer not found.\n";
		
	}

	void searchAccount(vector<User> &user)
	{
		string input;
		CheckingAccount c;
		SavingsAccount s;
		CD cd;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(User &i: user)
		{
			
			if((i.getNumber() == input) || (i.getName() == input) || (i.getPhone() == input))
			{
				cout << i.getNumber() << " " << i.getName() << " " << i.getPhone() << endl;
			}
		}
	}

	void changeStatus(){
		if(stat == "t"){
			stat ="f";
		}
		else
      {
			stat="t";
		}
		createStatus(stat);
	}
	
	string printToFile(){
		string info;
		info = number+"*"+password+"*"+name+"*"+lastDate+"*"+stat;\
		return info;
	}

	//Method to retrieve info from closed accounts
};
#endif
