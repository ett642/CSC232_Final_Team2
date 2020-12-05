#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <iostream>
#include <string>
#include "CD.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

class Accounts{
protected:
	string number;
	string password;
	string name;
	string lastDate;
	
public:
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

	string getName()
	{
		return name;
	}

	virtual CheckingAccount getChecking()
	{
		
	}

	virtual SavingsAccount getSavings()
    {
        
    }

    virtual CD getCD()
    {
        
    }

	virtual void changeCheckingStat()
    {
        
    }

    virtual void changeSavingsStat()
    {
		
    }
    
    virtual void changeCDStat()
    {

    }
	
	virtual string getPhone()
	{

	}

	virtual void changeStatus()
	{
		
	}
};
#endif
