#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include "Accounts.h"
#include "Admin.h"
#include "Official.h"
#include "User.h"
using namespace std;

/*
Driver for Team 2 CSC 232 final project Bear Bank.
Project done by Ethan Tanner, Ethan Dawley, and Christian Leslie
*/

string getDate(){
	time_t timeNow = time(0);   
    tm *localTime = localtime(&timeNow);
    return to_string(1 + localTime->tm_mon) +"/"+to_string(localTime->tm_mday)+"/"+ to_string(1900 + localTime->tm_year);
}

void fromFile(vector<Accounts> &logins){
	fstream file; string num; string pass; string name; string lastDate; string text;
	logins.clear();
	file.open("logins.txt");
	if(file){
		cout<<"Reading from file..."<<endl;
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
				string phone; string address;
				num = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				
				pass = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				
				name = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				
				lastDate = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				
				phone = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				
				address = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);
				
				User temp = User(num,pass,name,lastDate,phone,address);
				temp.fileInput(text);
				logins.push_back(temp);
			}
		}
	}
	file.close();
}

void updateFile(vector<Accounts> &logins){
	fstream file; file.open("logins.txt",fstream::trunc);
	cout<<"Updating file...\n";
	for(Accounts &i: logins){
		file<<i.printToFile()<<endl;
	}
	file.close();
	fromFile(logins);
}

void loginSearch(string number, string password, vector<Accounts> &logins, string date){
	for(Accounts &i: logins){
		if(number == i.getNumber() and password == i.getPassword()){
			cout<<"Logged in."<<endl;
			i.loggedIn(date, logins)
			updateFile(logins);
			return;
		}
	}
	cout<<"Login not found.\n";
	
}

main(){
	vector<Accounts> logins;
	
	string loginNum; string password;
	string date = getDate();
	cout<<date<<endl;
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
				loginSearch(loginNum,password,logins,date);
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
