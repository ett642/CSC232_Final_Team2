#ifndef ABACCOUNT_H
#define ABACCOUNT_H
#include <iostream>
#include <string>
using namespace std;

class AbAccount
{
    private:
        string fName;
        string lName;
        string address;
        string accNum;
        double interestRate;
        int term;
        string dateOfOC;
        double balance;
        string records;

    public:
        AbAccount()
        {
            fName = "";
            lName = "";
            address = "";
            accNum = "";
            dateOfOC = "";
            balance = 0.00;
        }

        AbAccount(string first, string last, string add, string acc, string date, double bal)
        {
            fName = first;
            lName = last;
            address = add;
            accNum = acc;
            dateOfOC = date;
            balance = bal;

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
        double calcInt(double balance)
        {
            double dailyIR = annualIR / 365;
            dailyIR = dailyIR * balance;
            balance += dailyIR;
            return accBalance;
        }
    

}

#endif