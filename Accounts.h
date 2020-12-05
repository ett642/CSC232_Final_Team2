#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <iostream>
#include <string>
using namespace std;

class Accounts{
protected:
	string password;
	string name;
	
public:
	string number;
	string lastDate;
	Accounts(string num, string pass, string inName, string date){
		number = num;
		password = pass;
		name = inName;
		lastDate = date;
		
	}
	
	virtual void loggedIn(string date){
		cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
		lastDate = date;
	}
	
	
	string getNumber(){
		return number;
	}
	
	string getPassword(){
		return password;
	}
	
	virtual string printToFile(){
		return "";
	}
	vitual void changeCheckingStat(){
		
	}
	virtual void changeSavingsStat(){
	
	}
	virtual void changeCDStat(){
		
	}
};
#endif
