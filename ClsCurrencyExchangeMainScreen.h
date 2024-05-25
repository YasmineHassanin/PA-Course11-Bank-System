#pragma once
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include<iostream>
#include"ClsMainScreen.h"
#include"ClsShowListCurrency.h"
using namespace std;
class ClsCurrencyExchangeMainScreen : protected ClsScreen
{
private:
	enum enCurrencyOption
	{
		eListCurrencies=1,eFindCurrencies=2,eUpdateCurrencies=3,eCurrencyCalculator=4,eMainMenue=5
	};
	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Please choose what do you want to do from[1 to 5]" << endl;
		short choice = ClsInputValidate::ReadIntNumberBetween(1, 5, "Error,this number is not between the range");
		return choice;
	}
	static void GoBackToCurrencyScreen()
	{
		cout << setw(37) << left << "press any key to back main currency screen\n";
		system("pause>0");
		ShowCurrencyScreen();
	}
	
	static void  _ShowListCurrency()
	{
		//cout << "code of list currency will be here\n";
		ClsShowListCurrency::ShowListCurrencyScreen();
	}
	static void _ShowFindCurrency()
	{
		cout << "code of find currency will be here\n";
	}
	static void _ShowUpdateCurrency()
	{
		cout << "code of update currency will be here\n";
	}
	static void _ShowCurrencyCalculator()
	{
		cout << "code of show currency calculator will be here\n";
	}
	static void PerformCurrencyExchangeOption(enCurrencyOption option)
	{
		switch (option)
		{
		case enCurrencyOption::eListCurrencies:
			system("cls");
			_ShowListCurrency();
			GoBackToCurrencyScreen();
			break;
		case enCurrencyOption::eFindCurrencies:
			system("cls");
			_ShowFindCurrency();
			GoBackToCurrencyScreen();
			break;
		case enCurrencyOption::eUpdateCurrencies:
			system("cls");
			_ShowUpdateCurrency();
			GoBackToCurrencyScreen();
			break;
		case enCurrencyOption::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculator();
			GoBackToCurrencyScreen();
			break;
		case enCurrencyOption::eMainMenue:
		{
			//Do nothing 
		}
			
		}
	}
public:
	static void ShowCurrencyScreen()
	{
		system("cls");
		_DrawScreenHeader("\t Currency Exchange Screen\n");
		cout << setw(37) << left << "" << "=================================\n";
		cout << setw(37) << "" << left << "\t\t Main menue\n";
		cout << setw(37) << left << "" << "==================================\n";
		cout << setw(37) << left << "" << "[1] List Currencies" << endl;
		cout << setw(37) << left << "" << "[2]Find Currencies" << endl;
		cout << setw(37) << left << "" << "[3]Update Currencies" << endl;
		cout << setw(37) << left << "" << "[4]Currency Calculator" << endl;
		cout << setw(37) << left << "" << "[5]Main menue" << endl;
		cout << setw(37) << left << "" << "==================================\n";
		PerformCurrencyExchangeOption((enCurrencyOption)_ReadMainMenueOption());
	}

};

