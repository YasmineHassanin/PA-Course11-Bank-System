#pragma once
#include "ClsScreen.h"
class ClsCurrencyClculatorScreen :protected ClsScreen
{
private:
	static ClsCurrencies _GetCurrency(string message)
	{
		cout << message << endl;
		string CurrencyCode = ClsInputValidate::ReadString();
		while (!ClsCurrencies::IsCurrencyExist(CurrencyCode))
		{
			cout << "Not Found \n";
			CurrencyCode = ClsInputValidate::ReadString();
		}
		ClsCurrencies Currency1 = ClsCurrencies::FindByCurrencyCode(CurrencyCode);
		return Currency1;
	}
	static float _ReadAmount()
	{
		float amount = 0.0;
		cout << "Please enter amount to exchange: ";
		amount = ClsInputValidate::ReadFloatNumber();
		return amount;
	}
	static void PrintCurrency(ClsCurrencies currency,string title="Currency card")
	{
		cout << "\n___________________________________\n";
		cout << title<<endl;
		cout << "Country : " << currency.GetCountryName() << endl;
		cout << "Code    :" << currency.GetCurrencyCode() << endl;
		cout << "Name    :" << currency.GetCurrencyName() << endl;
		cout << "Rate(1$):" << currency.Rate() << endl;
		cout << "___________________________________\n";
	}
	static void PrintCalculationResult(float amount,ClsCurrencies currencyfrom,ClsCurrencies currencyto)
	{
		PrintCurrency(currencyfrom, "Convert From:");
		float AmountInUSD = currencyfrom.ConvertToUSD(amount);
		cout << amount << " " << currencyfrom.GetCurrencyCode() << " = " << AmountInUSD <<" USD" << endl;
		if (currencyto.GetCurrencyCode() == "USD")
		{
			return;
		}
		cout << "Converting From USD : ";
		PrintCurrency(currencyto, "Convert to");
		float amountInCurrencyTo= currencyfrom.ConvertCurrencyToOtherCurrency(currencyto, amount);
		cout << amount << " " << currencyfrom.GetCurrencyCode() << " = " << amountInCurrencyTo <<currencyto.GetCurrencyCode() << endl;
	}
	
public:
	static void ShowCurrencyClculatorScreen()
	{
		char Continue = 'y';
		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Clculator screen\n");
			ClsCurrencies CurrencyFrom = _GetCurrency("Please enter currency1 code\n");
			ClsCurrencies CurrencyTo = _GetCurrency("Please enter currency2 code\n");
			float amount = _ReadAmount();
			cout << "Convert From:";
			PrintCalculationResult(amount, CurrencyFrom, CurrencyTo);
			cout << "Do you want to perform another clculation? y/n ?: ";
			cin >> Continue;
		}




	}
};

