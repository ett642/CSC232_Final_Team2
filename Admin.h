#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include "Accounts.h"
#include "Official.h"
#include "User.h"
#include <limits>
#include <vector>
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
	void loggedIn(string date, vector<Accounts> &logins)
   {
	cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
	lastDate = date;
   for(;;) { // menu for  loop
                    cout << "-------------------" << endl;
                    cout << "What would you like to do? \n" << endl;
                    cout << "[1] Create a Bank Official profile" << endl;
                    cout << "[2] Change a Bank Official profile's status" << endl;
                    cout << "[3] Create a Customer profile" << endl;
                    cout << "[4] Delete a Customer profile" << endl;
                    cout << "[5] Edit a Customer profile" << endl;
                    cout << "[6] Return to main menu" << endl;
                    cout << "-------------------" << endl;
                    int userInput;
                    cin >> userInput;
                    switch(userInput) {
                       case 1: 
                       {
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official First Name" << endl;
                          cout << "-------------------" << endl;
                          string firstName;
                          cin >> firstName; 
                         
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official Last Name" << endl;
                          cout << "-------------------" << endl;
                          string lastName;
                          cin >> lastName;
                          string inName = firstName + " " + lastName;
                          
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official Profile Number (First Digit Must Be 1)" << endl;
                          cout << "-------------------" << endl;
						        string num;
                          cin >> num;
                          if (num[0] == '1')
                          {
                                cout << "-------------------" << endl;
                                cout << "Enter Bank Official Profile Password" << endl;
                                cout << "-------------------" << endl;
      						        string pass;
                                cin >> pass; 
                                
                                Official temp = Official(num, pass, inName, date, "t");
                                logins.push_back(temp);
                                continue;
                          } 
                          else
                          {
                            cout << "-------------------" << endl;
                            cout << "Invalid Number please try again" << endl;
                            cout << "-------------------" << endl; 
                            continue;
                          }                     
                        }
                        
                        case 2: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Bank Official by Profile Number" << endl;
                          cout << "-------------------" << endl;
						        string num;
                          cin >> num;
                          
                          for(Accounts &i: logins)
                          {
      		                 cout << "-------------------" << endl;
                             cout << "Change this Bank Official's Status? Y/N" << endl;
                             cout << "-------------------" << endl;
                             string answer;
                             cin >> answer;
                             if(answer == "Y" || answer == "y")
                             {
                                 i.changeStatus();
                                 continue;
                             }
                             else if(answer == "N" || answer == "n")
                             {
                                 cout << "Returning to Admin Menu..." << endl;
                                 continue;
                             }
                             else
                             {
                                cout << "Invalid option...Please Try Again" <<endl;
                                continue;
                             } 

                          }                      
                        }
                                                 
                        case 3: 
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
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Phone Number" << endl;
                          cout << "-------------------" << endl;
                          string phone;
                          cin >> phone; 
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Address" << endl;
                          cout << "-------------------" << endl;
                          string address;
                          cin >> address; 
    
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Profile Number (First Digit Within 2-9)" << endl;
                          cout << "-------------------" << endl;
						        string num;
                          cin >> num;
                          if (num[0] != '1' && num[0] != '0')
                          {
                                cout << "-------------------" << endl;
                                cout << "Enter Customer Profile Password" << endl;
                                cout << "-------------------" << endl;
      						        string pass;
                                cin >> pass;  
                                
                                User temp = User(num, pass, inName, date, phone, address);
                                logins.push_back(temp);
                                continue;
                          } 
                          else
                          {
                            cout << "-------------------" << endl;
                            cout << "Invalid Number please try again" << endl;
                            cout << "-------------------" << endl;
                            continue;                       
                          }
                        }
                        
                        
                        case 4: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Customer by Profile Number" << endl;
                          cout << "-------------------" << endl;
						        string num;
                          cin >> num;
		                    for(Accounts &i: logins)
                          {
   		                    if(i.getNumber() == num)
                             cout << "-------------------" << endl;
                             cout << "Delete this Customer? Y/N" << endl;
                             cout << "-------------------" << endl;
                             string answer;
                             cin >> answer;
                             if(answer == "Y" || answer == "y")
                             {
                               int count = 0;
                               for(Accounts &j: logins)
                               {
                                 if(num == j.getNumber())
                                 {
                                 break;
                                 }
                                 count++;
                               }
                               logins.erase(logins.begin() + count);
                             }
                             else if(answer == "N" || answer == "n")
                             {
                                cout << "Returning to Admin Menu..." << endl;
                                continue;
                             }
                             else
                             {
                                cout << "Invalid option...Please Try Again" <<endl;
                                continue;
                             } 
                          }
                        }
                        
                        case 5: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Customer by Profile Number" << endl;
                          cout << "-------------------" << endl;
						        string num;
                          cin >> num;
		                    for(Accounts &i: logins)
                          {
   		                    if(i.getNumber() == num)                 
                             cout << "-------------------" << endl;
                             cout << "Edit this Customer Profile? Y/N" << endl;
                             cout << "-------------------" << endl;
                             string answer;
                             cin >> answer;
                             
                             if(answer == "Y" || answer == "y")
                             {
                                //proceed with editing the user
                                cout << "-------------------" << endl;
                                cout << "What would you like to change?" << endl;
                                cout << "[1] Change Name" << endl;
                                cout << "[2] Change Phone" << endl;
                                cout << "[3] Change Address" << endl;
                                cout << "[4] Change Password" << endl;
                                cout << "[5] Return" << endl;
                                cout << "-------------------" << endl;
                                int newInput;
                                cin >> newInput;
                                switch(newInput) 
                                {
                                   case 1: 
                                   {
                                      cout << "Enter First Name: " << endl;
                                      string firstname;
                                      cin >> firstname;
                                      cout << "Enter Last Name: " << endl;
                                      string lastname;
                                      cin >> lastname;
                                      string inName = lastname + " " + firstname;
                                      for(Accounts &i: logins)
                                      {
                                              i.changeName(inName);
                                              cout << "Name Successfully Changed" << endl;
                                              cout << "Returning to Edit Menu" << endl;
                                              continue;
                                          }
                                      }
                                    
                                   
                                   case 2: 
                                   {
                                      cout << "Enter New Phone Number: " << endl;
                                      string phoneNumber;
                                      cin >> phoneNumber;
                                      for(Accounts &i: logins)
                                      {
                                              cout << "Phone Number Successfully Changed" << endl;
                                              cout << "Returning to Edit Menu" << endl;
                                              i.changePhone(phoneNumber);
                                              continue;
                                          }
                                      }
                                    
                                    
                                   case 3: 
                                   {
                                      cout << "Enter New Password: " << endl;
                                      string password;
                                      cin >> password;

                                      cout << "Password Successfully Changed" << endl;
                                      cout << "Returning to Edit Menu" << endl;
                                      i.changePass(password);
                                      continue;
                                    }
                                    
                                   case 4: 
                                   {
                                      cout << "Enter New Address: " << endl;
                                      string newAddress;
                                      cin >> newAddress;
                                      for(Accounts &i: logins)
                                      {
                                              cout << "Address Successfully Changed" << endl;
                                              cout << "Returning to Edit Menu" << endl;
                                              i.changeAddress(newAddress);
                                              continue;
                                          }
                                      }
                                  }
                             }  
                             else if(answer == "N" || answer == "n")
                             {
                             cout << "Returning to Admin Menu..." << endl;
                             continue;
                             }
                             else
                             {
                             cout << "Invalid option...Please Try Again" <<endl;
                             continue;
                             } 
                          }
                        }
                        
                        case 6: 
                        {
                          cout << "-------------------" << endl;
                          cout << "Returning to Main Menu..." << endl;
                          cout << "-------------------" << endl;
                          break;
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
          
   string printToFile(string num, string pass, string inName, string date)
   {
      string info;
      info = num+"*"+pass+"*"+inName+"*"+date;
      return info;
   
   } 
   
};
#endif
