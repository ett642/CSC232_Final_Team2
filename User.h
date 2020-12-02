#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include "Accounts.h"
using namespace std;

class User : public Accounts
{
    private:
    
    vector<string> transactions;


    public:
    void accMenu();

    User(  string num, string pass, string inName, string date, vector<string> transactions) : Accounts( num,  pass,  inName,  date)
    {
        transactions.clear();
    }

    void loggedIn(string date){
		cout<<"Successfully logged in! Last login was "<<lastDate<<endl;
		lastDate = date;
        int userInput;

        cout << "What would you like to do:\n" << "1 to access accounts:\n" << "2 to access change password:\n" << "3 to access transactions:\n";
        switch(userInput)
        {
            case 1:
            {
                accMenu();
            }
            case 2:
            {
                //change password
            }
            case 3:
            {
                //transactions
            }
        }
	}

    void accMenu()
    {
        int userInput;
        cout << "What would you like to do:\n" << "1 to access Checking:\n" << "2 to access savings:\n" << "3 to access CD:\n";
        cin >> userInput;
        switch(userInput)
        {
            case 1:
            {
                //checking
            }
            case 2:
            {
                //savings
            }
            case 3:
            {
                //CD
            }
        }
    }
};





#endif