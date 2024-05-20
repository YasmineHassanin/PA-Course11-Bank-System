#pragma once
#include "ClsScreen.h"
#include"ClsMainScreen.h"
#include"Global.h"
class ClsLoginScreen : protected ClsScreen
{
private:
	static bool _Login()
	{
		bool LoginFaild = false;
		string username, password;
		short FaildLoginCounter = 0;
		short numberOfTrials = 3;
		do
		{
			if (LoginFaild)
			{
				FaildLoginCounter++;
				cout << "Error Invalid username/password ! \n";
				cout << "You have " << numberOfTrials - FaildLoginCounter << " trials" << endl;
			}
			if (FaildLoginCounter == numberOfTrials)
			{
				cout << "You are blocked after three trials\n";
				return false;
			}
			cout << "Enter username: ";
			cin >> username;
			cout << "Enter password: ";
			cin >> password;
			CurrentUser = ClsUser::Find(username, password);
			LoginFaild = CurrentUser.IsEmpty();
		} while (LoginFaild);
		ClsMainScreen::ShowMainMenueScreen();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\tLogin Screen \n");
		return _Login();
	}
};

