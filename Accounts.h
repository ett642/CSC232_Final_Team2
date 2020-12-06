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
	
	virtual void loggedIn(string date, vector<Accounts> &logins){
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
		CheckingAccount temp = CheckingAccount();
		return temp;
	}

	virtual SavingsAccount getSavings()
    {
        SavingsAccount temp = SavingsAccount();
		return temp;
    }

    virtual CD getCD()
    {
        CD temp = CD();
		return temp;
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
