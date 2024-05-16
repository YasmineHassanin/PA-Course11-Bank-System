#pragma once
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include"ClsMainScreen.h"
#include"ClsDepositScreen.h"
#include"ClsWithdrawScreen.h"
#include"ClsTotalBalancesScreen.h"
#include<iomanip>
#include<iostream>
using namespace std;
class ClsTransactionScreen :protected ClsScreen
{
private:
	enum enTransactionOption{Deposite=1,withdraw=2,TotalBalance=3,Mainmenue=4};
	static short ReadTransactionMainMenu()
	{
		cout << setw(37) << left << "" << "Choose number between [1 to 4]" << endl;
		short choice = ClsInputValidate::ReadIntNumberBetween(1, 4, "Sorry this number is not found\n");
		return choice;
	}
	static void _ShowDepositScreen()
	{
		//cout << "Deposite Screen will be here\n";
		ClsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		//cout << "Withdraw Screen will be here\n";
		ClsWithdrawScreen::ShowWithDrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		//cout << "TotalBalance Screen will be here\n";
		ClsTotalBalancesScreen::ShowTotalBalanceScreen();
	}
	static void _GoBackTransactionScreen()
	{
		cout << setw(37) << left << "" << "Press any key to back to Transaction menu\n";
		system("pause>0");
		ShowTransactionScreen();
	}
	static void _PerformTransactionOption(enTransactionOption option)
	{
		switch (option)
		{
		case enTransactionOption::Deposite:
			system("cls");
			_ShowDepositScreen();
			_GoBackTransactionScreen();
			break;
		case enTransactionOption::withdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackTransactionScreen();
			break;
		case enTransactionOption::TotalBalance:
			system("cls");
			_ShowTotalBalanceScreen();
			_GoBackTransactionScreen();
			break;
		case enTransactionOption::Mainmenue:
		{
			/*Do nothing here main screen will handle it :)*/
		}
		}
	}

public:
	static void ShowTransactionScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Transaction screen\n");
		cout << setw(37) << left << "" << "=====================================\n";
		cout << setw(37) << left << "" << "\t\t Transaction Screen\n";
		cout << setw(37) << left << "" << "=====================================\n";
		cout << setw(37) << left << "" << "[1] Deposit Screen \n";
		cout << setw(37) << left << "" << "[2] WithDrawScreen\n";
		cout << setw(37) << left << "" << "[3] TotalBalanceScreen\n";
		cout << setw(37) << left << "" << "[4] GoBackMainMenuScreen\n";
		cout << setw(37) << left << "" << "=====================================\n";
		_PerformTransactionOption((enTransactionOption)ReadTransactionMainMenu());
	}

		
};

