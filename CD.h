#ifndef CD_H
#define CD_H
#include <string>
#include <iostream>
#include "BankAccount.h"
#include <limits>
using namespace std;

//CD represents a functioning certificate of deposits
// CD class is a child class of parent
// BankAccount class

class CD : public BankAccount {
    public:
    double term;
    double rate;
    bool status;
   // Default constructor
   SavingsAccount() : BankAccount()
   {
      double term = 365;
      double rate = 10;
      bool status = true
   }
   // 2nd Constructor
   CD (string num, double balance, double interestRate): 
   BankAccount (num, balance, interestRate)
   {
      term = 365;
      rate = 10;
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
        { // deny the withdraw
            cout << "You may not withdraw, your Certificate of Deposit balance is: $" << accBalance << endl;
            cout << "You must wait until the maturity date to withdraw your funds " << endl;
        }
        else if (status == true) 
        { // do the withdraw from the balance
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
                cout << "You must deposit more money and wait until the maturity date before you can make another withdraw." << endl;
                status = false;
            }
        }
    }
    void calcInterest(double accBalance)// calculates current interest
    {
       accBalance = calcInt(accBalance);
    }      
};
#endif
