#pragma once
#include<iomanip>
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include"ClsShowClintsList.h"
#include"ClsAddNewClient.h"
#include"ClsDeleteClientScreen.h"
#include"ClsUpdateClientScreen.h"
#include"ClsFindClientScreen.h"
#include"ClsTransactionScreen.h"
#include"ClsManageUsersScreen.h"
#include"ClsLoginScreen.h"
#include"Global.h"

class ClsMainScreen : protected ClsScreen
{
private:
	enum enMainMenueOptions
	{
showClientList=1, Addnewclient=2, DeleteNewClient=3, UpdateClientinfo=4, FindClient=5, Transactions=6, ManageUsers=7, Logout=8
    };
static short _ReadMainMenueOption()
	{
		cout <<setw(37)<<left<< "" << "Please choose what do you want to do from[1 to 8]" << endl;
		short choice= ClsInputValidate::ReadIntNumberBetween(1, 8, "Error,this number is not between the range");
		return choice;
	}
static void _GoBackMainMenue()
{
	cout << setw(37) << left << "Press any key to go back main menue\n";
	system("pause>0");
	ShowMainMenueScreen();
}
static void _ShowClientsScreen()
{
	//cout << "\nClients list screen will be here ...\n";
	ClsShowClintsList::ShowListClients();
}
static void _AddNewClientScrren()
{
	//cout << "\nAdd new client screen will be here....\n";
	ClsAddNewClient::ShowAddNewClientListScreen();
}
static void _DeleteClientScreen()
{
	//cout << "\nDelete client screen will be here...\n";
	ClsDeleteClientScreen::DeleteCientScreen();
}
static void _UpdateClientScreen()
{
	//cout << "\nUpdate client screen will be here...\n";
	ClsUpdateClientScreen::UpdateClientScreen();
}
static void _FindClientScreen()
{
	//cout << "\n Find Screen screen will be here ...\n";
	ClsFindClientScreen::FindClientScreen();
}
static void _TransactionScreen()
{
	//cout << "\n Transaction screen will be here ...\n";
	ClsTransactionScreen::ShowTransactionScreen();
}
static void _ManageUsersScreen()
{
	//cout << "\nManage users screen will be here...\n";
	ClsManageUsersScreen::ShowManageUsersScreen();
}
//static void _ShowEndScreen()
//{
//	cout << "\nEnd Screen will be here...\n";
//}
static void _Logout()
{
	CurrentUser = ClsUser::Find("", "");
}
static void _PerformMainMenueOption(enMainMenueOptions option)
{
	switch (option)
	{
	case enMainMenueOptions::showClientList:
		system("cls");
		_ShowClientsScreen();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::Addnewclient:
		system("cls");
		_AddNewClientScrren();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::DeleteNewClient:
		system("cls");
		_DeleteClientScreen();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::UpdateClientinfo:
		system("cls");
		_UpdateClientScreen();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::FindClient:
		system("cls");
		_FindClientScreen();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::Transactions:
		system("cls");
		_TransactionScreen();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::ManageUsers:
		system("cls");
		_ManageUsersScreen();
		_GoBackMainMenue();
		break;
	case enMainMenueOptions::Logout:
		system("cls");
		_Logout();
			break;
	}

}
public:
	static void ShowMainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");

     cout << setw(37) << left <<"" << "=================================\n";
	 cout << setw(37) << "" << left << "\t\t Main menue\n";
	 cout << setw(37) << left << "" << "==================================\n";
     cout<<setw(37)<<left<<"" << "\t[1] Show Client List" << endl;
	 cout<<setw(37)<<left<<"" << "\t[2] Add new client" << endl;
	 cout<<setw(37)<<left<<""<<"\t[3] Delete New Client" << endl;
	 cout<<setw(37)<<left<<""<<"\t[4] Update Client info" << endl;
	 cout<<setw(37)<<left<<""<<"\t[5] Find Client" << endl;
	 cout<<setw(37)<<left<<""<<"\t[6] Transactions" << endl;
	 cout<<setw(37)<<left<<""<<"\t[7] Manage Users" << endl;
	 cout << setw(37) << left << "" << "\t[8] Logout" << endl;
	 cout << setw(37) << left << "" << "====================================\n";
	 _PerformMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
	}


};

