#ifndef CD_H
#define CD_H
#include <string>
#include <iostream>
#include "AbAccount.h"
#include <limits>
using namespace std;

// CD represents a functioning certificate of deposits
// CD class is a child class of parent
// AbAccount class

class CD : public AbAccount {
    public:
    double term;
    double annualRate;
    bool status;
   // Default constructor
   CD() : AbAccount()
   {
      double term = 3;
      double rate = 0.1;
      bool status = true
   }
   // 2nd Constructor
   CD (string num, double balance, double interestRate): 
   AbAccount (num, balance, interestRate)
   {
      term = 3;
      rate = 0.1;
      status = true
   }
   //function to open a CD
   void open(double amount) 
   {
      if(amount > 0.00) //if the amount deposited is more than 0 
      {
         accBalance += amount;//successfully deposit
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
      if(accBalance >= 0.0) //if the balance is greater than $0 the status will remain open 
      {
         status = true;
      }
      else // redudant statement...
      { 
         status = false; 
      }
        
   }
   void withdraw(double amount) //function to withdraw money
   {
       if(status == false) 
        { // withdraw with penalty
            cout << "Warning! Your withdrawl will incur a penalty, your Certificate of Deposit balance is: $" << accBalance << endl;
            cout << "You must wait until the maturity date to withdraw your funds with no penalty " << endl;
        }
        else if (status == true) 
        { // do the withdraw from the balance with no penalty
            if(accBalance >= amount) 
            {
                accBalance -= amount; 
            }
            else 
            {
                cout << "Invalid funds " << endl;
            }
            if(accBalance < 0.0)// if the balance falls below $0 account becomes inactive 
            {
                cout << "Warning! You cannot withdraw your Certificate of Deposit has fallen below $0.00. " << endl;
                cout << "You must deposit more money and wait until the maturity date before you can make another withdraw without penalty." << endl;
                status = false;
            }
        }
    }
    void calcInterest(double accBalance, double annualRate)// calculates current interest
    {
       double dailyRate = annualRate / 365;
       dailyRate = dailyRate * accBalance;
       accBalance += dailyRate;
       return accBalance;
    }      
};
#endif
