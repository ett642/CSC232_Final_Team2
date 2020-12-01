#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include <string>
#include <iostream>
#include "BankAccount.h"
#include <limits>
using namespace std;

class CheckingAccount : public BankAccount 
{
   public:
   // Default constructor
   CheckingAccount() : BankAccount()
   {
      flag = false;
   }
    
   CheckingAccount(string num, long double balance, double intrestRate) 
   : BankAccount(num, balance, intrestRate)
   {
      flag = false;
   }

    void deposit(long double amount) 
    {
        if(amount > 0.00) 
        {
            accBalance += amount; // deposit the amount
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
       if(accBalance >= amount) 
       {
         accBalance -= amount; // subtract the amount if it's in the balance
       }
       else 
       {
         cout << "Invalid funds " << endl;
         if(accBalance < 0.00) 
         { // if account balance is below 0 let the user know and do not allow withdraw
            cout << "Your balance fell below $0.";
         }
       }
    } 
};
#endif
