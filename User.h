#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include "CD.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "Accounts.h"
using namespace std;

class User : public Accounts
{
    protected:
    string phone;
	string address;
	CheckingAccount checking = CheckingAccount();
	SavingsAccount savings = SavingsAccount();
	CD cd = CD();


    public:

    User(  string num, string pass, string inName, string date, vector<string> transactions) : Accounts( num,  pass,  inName,  date)
    {
        transactions.clear();
    }

    void loggedIn(string date){
		cout << "Successfully logged in! Last login was " << lastDate << endl;
		lastDate = date;
        int userInput;

        for(;;)
        {
            cout << "What would you like to do:\n" << "1 to access accounts:\n" << "2 to access change password:\n";
            cout << "3 to access transactions:\n" << "4 to exit\n";
            switch(userInput)
            {
                case 1:
                {
                    accMenu(date);
                }
                case 2:
                {
                    changePass();
                }
                case 3:
                {
                    //transactions
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

    void accMenu(string date)
    {
        int userInput;
        cout << "What would you like to do:\n" << "1 to access Checking:\n" << "2 to access savings:\n";
        cout << "3 to access CD:\n" << "4 to exit\n";
        cin >> userInput;
        for(;;)
        {
            switch(userInput)
            {
                case 1:
                {
                    checking.menu(date);
                }
                case 2:
                {
                    savings.menu(date);
                }
                case 3:
                {
                    cd.menu(date);
                }
                case 4:
                {
                    cout << "-------------------" << endl;
                    cout << "Exiting Menu... " << endl;
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
    void changePass()
    {
        string input,input2;
        cout << "Enter new password: ";
        cin >> input;
        cout << "Re-enter new password: ";
        cin >> input2;
        while(input != input2 )
        {
            cout << "Passwords do not match. Please Re-Enter new password. or enter 1 to restart password change.";
            cin >> input2;
            if(input2 == "1")
            {
                changePass();
                exit(0);
            }

        }
        password = input;

    }
    
    string printToFile ()
   {
      string info;
      info = number+"*"+password+"*"+name+"*"+lastDate+"*"+phone+"*"+address;
      return info;
   
   }
};





#endif
