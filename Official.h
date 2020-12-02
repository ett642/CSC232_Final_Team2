#ifndef OFFICIAL_H
#define OFFICIAL_H
#include <iostream>
#include <string>
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
	
	void loggedIn(string date){
		if(status){
			cout<<"Status: Active"<<endl;
		}
		else{
			cout<<"Status: Inactive"<<endl;
			return;
		}
	}
	
	//Method to open and close bank accounts
	
	//Method to retrieve info from closed accounts
	
	//deposit and withdraw from a user account with permission
	
	//Search Account by name, number, and phone number
};
#endif
