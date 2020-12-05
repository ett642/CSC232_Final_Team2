#ifndef ABACCOUNT_H
#define ABACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

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
        AbAccount()
        {
            status = false;
            dateOfOC = "";
            balance = 0.00;
			interestRate = 0;
        }

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

        void setStatus()
        {
            int input;
            cout << "1 to activate account.\n" << "2 to deactivate account.\n";
            cin >> input;
            switch(input)
            {
                case 1:
                {
                    status = true;
                }
                case 2:
                {
                    status = false;
                }
            }
        }

        bool getStatus()
        {
            return status;
        }
		
		void setInterest(double interest){
			interestRate = interest;
		}
};
#endif
