#ifndef ABACCOUNT_H
#define ABACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

//Parent class of checking, savings, and cd account classes
class AbAccount
{
    protected:
	
        string accNum;
        double interestRate;
        int term;
        string dateOfOC;
        double balance;
        string records;
        bool status;

    public:
	
    	string lastDate;
	
	//Default Constructor
        AbAccount()
        {
            status = false;
            dateOfOC = "";
            balance = 0.00;
			interestRate = 0;
        }
	
	//Constructor
        AbAccount( string acc, string date, double bal, bool stat)
        {
            accNum = acc;
            dateOfOC = date;
            balance = bal;
            status = stat;
        }

        // Deposits an amount specified into the account balance
        virtual void deposit(long double amount)
        {
            balance += amount;
        }
	
        // Withdraws an amount specified from the account balance
        virtual void withdraw(long double amount)
        {
            balance -= amount;
        }
	
        // calculates daily interest rate and adds the daily interest to account balance
        void calcInt()
        {
            double dailyIR = interestRate / 365;
            dailyIR = dailyIR * balance;
            balance += dailyIR;
        }
	
	//Changes status of user banking accounts 
        virtual void setStatus()
        {
		while(true)
		{
			int input;
			cout <<endl<<"1 to activate account.\n" << "2 to deactivate account.\n";
			cin >> input;
			
			switch(input)
			{
				case 1:
				{
					status = true;
					cout<<"Account status changed to true!\n\n";
					return;
				}
				case 2:
				{
					status = false;
					cout<<"Account status changed to false!\n\n";
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
	
	//Gets user account status
        bool getStatus()
        {
            return status;
        }
	
	//Sets interest rate
	void setInterest(double interest)
	{
		interestRate = interest;
	}
};
#endif
