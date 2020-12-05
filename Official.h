#ifndef OFFICIAL_H
#define OFFICIAL_H
#include <iostream>
#include <string>
#include <vector>
#include "User.h"
#include "Accounts.h"
using namespace std;

class Official : public Accounts{
private:
	string stat;
	bool status;
	
public:
	Official(string num, string pass, string inName, string date, string s):Accounts(num,pass,inName,date){
		stat = s;
		createStatus(stat);
	}
	
	void createStatus(string s){
		if(s=="t")
			status = true;
		else
			status = false;
	}
	
	void loggedIn(string date, vector<Accounts> &logins){
		if(status){
			cout<<"Status: Active"<<endl;
		}
		else{
			cout<<"Status: Inactive"<<endl;
			return;
		}
	}
	
	void openClose(vector<Accounts> &logins)
	{
		string input;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(Accounts &i: logins)
		{
			if(i.getNumber() == input)
			{
				cout << "Which account type would you like to access?\n" << "1 for Checking\n" << "2 for Savings\n";
				cout <<"3 for CD\n" << "4 to exit\n";
				cin >> sNum;
				for(;;)
				{
					switch(sNum)
					{
						case 1:
						{
							changeCheckingStat(i);
						}
						case 2:
						{
							changeSavingsStat(i);
						}
						case 3:
						{
							changeCDStat(i);
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
		}
		cout << "Customer not found.\n";
		
	}

	void changeCheckingStat(Accounts i)
	{
		CheckingAccount c;
		c = i.getChecking();
		c.setStatus();
		if(c.getStatus() == false)
		{
			//save num, inName
			// save account info
		}
	}

	void changeSavingsStat(Accounts i)
	{
		SavingsAccount s;
		s = i.getSavings();
		s.setStatus();
		if(s.getStatus() == false)
		{
			//save num, inName
			// save account info
		}
	}

	void changeCDStat(Accounts i)
	{
		CD c;
		c = i.getCD();
		c.setStatus();
		if(c.getStatus() == false)
		{
			//save num, inName
			// save account info
		}
	}

	void accountDeposit(vector<Accounts> &logins)
	{
		string input;
		CheckingAccount c;
		SavingsAccount s;
		CD cd;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(Accounts &i: logins)
		{
			
			if((i.getNumber() == input))
			{
				cout << "Allow the Customer to enter their password.\n";
				cin >> input;
				if(i.getPassword() == input)
				{
					cout << "Which account type would you like to access?\n" << "1 for Checking\n" << "2 for Savings\n";
					cout <<"3 for CD\n" << "4 to exit\n";
					cin >> sNum;
					for(;;)
					{
						switch(sNum)
						{
							case 1:
							{
								c = i.getChecking();
								cout << "1 to deposit\n" << "2 to withdraw" << "3 to Cancel";
								cin >> sNum;
								for(;;)
								{
									switch(sNum)
									{
										case 1:
										{
											cout << "-------------------" << endl;
											cout << "How much would you like to deposit?" << endl;
											cout << "-------------------" << endl;
											long double depositAmt;
											cin >> depositAmt;
											c.deposit(depositAmt);
										}
										case 2:
										{
											cout << "-------------------" << endl;
											cout << "How much would you like to Withdraw?" << endl;
											cout << "-------------------" << endl;
											long double withdrawAmt;
											cin >> withdrawAmt;
											c.withdraw(withdrawAmt);
										}
										case 3:
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
							case 2:
							{
								s = i.getSavings();
								cout << "1 to deposit\n" << "2 to withdraw" << "3 to Cancel";
								cin >> sNum;
								for(;;)
								{
									switch(sNum)
									{
										case 1:
										{
											cout << "-------------------" << endl;
											cout << "How much would you like to deposit?" << endl;
											cout << "-------------------" << endl;
											long double depositAmt;
											cin >> depositAmt;
											s.deposit(depositAmt);
										}
										case 2:
										{
											cout << "-------------------" << endl;
											cout << "How much would you like to Withdraw?" << endl;
											cout << "-------------------" << endl;
											long double withdrawAmt;
											cin >> withdrawAmt;
											s.withdraw(withdrawAmt);
										}
										case 3:
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
							case 3:
							{
								//add CD when CD is complete
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
				else
				{
					cout << "Password incorrect.\n";
					return;
				}
				
			}
		}
		cout << "Customer not found.\n";
		
	}

	void searchAccount()
	{
		string input;
		CheckingAccount c;
		SavingsAccount s;
		CD cd;
		int sNum;
		cout << "Enter the customer account you would like to access: ";
		cin >> input;
		for(Accounts &i: logins)
		{
			
			if((i.getNumber() == input) || (i.getName() == input) || (i.getPhone() == input))
			{
				cout << i.getNumber() << " " << i.getName() << " " << i.getPhone() << endl;
			}
	

	//Method to retrieve info from closed accounts
};
#endif
