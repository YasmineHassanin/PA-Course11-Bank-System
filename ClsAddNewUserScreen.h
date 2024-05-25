#pragma once
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include"ClsUser.h"
class ClsAddNewUserScreen :protected ClsScreen
{
private:
	static void _ReadUserInfo(ClsUser& user)
	{
		cout << "please enter FirstName: ";
		user.FName= ClsInputValidate::ReadString();
		cout << "please enter LastName: ";
		user.LName = ClsInputValidate::ReadString();
		cout << "please enter email: ";
		user.Email = ClsInputValidate::ReadString();
		cout << "please enter phone: ";
		user.Phone = ClsInputValidate::ReadString();
		cout << "please enter password: ";
		user.password = ClsInputValidate::ReadString();
		cout << "please enter permissions: ";
		user.permission = _ReadPermissionToSet();	
	}
   static	void _PrintUser(ClsUser user)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << user.FName;
		cout << "\nLastName    : " << user.LName;
		cout << "\nEmail       : " << user.Email;
		cout << "\nPhone       : " << user.Phone;
		cout << "\nusername    :" << user.username;
		cout << "\nPassword    : " << user.password;
		cout << "\nPermission  : " << user.permission;
		cout << "\n___________________\n";

	}
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
public:
	static void ShowAddNewUserScreen()
	{

		_DrawScreenHeader("\tAdd New User Screen\n");
		cout << "Please enter the user name that you want to add \n";
		string username = ClsInputValidate::ReadString();
		while (ClsUser::IsUserExist(username))
		{
			cout << "Sorry,This user Is already exist,try with another one\n";
			username= ClsInputValidate::ReadString();
		}
		ClsUser user = ClsUser::GetAddNewUser(username);
		_ReadUserInfo(user);/*will take info user and store it in user object using GetAddnewUser()*/
		ClsUser::enSaveResults saveResults;
		saveResults = user.Save();
		switch (saveResults)
		{
		case ClsUser::enSaveResults::svSucceeded:
		{
			cout << "User added successfully\n";
			_PrintUser(user);
			break;
		}
		case ClsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "Error User not saved cause it's empty!\n";
			break;
		}
		case ClsUser::enSaveResults::enSaveFaileduserAlreadyExist:
		{
			cout << "User not Saved Cause this username is used\n";
			break;
		}
			
		}
	}
};

