#pragma once
#include "ClsScreen.h"
class ClsUpdateCurrencyRateScreen :protected ClsScreen
{
private:

	static void PrintCurrency(ClsCurrencies currency)
	{
		cout << "\n___________________________________\n";
		cout << "Currency Card: \n";
		cout << "Country : " << currency.GetCountryName() << endl;
		cout << "Code    :" << currency.GetCurrencyCode() << endl;
		cout << "Name    :" << currency.GetCurrencyName() << endl;
		cout << "Rate(1$):" << currency.Rate() << endl;
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
	static float ReadRate()
	{
		float NewRate = 0;
		cout << "Enter new_rate: ";
		NewRate = ClsInputValidate::ReadFloatNumber();
		return NewRate;
	}
public:
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Rate Screen\n");
		string CurrencyCode = "";
		cout << "Please enter currency code: ";
        CurrencyCode = ClsInputValidate::ReadString();
		while (!ClsCurrencies::IsCurrencyExist(CurrencyCode))
		{
			cout << "This Currency is not found ,Please try again : ";
			CurrencyCode = ClsInputValidate::ReadString();
		}
		ClsCurrencies Currency1 = ClsCurrencies::FindByCurrencyCode(CurrencyCode);
		PrintCurrency(Currency1);
		cout << "Are you sure you want to update? : ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Currency1.UpdatedRate(ReadRate());
			cout << "Currency rate updated successfully\n";
			PrintCurrency(Currency1);
		}
		
		
		
		
	}
};

