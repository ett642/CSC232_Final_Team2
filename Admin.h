#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include "Accounts.h"
#include <limits>
using namespace std;

//Admin class represents the role of a banking administrator
//Admin is a child of parent class Accounts

class Admin : public Accounts
{
   public:
      //public variables
   
   //Default constructor
   Admin() : Accounts()
   {
   
   }
   //2nd constructor
   Admin(string num, string pass, string inName, string date): Accounts(num,pass,inName,date)
   {
   
   }
   
   //function for logged in menu
	void loggedIn(string date)
   {
	cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
	lastDate = date;
   for(;;) { // menu for  loop
                    cout << "-------------------" << endl;
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Create a Bank Official profile" << endl;
                    cout << "[2] Enable a Bank Official profile" << endl;
                    cout << "[3] Disable a Bank Official profile" << endl;
                    cout << "[4] Create a Customer profile" << endl;
                    cout << "[5] Delete a Customer profile" << endl;
                    cout << "[6] Edit a Customer profile" << endl;
                    cout << "[7] Return to main menu" << endl;
                    cout << "-------------------" << endl;
                    int userInput;
                    cin >> userInput;
                    switch(userInput) {
                       switch(userInput) 
                    {
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
   string printToFile (string num, string pass, string inName, string date)
   {
      string info;
      info = num + pass + inName + date;
      return info;
   
   } 
   
   
   //function to create a bank official login

   //function to enable a bank official login
   
   //function to disable a bank official login
   
   //function to create user account
   
   //function to delete user account
   
   //function to modify user account
   
   //function to change user password
