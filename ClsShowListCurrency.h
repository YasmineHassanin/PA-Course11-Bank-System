#pragma once
#include "ClsScreen.h"
#include"ClsCurrencies.h"
#include<iostream>
using namespace std;
class ClsShowListCurrency : protected ClsScreen
{
private:
	static void _PrintCurrency(ClsCurrencies currency)
	{
		cout << setw(8) << left << "" << "|" << setw(30) << left << currency.GetCountryName();
		cout << "|" << setw(8) << left << currency.GetCurrencyCode();
		cout << "|" << setw(45) << left << currency.GetCurrencyName();
		cout << "|" << setw(10) << left << currency.Rate();
	}

public:
	static void ShowListCurrencyScreen()
	{
		vector<ClsCurrencies>Vcurrencies = ClsCurrencies::GetCurrenciesList();
		string title = "\t List Currency Screen\n";
		string subtitle = "\t(" + to_string(Vcurrencies.size()) + ") Currencies\n";
		_DrawScreenHeader(title, subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "" << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "|" << left << setw(30) << "Country Name";
		cout << "|" << setw(8) << "Currency code";
		cout << "|" << setw(45) << "Currency Name";
		cout << "|" << setw(10) << "Rate /(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (Vcurrencies.size() == 0)

			cout << "No currencies are exist in the system" << endl;

		else
		{
			for (ClsCurrencies currency : Vcurrencies)
			{
				_PrintCurrency(currency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;


	}
};

