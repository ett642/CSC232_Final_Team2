#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <string>
#include <iostream>
#include <fstream>
#include "AbAccount.h"
#include <limits>
using namespace std;

//SavingsAccount represents a functioning savings account
// SavingsAccount class is a child class of parent
// AbAccount class

class SavingsAccount : public AbAccount {
    public:
    bool flag;
   // Default constructor
   SavingsAccount() : AbAccount()
   {
      flag = true;
   }
   // 2nd Constructor
   SavingsAccount (string num, string date, double balance, bool status, bool flag): AbAccount(num, date, balance,status)
   { 
      flag = true;
   }
   
   //function for logged in menu
   void Menu(string date)
   {
	   if(!status){
		cout<<"You don't have a savings account! Contact a Bank Official to open one.\n";
		return;
	}
	lastDate=date;
   for(;;) { // menu for  loop
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
                          deposit(depositAmt, date);
                          //deposit amount using depositAmt?
                          
                          cout << "-------------------" << endl;
                          cout << "Your new balance is: " << balance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          char enter = cin.get(); 
                          cin.ignore();
                          continue;
                       }
                       case 2: 
                       {
                          cout << "-------------------" << endl;
                          cout << "How much would you like to Withdraw?" << endl;
                          cout << "-------------------" << endl;
                          long double withdrawAmt;
                          cin >> withdrawAmt;
                          withdraw(withdrawAmt,date);
                          
                          //withdraw amount using withdrawAmt?
                          
                          cout << "-------------------" << endl;
                          cout << "Your new balance is: " << balance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          char enter = cin.get(); 
                          cin.ignore();
                          continue;
                       }
                       case 3:
                       {
                          cout << "-------------------" << endl;
                          cout << "Your Current Balance is: " << balance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          char enter = cin.get(); 
                          cin.ignore();
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
                       
                          

                       
                       



   //function to deposit money
   void deposit(double amount, string number,string date) 
   {
      if(amount > 0.00) //if the amount deposited is more than 0 
      {
         balance += amount;//successfully deposit
		 fstream file; file.open(number+"transactions.txt");
		 file<<date+"*Deposited "<<amount<<" into savings."<<endl;
		 file.close();
      }
      else //if the deposit is not a positive amount it will not deposit
      {
         cout << "Invalid deposit" << endl;//lets user know amount is invalid for deposit
         cin.clear();
         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         for(;;) 
         {
            cout << "Please enter a valid deposit: "<< endl; //prompts user to enter a valid deposit
            double amt;
            cin >> amt;
            deposit(amt);
            break;
         }
      }
      if(balance >= 0.0) //if the balance is greater than $0 the status will remain open 
      {
         flag = true;
      }
        
   }
   
   
   void withdraw(double amount, string number, string date) //function to withdraw money
   {
       if(flag == false) 
        { // deny the withdrawl
            cout << "You may not withdraw, your account balance is: $" << balance << endl;
            cout << "You must raise your account balance above $0 to make a withdraw." << endl;
        }
        else if (flag == true) 
        { // do the withdrawl from the balance
            if(balance >= amount) 
            {
                balance -= amount;
				fstream file; file.open(number+"transactions.txt");
				file<<date+"*Withdrew "<<amount<<" from savings."<<endl;
				file.close();
            }
            else 
            {
                cout << "Invalid funds " << endl;
            }
            if(balance < 0.0)// if the balance falls below $0 account becomes inactive 
            {
                cout << "Warning! You cannot withdraw your account has fallen below $0.00. " << endl;
                cout << "You must deposit more money before you can make another withdraw." << endl;
                flag = false;
            }
        }
    }

string changeStatus(){
		if(status){
			return "t";
		}
		return "f";
	}

	string printToFile ()
	{
		string info;
		info = to_string(balance)+"*"+changeStatus()+"*"+to_string(interestRate);
		return info;
	}
	
	void fileInfo(double bal, string stat, double interest){
	   balance = bal;
		interestRate = interest;
		if(stat == "t")
			status = true;
		else
			status = false; 
   }
};
#endif
