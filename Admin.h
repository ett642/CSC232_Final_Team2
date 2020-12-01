#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include "Accounts.h"
#include <limits>
using namespace std;

//Admin class represents the role of a banking administrator
//Admin is a child of parent class Accounts

class Admin : public Accounts
{
   public:
      //public variables
      
   //Default constructor
   Admin() : Accounts()
   {
   
   }
   //2nd constructor
   Admin(int num, string pass, string inName, string date): Accounts(num,pass,inName,date)
   {
   
   }
   
   //function for post login 
   
   //function to create a bank official login

   //function to enable a bank official login
   
   //function to disable a bank official login
   
   //function to create user account
   
   //function to delete user account
   
   //function to modify user account
   
   //function to change user password
