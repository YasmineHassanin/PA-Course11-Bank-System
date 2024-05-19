#pragma once
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include"ClsUser.h"
#include<iostream>
using namespace std;
class ClsFindUserScreen :protected ClsScreen
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen\n");
		cout << "Please enetr the username to Update\n";
		string username = "";
		username = ClsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(username))
		{
			cout << "Error This User not exist,try Another one\n";
			username = ClsInputValidate::ReadString();
		}
		ClsUser user = ClsUser::Find(username);
		if(!user.IsEmpty())
		{
			cout << "User found\n";
		}
		else
		{
			cout << "User Was not found\n";
		}
		_PrintUser(user);
	}
};

