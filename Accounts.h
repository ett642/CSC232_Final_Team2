#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <iostream>
#include <string>

class Accounts.h{
private:
	int number;
	string password;
	string name;
	string lastDate;
	
public:
	Accounts(int num, string pass, string inName, string date){
		number = num;
		password = pass;
		name = inName;
		lastDate = date;
	}
	
	virtual void login(string date){
		lastDate = date;
	}
	};
#endif
