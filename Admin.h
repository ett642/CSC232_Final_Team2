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
   //Constructor
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
                       case 1: 
                       {
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official First Name" << endl;
                          cout << "-------------------" << endl;
                          string firstname;
                          cin >> firstname; 
                         
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official Last Name" << endl;
                          cout << "-------------------" << endl;
                          string lastname;
                          cin >> lastname;
                          string inName = firstname + lastname;
                          //return inName?
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official Profile Number (4 digits)" << endl;
                          cout << "-------------------" << endl;
						  string num;
                          cin >> num;
                          //check if number entered is 4 digits
                         
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official Profile Password" << endl;
                          cout << "-------------------" << endl;
						  string pass;
                          cin >> pass;
                          
                          //error checking here
                          continue;
                        }
                        
                        case 2: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Bank Official by Profile Number" << endl;
                          cout << "-------------------" << endl;
						  string num;
                          cin >> num;
                          
                          cout << "-------------------" << endl;
                          cout << "Enable this Bank Official? Y/N" << endl;
                          cout << "-------------------" << endl;
                          string answer;
                          cin >> answer;
                          if(answer == "Y" || answer == "y")
                          {
                          //proceed with enabling the bank official
                          }
                          else if(answer == "N" || answer == "n")
                          {
                          cout << "Returning to Admin Menu..." << endl;
                          continue;
                          }
                          else
                          {
                          cout << "Invalid option...Please Try Again" <<endl;
                          //return to enable this bank official? y/n
                          } 
                          continue;
                        }
                         
                        case 3: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Bank Official by Profile Number" << endl;
                          cout << "-------------------" << endl;
						  string num;
                          cin >> num;
                          
                          cout << "-------------------" << endl;
                          cout << "Disable this Bank Official? Y/N" << endl;
                          cout << "-------------------" << endl;
                          string answer;
                          cin >> answer;
                          if(answer == "Y" || answer == "y")
                          {
                          //proceed with enabling the bank official
                          }
                          else if(answer == "N" || answer == "n")
                          {
                          cout << "Returning to Admin Menu..." << endl;
                          continue;
                          }
                          else
                          {
                          cout << "Invalid option...Please Try Again" <<endl;
                          //return to disable this bank official? y/n
                          } 
                          continue;
                        }
                        
                        case 4: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Enter Customer First Name" << endl;
                          cout << "-------------------" << endl;
                          string firstname;
                          cin >> firstname; 
                         
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Last Name" << endl;
                          cout << "-------------------" << endl;
                          string lastname;
                          cin >> lastname;
                          string inName = firstname + lastname;
                          //return inName?
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Profile Number (5 digits)" << endl;
                          cout << "-------------------" << endl;
						  string num;
                          cin >> num;
                          //check if number entered is 5 digits
                         
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Profile Password" << endl;
                          cout << "-------------------" << endl;
						  string pass;
                          cin >> pass;                        
                        }
                        
                        case 5: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Customer by Profile Number" << endl;
                          cout << "-------------------" << endl;
						  string num;
                          cin >> num;
                          
                          cout << "-------------------" << endl;
                          cout << "Delete this Cusotmer? Y/N" << endl;
                          cout << "-------------------" << endl;
                          string answer;
                          cin >> answer;
                          if(answer == "Y" || answer == "y")
                          {
                          //proceed with deleting the user
                          //figure out how to delete user completely
                          }
                          else if(answer == "N" || answer == "n")
                          {
                          cout << "Returning to Admin Menu..." << endl;
                          continue;
                          }
                          else
                          {
                          cout << "Invalid option...Please Try Again" <<endl;
                          //return to delete this Customer? y/n
                          } 
                          continue;
                        }
                        
                        case 6: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Customer by Profile Number" << endl;
                          cout << "-------------------" << endl;
						  string num;
                          cin >> num;
                                                    
                          cout << "-------------------" << endl;
                          cout << "Edit this Cusotmer Profile? Y/N" << endl;
                          cout << "-------------------" << endl;
                          string answer;
                          cin >> answer;
                          if(answer == "Y" || answer == "y")
                          {
                          //proceed with editing the user
                          //figure out how to reset password here as well
                          }
                          else if(answer == "N" || answer == "n")
                          {
                          cout << "Returning to Admin Menu..." << endl;
                          continue;
                          }
                          else
                          {
                          cout << "Invalid option...Please Try Again" <<endl;
                          //return to delete this Customer? y/n
                          } 
                          continue;
                        }
                        case 7: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Returning to Main Menu..." << endl;
                          cout << "-------------------" << endl;
                          break;
                          //find out how to exit


                        }
                        default: 
                        {       // error catching
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
      info = num+"*"+pass+"*"+inName+"*"+date;
      return info;
   
   } 
   
};
#endif
   
   //function to create a bank official login

   //function to enable a bank official login
   
   //function to disable a bank official login
   
   //function to create user account
   
   //function to delete user account
   
   //function to modify user account
   
   //function to change user password
