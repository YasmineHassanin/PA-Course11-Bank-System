#pragma once
#include "ClsScreen.h"
#include"ClsCurrencies.h"
#include<iostream>
using namespace std;
class ClsFindCurrencyScreen :protected ClsScreen
{
private:
	
	static void PrintCurrency(ClsCurrencies currency)
	{
		cout << "\n___________________________________\n";
		cout << "Currency Card: \n";
		cout << "Country : " << currency.GetCountryName() << endl;
		cout << "Code    :"<<currency.GetCurrencyCode()<<endl ;
		cout << "Name    :"<<currency.GetCurrencyName() <<endl;
		cout << "Rate(1$):"<<currency.Rate()<<endl ;
		cout << "___________________________________\n";
	}
	static void ShowResult(ClsCurrencies currency)
	{
		if (!currency.IsEmpty())
		{
			cout << "The Currency found : ";
			PrintCurrency(currency);
		}
		else
		{
			cout << "The currency was not found\n";
		}
	}
public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency screen\n");
		cout << "Find By: [1]Code or [2]Country? :";
		short option = 0;
		cin >> option;
		if(option==1)
		{
			cout << "Please enter Currency code: ";
			string cuurencyCode = ClsInputValidate::ReadString();
			ClsCurrencies Currency1 = ClsCurrencies::FindByCurrencyCode(cuurencyCode);
			ShowResult(Currency1);
		}
		else
		{
			cout << "Please enter Country Name: ";
			string Country = ClsInputValidate::ReadString();
			ClsCurrencies Currency2= ClsCurrencies::FindByCountry(Country);
			ShowResult(Currency2);
		}
	}
};

