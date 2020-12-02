#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include <string>
#include <iostream>
#include "AbAccount.h"
#include <limits>
using namespace std;

//SavingsAccount represents a functioning savings account
// SavingsAccount class is a child class of parent
// AbAccount class

class SavingsAccount : public AbAccount {
   protected:
      bool flag;
   public:
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
   //function to display menu
   //void display
   //function to deposit money
   void deposit(double amount) 
   {
      if(amount > 0.00) //if the amount deposited is more than 0 
      {
         balance += amount;//successfully deposit
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
   void withdraw(double amount) //function to withdraw money
   {
       if(flag == false) 
        { // deny the withdraw
            cout << "You may not withdraw, your account balance is: $" << balance << endl;
            cout << "You must raise your account balance above $0 to make a withdraw." << endl;
        }
        else if (flag == true) 
        { // do the withdraw from the balance
            if(balance >= amount) 
            {
                balance -= amount; 
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
    void calcInterest(double accBalance)// calculates current interest
    {
       accBalance = calcInt(accBalance);
    }      
};
#endif
