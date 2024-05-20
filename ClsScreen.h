#pragma once
#include<iostream>
#include<string>
#include"Global.h"
#include"ClsUser.h"
#include<string>
#include"ClsDateLibrary.h"
using namespace std;
class ClsScreen
{


protected:
	static void _DrawScreenHeader(string title,string subTitle="")
	{
		cout<<"\t\t\t\t__________________________________________________";
		cout << "\n\n\t\t\t\t" << title;
		if (subTitle != "")
		{
			cout << "\n\t\t\t\t"<<subTitle << endl;
		}
		cout << "\n\t\t\t\t________________________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.username;
		cout << "\n\t\t\t\t\tDate: " << ClsDateLibrary::DateToString(ClsDateLibrary());
		cout << endl;
	}
	static bool CheckAccessRights(ClsUser::enPermissions permission)
	{
		if (!CurrentUser.CheckAccessPrmissions(permission))
		{
			cout << "\t\t\t\t\t_________________________________________________";
			cout << "\n\n\t\t\t\t\tAccess Denaied!,Contact your Admin";
			cout << "\n\t\t\t\t\t_______________________________________________\n";
			return false;
		}
		else
		{
			return true;
		}
		
	}
	/*static void ShowLoggedInUser()
	{
		CurrentUser = ClsUser::Find(CurrentUser.username);
		cout <<"\t\t\t\t\tUser: " << CurrentUser.username;
		
	}
	static void ShowDateOfDay()
	{
		ClsDateLibrary Date;
		cout << "\n\t\t\t\t\tDate: " << ClsDateLibrary::DateToString(ClsDateLibrary());
		cout << "\n\t\t\t\t_______________________________________________\n";
	}*/
};

