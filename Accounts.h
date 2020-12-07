#ifndef ACCOUNTS_H
#define ACCOUNTS_H
#include <iostream>
#include <string>
#include "CD.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

//Accounts is the parent class of Official, User, and Admin. It details user accounts and gives functions for them to use.

class Accounts{
protected:
	string number;
	string password;
	string name;
	string lastDate;
	
public:
	Accounts(string num, string pass, string inName, string date){ //Constructor for Accounts
		number = num;
		password = pass;
		name = inName;
		lastDate = date;
	}
	
	virtual void loggedIn(string date, vector<Accounts> &logins){ //Virtual function for options once the Account has logged in
	}
	
	
	string getNumber(){ //Getter for account number
		return number;
	}
	
	string getPassword(){ //Getter for account password
		return password;
	}

	string getName() //Getter for name
	{
		return name;
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
		return "";
	}

	virtual void changeStatus()
	{
		
	}
	
	virtual string printToFile(){
		return "";
	}
   
   void changeName(string inName){
   name = inName;
   }
   
   void changePass(string pass){
   password = pass;  
   }
   
   virtual void changePhone(string phone){
   
   }
   
   virtual void changeAddress(string address){
  
   }
   
   
   
};
#endif
