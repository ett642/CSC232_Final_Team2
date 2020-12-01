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
	virtual void login(string date){
		lastDate = date;
	}
	};
#endif