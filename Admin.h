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
   void loggedIn(string date, vector<Official> &official, vector<User> &user)
   {
		cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
		lastDate = date; //changes the last date to the current date
		while(true){ // menu for  loop
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
			switch(userInput) //switch case based on user input
			{
                       	case 1: //Creates a Bank Official in the logins.txt file
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
                          string inName = firstName + " " + lastName; //gets name 
                          
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Bank Official Profile Number (First Digit Must Be 1)" << endl; //search Bank Official profile number
                          cout << "-------------------" << endl;
			  string num;
                          cin >> num;
                          if (num[0] == '1')
                          {
                                cout << "-------------------" << endl;
                                cout << "Enter Bank Official Profile Password" << endl;
                                cout << "-------------------" << endl;
      				string pass;
                                cin >> pass; //get password
                                
                                Official temp = Official(num, pass, inName, date, "t");
                                official.push_back(temp); //creates the Bank Official
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
                        
                        case 2: //Change Bank Official Profile Status 
                        {
                          cout << "-------------------" << endl;
                          cout << "Search a Bank Official by Profile Number" << endl;
                          cout << "-------------------" << endl;
			  string num;
                          cin >> num;
                          
                          for(Official &i: official) //traverse vector
                          {
      		             cout << "-------------------" << endl;
                             cout << "Change this Bank Official's Status? Y/N" << endl;
                             cout << "-------------------" << endl;
                             string answer; 
                             cin >> answer;
                             if(answer == "Y" || answer == "y")
                             {
                                 i.changeStatus(); //changes status of the Bank official
                                 continue;
                             }
                             else if(answer == "N" || answer == "n")
                             {
                                 cout << "Returning to Admin Menu..." << endl;
                                 continue; //returns to the Admin Menu 
                             }
                             else
                             {
                                cout << "Invalid option...Please Try Again" <<endl;
                                continue;
                             }
                          }
			continue;
                        }
                        case 3: //Create a Customer Profile
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
                          string inName = firstname +" "+ lastname; //add name to vector
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Phone Number" << endl;
                          cout << "-------------------" << endl;
                          string phone;
                          cin >> phone; 
                          
                          cout << "-------------------" << endl;
                          cout << "Enter Customer Address" << endl;
                          cout << "-------------------" << endl;
			  cin.clear();
                          cin.ignore();
                          string address;
                          getline(cin,address); 
    
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
                                
                                User temp = User(num, pass, inName, date, phone, address); //adds user info to the vector with correct content
                                user.push_back(temp);
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
                        
                        
                        case 4: //Delete a Customer Profile
                        {
		            cout << "-------------------" << endl;
		            cout << "Search a Customer by Profile Number" << endl;
			    cout << "-------------------" << endl;
		            string num;
			    cin >> num;
			    for(User &i: user) //traverse the vector
			    {
				if(i.getNumber() == num)
				{
					cout << "-------------------" << endl;
					cout << "Delete this Customer? Y/N" << endl;
					cout << "-------------------" << endl;
					string answer;
					cin >> answer;
					if(answer == "Y" || answer == "y")
					{
						int count = 0;
						for(User &j: user)
						{
							if(num == j.getNumber()) //if the number is in the vector then break out of the loop
							{
								break;
							}
							count++;
						}
						user.erase(user.begin() + count); //erase the customer profile
						continue;
					}
					else if(answer == "N" || answer == "n")
					{
						cout << "Returning to Admin Menu..." << endl; //return to Admin menu
						continue;
					}
					else
					{
						cout << "Invalid option...Please Try Again" <<endl; //wrong input
						continue;
					} 
			          }
			    }
			continue;
                        }
                        
                        case 5: //Edit Customer Profile
                        {
		           cout << "-------------------" << endl;
		           cout << "Search a Customer by Profile Number" << endl;
			   cout << "-------------------" << endl;
			   string num;
			   cin >> num;
		           for(User &i: user) //searches through User vector
			   {
				if(i.getNumber() == num) //compares the account number with the vector 
				{
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
								i.changeName(inName); //changes the name in the vector
								cout << "Name Successfully Changed" << endl;
								cout << "Returning to Edit Menu" << endl;
								continue;
							}


						   case 2: 
							{
								cout << "Enter New Phone Number: " << endl;
								string phoneNumber;
								cin >> phoneNumber;
								cout << "Phone Number Successfully Changed" << endl;
								cout << "Returning to Edit Menu" << endl;
								i.changePhone(phoneNumber); //changes the phone in the vector
								continue;
							}


						   case 3: 
							{
								i.changePass(); //calls function to change password in vector
								cout << "Password Successfully Changed" << endl;
								cout << "Returning to Edit Menu" << endl;
								continue;
							}

						   case 4: 
							{
								cout << "Enter New Address: " << endl;
								string newAddress;
								cin >> newAddress;
								cout << "Address Successfully Changed" << endl;
								cout << "Returning to Edit Menu" << endl;
								i.changeAddress(newAddress); //changes address
								continue;
							}
						}
					}  
					else if(answer == "N" || answer == "n")
					{
						cout << "Returning to Admin Menu..." << endl;
						continue; //returns to Admin menu
					}
					else
					{
						cout << "Invalid option...Please Try Again" <<endl;
						continue; //wrong 
					} 
				}
				continue;
			    }
			}
                        
                        case 6: //Returns to Main Menu
                        {
                          cout << "-------------------" << endl;
                          cout << "Returning to Main Menu..." << endl;
                          cout << "-------------------" << endl;
                          return;
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
		
   string printToFile() //function to print information to logins.txt
   {
      string info;
      info = number+"*"+password+"*"+name+"*"+lastDate;\
      return info;
   
   } 
   
};
#endif
