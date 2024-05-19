#pragma once
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include"ClsUser.h"
#include<iostream>
using namespace std;
class ClsDeleteUserScreen : protected ClsScreen
{
private:
	static void _PrintUser(ClsUser user)
	{
		cout << "\n___________________\n";
		cout << "\nThe user card :";
		cout << "\nfirstname : " << user.FName;
		cout << "\nlastname  : " << user.LName;
		cout << "\nEmail     : " << user.Email;
		cout << "\nphone     : " << user.Phone;
		cout << "\nPassword  : " << user.password;
		cout << "\npermission: " << user.permission;
		cout << "\n___________________\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen\n");
		cout << "Please enetr the username of user you want to delete\n";
		string username = ClsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(username))
		{
			cout << "Error This User not exist already,try Another one\n";
			username = ClsInputValidate::ReadString();
		}
		ClsUser user = ClsUser::Find(username);
		_PrintUser(user);
		char answer = 'n';
		cout << "Do You sure to delete this User ? y/n:  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (user.DeleteUsers())
			{
				cout << "The User is Deleted successfully\n";
				_PrintUser(user);
			}
			else
			{
				cout << "Error User was not deleted\n";
			}
			
		}

	}
};

