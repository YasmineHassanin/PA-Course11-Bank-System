#pragma once
#include "ClsScreen.h"
#include<iostream>
#include<iomanip>
#include<string>
#include"ClsUser.h"
using namespace std;
class ClsListUsersScreen :protected ClsScreen
{
private:
	static void _PrintUserRecordLine(ClsUser User)
	{
		cout << setw(8) << left << "" << "|" << setw(15) << left << User.username ;
		cout << "|" << setw(20) << left << User.FullName();
		cout << "|" << setw(12) << left << User.Email;
		cout << "|" << setw(20) << left << User.Phone;
		cout << "|" << setw(10) << left << User.password;
		cout << "|" << setw(12) << left << User.permission;
	}
public:
	static void ShowListUsersScreen()
	{
		system("cls");
		vector <ClsUser>VUsers;
		VUsers = ClsUser::GetUsersList();
		string title = "\tUsers List";
		string SubTitle = "\tUser( " + to_string(VUsers.size()) + ")";
		_DrawScreenHeader(title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "" << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "|" << left << setw(15) << "UserName";
		cout << "|" << setw(20) << "FullName";
		cout << "|" << setw(12) << "Phone";
		cout << "|" << setw(20) << "Email";
		cout << "|" << setw(10) << "Password";
		cout << "|" << setw(12) << "permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (VUsers.size() == 0)
		{
			cout << "No Users Are exist in the system\n";
		}
		else
			for(ClsUser U: VUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

