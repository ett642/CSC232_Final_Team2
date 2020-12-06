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

void fromFile(vector<Admin> &admin, vector<Official> &official, vector<User> &user){
	ifstream file; string num; string pass; string name; string lastDate; string info;
	admin.clear();
	official.clear();
	user.clear();
	file.open("logins.txt");
	if(file){
		cout<<"Reading from file..."<<endl;
		while(getline(file,info)){
			if(info[0] == '0'){
				string text = info;
				num = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);

				pass = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);

				name = text.substr(0, text.find("*"));
				text = text.substr(text.find("*")+1);

				lastDate = text;
				Admin temp = Admin(num,pass,name,lastDate);
				admin.push_back(temp);
			}
			else if(info[0] == '1'){
				string status; string text = info;
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
				official.push_back(temp);
			}
			else{
				string phone; string address; string text = info;
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
				user.push_back(temp);
			}
		}
	}
	file.close();
}

void updateFile(vector<Admin> &admin, vector<Official> &official, vector<User> &user){
	ofstream file; file.open("logins.txt",ofstream::trunc);
	cout<<endl<<"Updating file...\n";
	for(Admin &i: admin){
		file<<i.printToFile()<<endl;
	}
	for(Official &i: official){
		file<<i.printToFile()<<endl;
	}
	for(User &i: user){
		file<<i.printToFile()<<endl;
	}
	file.close();
	fromFile(admin,official,user);
}

void loginSearch(string number, string password, vector<Admin> &admin, vector<Official> &official, vector<User> &user, string date){
		if(number[0] == '0'){
			for(Admin &i: admin){
				if(number == i.getNumber() and password == i.getPassword()){
				cout<<"Logged in."<<endl;
				i.loggedIn(date, official, user);
				updateFile(admin,official,user);
				return;
				}
			}
		}
		else if(number[0] == '1'){
			for(Official &i: official){
				if(number == i.getNumber() and password == i.getPassword()){
				cout<<"Logged in."<<endl;
				i.loggedIn(date, user);
				updateFile(admin,official,user);
				return;
				}
			}
		}
		else{
			for(User &i: user){
				if(number == i.getNumber() and password == i.getPassword()){
				cout<<"Logged in."<<endl;
				i.loggedIn(date);
				updateFile(admin,official,user);
				return;
				}
			}
		}
	cout<<"Login not found.\n";
	
}

main(){
	vector<Admin> admin;
	vector<Official> official;
	vector<User> user;
	
	
	string loginNum; string password;
	string date = getDate();
	cout<<date<<endl;
	fromFile(admin, official, user);
	
	bool check = true;
	while(check){
		cout<<endl<<"Welcome to Bear Bank!\n[1] Login\n[2] Exit"<<endl;
		cout<<endl<<"Choose an option: ";
		int option; cin>>option;
		switch(option){
			case 1:
				cout<<"Enter your login number: ";
				cin>>loginNum;
				cout<<"Enter your login password: ";
				cin>>password;
				loginSearch(loginNum,password,admin,official,user,date);
				continue;
			case 2:
				cout<<"Goodbye!";
				check = false;
				continue;
			default:
				cout<<"Incorrect option. Please try again."<<endl;
				cin.clear();
                cin.ignore();
                continue;
		}
	}
	
	return 0;
}
