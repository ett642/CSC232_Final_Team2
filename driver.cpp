#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Accounts.h"
#include "Admin.h"
#include "Official.h"
#include "User.h"
using namespace std;

/*
Driver for Team 2 CSC 232 final project Bear Bank.
Project done by Ethan Tanner, Ethan Dawley, and Christian Leslie
*/

void getDate(string date, int *month, int *day, int *year){
	*month = stoi(date.substr(0,date.find("/")));
	date = date.substr(date.find("/")+1);
	*day = stoi(date.substr(0,date.find("/")));
	date = date.substr(date.find("/")+1);
	*year = stoi(date);
}

void fromFile(vector<Accounts> &logins){
	fstream file; string num; string pass; string name; string lastDate; string text;
	file.open("logins.txt");
	if(file){
		while(getline(file,text)){
			if(text[0] == '0'){
				num = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				pass = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				name = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				lastDate = text;
				Admin temp = Admin(num,pass,name,lastDate);
				logins.push_back(temp);
			}
			else if(text[1] == '1'){
				string status;
				num = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				pass = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				name = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				lastDate = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				status = text;
				Official temp = Official(num,pass,name,lastDate,status);
				logins.push_back(temp);
			}
			else{
				num = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				pass = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				name = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				lastDate = text;
			}
		}
	}
	file.close();
}

void loginSearch(string number, string password, vector<Accounts> &logins){
	for(Account &i: logins){
		if(number == i.getNumber() and password == i.getPassword){
			cout<<"Logged in."<<endl;
			return;
		}
	}
	
}

main(){
	vector<Accounts> logins;
	
	string loginNum; string password; string date;
	int month; int day; int year;
	cout<<"Enter today's date (MM/DD/YYYY): ";
	cin>>date;
	getDate(date, &month, &day, &year);
	fromFile(logins);
	
	cout<<"Welcome to Bear Bank!\n[1] Login\n[2] Exit"<<endl;
	bool check = true;
	while(check){
		cout<<endl<<"Choose an option: ";
		int option; cin>>option;
		switch(option){
			case 1:
				cout<<"Enter your login number: ";
				cin>>loginNum;
				cout<<"Enter your login password: ";
				cin>>password;
				break;
			case 2:
				cout<<"Goodbye!";
				check = false;
				break;
			default:
				cout<<"Incorrect option. Please try again."<<endl;
		}
	}
	
	return 0;
}
