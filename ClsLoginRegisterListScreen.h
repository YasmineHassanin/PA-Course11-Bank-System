#pragma once
#include "ClsScreen.h"
#include<iostream>
#include<string>
class ClsLoginRegisterListScreen :protected ClsScreen
{
private:
	static void PrintLoginUserRecordLine(ClsUser::stLoginRegisterRecord LogginRegisterLoggin)
	{
		cout << setw(8) << left << "" << "|" << setw(35) << left << LogginRegisterLoggin.DateTime;
		cout << "|" << setw(20) << left << LogginRegisterLoggin.Username;
		cout << "|" << setw(20) << left << LogginRegisterLoggin.Password;
		cout << "|" << setw(10) << left << LogginRegisterLoggin.permissions;
	}
public:
	static void ShowLogingRegisterScreen()
	{
		if (!CheckAccessRights(ClsUser::enPermissions::eLoginRegister))
		{
			return;
		}
		vector <ClsUser::stLoginRegisterRecord> VLoginRegisterRecord = ClsUser::GetLoginRegisterList();
		string title = "\tLogin Register List Screen\n";
		string subtitle = "\t\t(" + to_string(VLoginRegisterRecord.size()) + ") Record(s)\n";
		_DrawScreenHeader(title,subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "|" << left << setw(35) << "Date/Time";
		cout << "|" << left << setw(20) << "Username";
		cout << "|" << left << setw(20) << "Password" ;
		cout << "|" << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (VLoginRegisterRecord.size() == 0)
			cout << "\t\t\t\t No Logins available in the system\n";
		else
		{
			for (ClsUser::stLoginRegisterRecord LoginUser : VLoginRegisterRecord)
			{
				PrintLoginUserRecordLine(LoginUser);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

