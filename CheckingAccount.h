#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
#include "AbAccount.h"
#include <limits>
using namespace std;

class CheckingAccount : public AbAccount 
{
   protected:
   bool flag;
   
   // Default constructor
   CheckingAccount() : AbAccount()
   {
      flag = false;
   }
    
   CheckingAccount (string num, string date, double balance, bool status, bool flag): AbAccount(num, date, balance,status)
   {
      flag = false;
   }
   
   //function for logged in menu
   void loggedIn(string date)
   {
	cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
	lastDate = date;
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
                    switch(userInput) {
                       case 1: 
                       {
                          cout << "-------------------" << endl;
                          cout << "How much would you like to deposit?" << endl;
                          cout << "-------------------" << endl;
                          long double depositAmt;
                          cin >> depositAmt;
                          deposit(depositAmt);
                          
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
                          withdraw(withdrawAmt);
                          
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

    void deposit(long double amount) 
    {
        if(amount > 0.00) 
        {
            balance += amount; // deposit the amount
        }
        else 
        {
            cout << "Invalid deposit" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(;;) 
            { // error checking
                cout << "Please enter a valid deposit: " << endl;
                double amt;
                cin >> amt;
                deposit(amt);
                break;
             }
         }    
     }
     
    void withdraw(long double amount) 
    {
       if(amount < 0.00) {
          cout << "Invalid withdraw" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(;;) { // error checking
                cout << "Please enter a valid withdraw: " << endl;
                double amt;
                cin >> amt;
                withdraw(amt);
                break;
            }
       }
       if(balance >= amount) 
       {
         balance -= amount; // subtract the amount if it's in the balance
       }
       else 
       {
         cout << "Invalid funds " << endl;
         if(balance < 0.00) 
         { // if account balance is below 0 let the user know and do not allow withdraw
            cout << "Your balance fell below $0.";
         }
       }
    } 
};
#endif
