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
    private:
    string maturityDate = "1/1/2000";
    double rate = 0.1;
    
    public:
    // Constructor
    CD (): AbAccount()
    {

    }
    
   //function for logged in menu
   void menu(string date)
   {
   if(!status)
   {
   cout<<"You don't have a CD! Contact a Bank Official to open one.\n";
   return;	
   }
   lastDate = date;
   for(;;) { // menu for  loop
                    cout << "-------------------" << endl;
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Open a CD" << endl;
                    cout << "[2] Close Existing CD" << endl;
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
                          open(depositAmt, lastDate);
                          
                          //deposit amount using depositAmt?
                          
                          cout << "-------------------" << endl;
                          cout << "Your CD balance is: " << balance << endl;
                          cout << "Maturity Date: " << maturityDate << endl; //put maturityDate variable here
                          cout << "Monthly Interest Rate: " << rate << endl;//put rate variable here
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
                          cout << "Your CD is now closed. You recieved $" << close(lastDate) << endl;
                          cout << "-------------------" << endl;
                          cout << "Hit enter to continue" << endl;
                          cout << "-------------------" << endl;
                          char enter = cin.get(); 
                          cin.ignore();
                          continue;
                       }
                       case 3:
                       {
                          cout << "-------------------" << endl;
                          cout << "Your Initial Deposit was: " << balance << endl;
                          cout << "Maturity Date: " << maturityDate << endl; //put maturityDate variable here
                          cout << "Monthly Interest Rate: " << rate << endl;//put rate varaible here
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
   void open(double amount, string date) 
   {
      if(amount > 0.00) //if the amount deposited is more than 0 
      {
         balance += amount; //successfully deposit
         maturityDate = maturityCalc(date);
		 status = true;
         
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
            open(amt,date);
            break;
         }
      }

   }
   
   double close(string date) //function to withdraw money and close the account
   {
       if(!status) 
       {
            cout<<"You don't have a CD! Contact a Bank Official to open one.\n";
            return 0;	
       }
            cout << "Warning! Your withdrawl will incur a penalty, your Certificate of Deposit balance is: $" << balance << endl;
            cout << "You must wait until the maturity date to withdraw your funds with no penalty " << endl;
            
            int month = stoi(date.substr(0,date.find("/")));
      		string temp = date.substr(date.find("/")+1);
      		int day = stoi(date.substr(0,date.find("/")));
            temp = date.substr(date.find("/")+1);
		      int year = stoi(date);
            
            int maturityMonth = stoi(maturityDate.substr(0,maturityDate.find("/")));
            temp = maturityDate.substr(maturityDate.find("/")+1);
            int maturityDay = stoi(maturityDate.substr(0,maturityDate.find("/")));
            temp = maturityDate.substr(maturityDate.find("/")+1);
            int maturityYear = stoi(maturityDate);
            
            if (month > maturityMonth)
            {
               maturityMonth += 12;
            }
            int monthsLeft = maturityMonth - month;
            
            if (maturityYear < year)
            {
            //successful
            calcInt();
            double tempBalance = balance;
            resetCD();
            return tempBalance;
            }
            
            else if (maturityYear == year)
            {
               if(monthsLeft > 3)
               {
                  //successful
                  calcInt();
                  double tempBalance = balance;
                  resetCD();
                  return tempBalance;
               }
               else if(monthsLeft == 3)
               {
                  if(maturityDay <= day)
                  {
                     //successful
                     calcInt();
                     double tempBalance = balance;
                     resetCD();
                     return tempBalance;
                  }
               }
            }
            //interest penalty
            if(monthsLeft == 3)
            {
               double tempBalance = balance - (balance * 0.4);
               resetCD();
               return tempBalance;
            }
            //interest penalty
            else if(monthsLeft == 2)
            {
               double tempBalance = balance - (balance * 0.2);
               resetCD();
               return tempBalance;
            }
            //interest penalty
            else
            {
               double tempBalance = balance - (balance * 0.1);
               resetCD();
               return tempBalance;
            }             
            
    }
    
    void calcInt()// calculates current interest based on CD's fixed annual rate
    {
       double monthlyRate = rate / 12;
       monthlyRate = 3 * (monthlyRate * balance);
       balance += monthlyRate;
    }  
    
    //function to determine when the maturity date of the CD is
    string maturityCalc(string date)
    {
      //take the current date and change the month variable to be 3 months later
      int month = stoi(date.substr(0,date.find("/")));
		string temp = date.substr(date.find("/")+1);
		int day = stoi(date.substr(0,date.find("/")));
      temp = date.substr(date.find("/")+1);
      int year = stoi(date);
      
      month += 3;
      if (month > 12)
      {
         month -= 12;
         year += 1;
      }
      string mDate = to_string(month) + "/" + to_string(day) + "/" + to_string(year);
      return mDate;  //return the result as a string variable "maturityDate"
      
    }
    
    void resetCD()
    {
      balance = 0;
      status = false;
    }

	void fileInfo(double bal, string stat, string term){
	   balance = bal;
	   maturityDate = term;
		if(stat == "t"){
			status = true;
		}
		else{
			status = false;
		}
	}
	
	string printToFile(){
		string info; string stat = "f";
		if(status){
			stat = "t";
		}
		info = to_string(balance)+"*"+stat+"*"+maturityDate;
		return info;
	}
};
#endif
