#pragma once
#include "ClsScreen.h"
#include<iostream>
#include"ClsInputValidate.h"
#include<iomanip>
#include"ClsMainScreen.h"
#include"ClsListUsersScreen.h"
#include"ClsAddNewUserScreen.h"
#include"ClsDeleteUserScreen.h"
#include"ClsUpdateUserScreen.h"
#include"ClsFindUserScreen.h"
using namespace std;
class ClsManageUsersScreen :protected ClsScreen
{
private:
	enum _enManageusersOptions
	{
		eshowListUsers=1,eAddUser=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainmenu=6
	};
	static short ReadManageUsersOptions()
	{
		cout << "Please enter option between[1 to 6]\n";
		short choice = ClsInputValidate::ReadIntNumberBetween(1, 6, "This number is not between the range");
		return choice;
	}
	/*Stubs*/
	static void _ShowListUsers()
	{
		//cout << "Show list user screen  will be here\n";
		ClsListUsersScreen::ShowListUsersScreen();
	}
	static void _ShowAddUser()
	{
		//cout << "Add users screen will be here\n";
		ClsAddNewUserScreen::ShowAddNewUserScreen();
	}
	static void _ShowDeleteUser()
	{
		//cout << "Delete user screen will be here\n";
		ClsDeleteUserScreen::ShowDeleteUserScreen();
	}
	static void _ShowUpdateUser()
	{
		//cout << "Update user screen will be here\n";
		ClsUpdateUserScreen::ShowUpdateUsersScreen();
	}
	static void _ShowFindUser()
	{
		//cout << "Find user screen will be here\n";
		ClsFindUserScreen::ShowFindUserScreen();
	}
	static void _GoBackManageUsers()
	{
		cout << setw(37) << left << "" << "Press any key to back Manage users screen\n";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _PerformMenuOption(_enManageusersOptions option)
	{
		switch (option)
		{
		case _enManageusersOptions::eshowListUsers:
			system("cls");
			_ShowListUsers();
			_GoBackManageUsers();
			break;
		case _enManageusersOptions::eAddUser:
			system("cls");
			_ShowAddUser();
			_GoBackManageUsers();
			break;
		case _enManageusersOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUser();
			_GoBackManageUsers();
			break;
		case _enManageusersOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUser();
			_GoBackManageUsers();
			break;
		case _enManageusersOptions::eFindUser:
			system("cls");
			_ShowFindUser();
			_GoBackManageUsers();
			break;
		case _enManageusersOptions::eMainmenu:
		{
			/*Do nothing Main menue will handle it */
		}

		}
	}
public:
	static void ShowManageUsersScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tManage User Screen\n");
		cout << setw(37) << left << "" << "========================================\n";
		cout << setw(37) << left << "" << "\t\t Manage users Menu\n";
		cout << setw(37) << left << "" << "========================================\n";
		cout << setw(37) << left << "" << "[1] Show List Users\n";
		cout << setw(37) << left << "" << "[2] Show Add User Screen\n";
		cout << setw(37) << left << "" << "[3] Show Delete User Screen\n";
		cout << setw(37) << left << "" << "[4] Show Update User Screen\n";
		cout << setw(37) << left << "" << "[5] Show Find User Screen\n";
		cout << setw(37) << left << "" << "[6] Show Main Menue Screen\n";
		cout << setw(37) << left << "" << "========================================\n";
		_PerformMenuOption((_enManageusersOptions)ReadManageUsersOptions());
	}

};

