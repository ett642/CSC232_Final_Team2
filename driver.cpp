#include <iostream>
#include <string>
#include <vector>
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

main(){
	int loginNum; string password; string date;
	int month; int day; int year;
	cout<<"Enter today's date (MM/DD/YYYY): ";
	cin>>date;
	getDate(date, &month, &day, &year);
	
	cout<<"Welcome to Bear Bank!\n[1] Login\n[2] Create Account\n[3] Exit"<<endl;
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
				cout<<"Create account code"<<endl;
				break;
			case 3:
				cout<<"Goodbye!";
				check = false;
				break;
			default:
				cout<<"Incorrect option. Please try again."<<endl;
		}
	}
	
	return 0;
}