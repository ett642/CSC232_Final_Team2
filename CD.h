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
    double rate;
    bool flag;
    // Constructor
    CD (string num, string date, double balance, bool status, bool flag): AbAccount(num, date, balance,status)
    {
       term = 3;
       rate = 0.1;
       flag = true;
    }
   //function for logged in menu
   void menu(string date)
   {
	//cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
	//lastDate = date;
   for(;;) { // menu for  loop
                    cout << "-------------------" << endl;
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Open a CD" << endl;
                    cout << "[2] Withdraw Funds from an Existing CD" << endl;
                    cout << "[3] Check CD Info" << endl;
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
                          cout << "Your CD balance is: " << balance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          cout << "-------------------" << endl;
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
                          //fix withdraw function and work on how to close CD account
                          
                          cout << "-------------------" << endl;
                          cout << "Your CD is now closed" << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          char enter = cin.get(); 
                          cin.ignore();
                          continue;
                       }
                       case 3:
                       {
                          cout << "-------------------" << endl;
                          cout << "Your Current CD Balance is: " << balance << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          cout << "-------------------" << endl;
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

   
   
  
   //function to open a CD
   void open(double amount) 
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
            cout << "Warning! Your withdrawl will incur a penalty, your Certificate of Deposit balance is: $" << balance << endl;
            cout << "You must wait until the maturity date to withdraw your funds with no penalty " << endl;
        }
        else if (status == true) 
        { // do the withdraw from the balance with no penalty
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
                cout << "Warning! You cannot withdraw your Certificate of Deposit has fallen below $0.00. " << endl;
                cout << "You must deposit more money and wait until the maturity date before you can make another withdraw without penalty." << endl;
                status = false;
            }
        }
    }
    double calcInterest(double balance, double annualRate)// calculates current interest
    {
       double dailyRate = annualRate / 365;
       dailyRate = dailyRate * balance;
       balance += dailyRate;
       return balance;
    }      
};
#endif
