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
	
	void loggedIn(string date, vector<Accounts> &logins){
		if(status){
			cout<<"Status: Active"<<endl;
		}
		else{
			cout<<"Status: Inactive"<<endl;
			return;
		}
	}
	
	void openClose(vector<Accounts> &logins)
	{
		string input;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(Accounts &i: logins){
		if(i.getNumber() == input)
			{
				cout << "Which account type would you like to access?\n" << "1 for Checking, 2 for Savings, 3 for CD";
				cin >> sNum;
				for(;;)
				{
					switch(sNum)
					{
						case 1:
						{
							i.changeCheckingStat();
						}
						case 2:
						{
							i.changeSavingsStat();
						}
						case 3:
						{
							i.changeCDStat();
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
	}

	void changeCheckingStat(User i)
	{
		CheckingAccount c;
		c = i.getChecking();
		c.setStatus();
	}

	void changeSavingsStat(User i)
	{
		SavingsAccount s;
		s = i.getSavings();
		s.setStatus();
	}

	void changeCDStat(User i)
	{
		CD c;
		c = i.getCD();
		c.setStatus();
	}

	
	
	//Method to retrieve info from closed accounts
	
	//deposit and withdraw from a user account with permission
	
	//Search Account by name, number, and phone number
	
	
	
	void changeStatus(){
		if(s == "t"){
			s ="f";
		else{
			s="t";
		}
		createStatus(s);
	}
};
#endif
