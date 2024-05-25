#pragma once
#include "ClsScreen.h"
#include"ClsUser.h"
#include<iostream>
#include"ClsInputValidate.h"
using namespace std;
class ClsUpdateUserScreen :protected ClsScreen
{
	static int _ReadPermissionToSet()
	{
		int permission = 0;
		char answer = 'n';
		cout << "Do You want to give Full access y/n?: ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			return -1;
		}
		cout << "\nDo you want to give access to \n:";
		cout << "Show Clients List y/n?  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eShowListClients;
		}
		cout << "Add new Client y/n?  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eAddNewClients;
		}
		cout << "Delete Clients y/n?  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eDeleteClients;
		}
		cout << "Update Clients y/n?  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eUpdateClients;
		}
		cout << "Find Clients y/n?  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eFindClients;
		}
		cout << " Make Transactions y/n?  ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eTransaction;
		}
		cout << " Manage Users y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eManageUsers;
		}
		cout << " Login Register List y/n? ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			permission += ClsUser::enPermissions::eLoginRegister;
		}
		return permission;
	}
	static void _ReadUserInfo(ClsUser& user)
	{
		cout << "Please enter the firstname: ";
		user.FName = ClsInputValidate::ReadString();
		cout << "Please enter the Lastname: ";
		user.LName = ClsInputValidate::ReadString();
		cout << "Please enter the Email: ";
		user.Email = ClsInputValidate::ReadString();
		cout << "Please enter the Phone: ";
		user.Phone = ClsInputValidate::ReadString();
		cout << "Please enter the Password: ";
		user.password = ClsInputValidate::ReadString();
		cout << "Please enter the permissions: ";
		user.permission = _ReadPermissionToSet();
	}
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
	static void ShowUpdateUsersScreen()
	{
		_DrawScreenHeader("\t Update Users Screen\n");
		cout << "Please enetr the username to Update\n";
		string username = "";
		username = ClsInputValidate::ReadString();
		while (!ClsUser::IsUserExist(username))
		{
			cout << "Error This User not exist,try Another one\n";
			username = ClsInputValidate::ReadString();
		}
		ClsUser user = ClsUser::Find(username);
		_PrintUser(user);
		cout << "\nDo You sure to update this user ? y/n ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "\n\nUpdate user info: ";
			cout << "\n____________________\n";

			_ReadUserInfo(user);
			ClsUser::enSaveResults SaveResult;
			SaveResult = user.Save();
			switch (SaveResult)
			{
			case ClsUser::enSaveResults::svSucceeded:
			{
				cout << "User Updated successfully\n";
				_PrintUser(user);
				break;
			}
			case ClsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "Error User was not saved\n";
				break;
			}

			}
		}
	}
};

