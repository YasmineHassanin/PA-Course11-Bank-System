#pragma once
#include "ClsScreen.h"
#include"ClsMainScreen.h"
#include"Global.h"
class ClsLoginScreen : protected ClsScreen
{
private:
	static void _Login()
	{
		bool LoginFaild = false;
		string username, password;
		do
		{
			if (LoginFaild)
			{
				cout << "Error Invalid username/password ! \n";
			}
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			CurrentUser = ClsUser::Find(username, password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		ClsMainScreen::ShowMainMenueScreen();
	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen \n");
		_Login();
	}
};

