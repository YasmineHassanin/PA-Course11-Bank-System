#pragma once
#include<iostream>
#include<fstream>
#include"ClsInputValidate.h"
#include<string>
using namespace std;
class ClsCurrencies
{
private:

	enum enMode
	{
		emptyMode=0,UpdatedCurrency=1
	};
	enMode _Mode;

	string _CountryName;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	static ClsCurrencies _ConvertLineDataToCurrencyObject(string line,string separator= "#//#")
	{
		vector<string>Vcurrencies = ClsString::SplitString(line, separator);
		return ClsCurrencies(enMode::UpdatedCurrency, Vcurrencies[0], Vcurrencies[1], Vcurrencies[2],stod(Vcurrencies[3]));
	}
static	vector<ClsCurrencies>_LoadDataFromFile()
	{
		vector<ClsCurrencies>Vcurrencies;
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsCurrencies Currency = _ConvertLineDataToCurrencyObject(line, "#//#");
				Vcurrencies.push_back(Currency);
			}
			myfile.close();
		}
		return Vcurrencies;
	}
static string _ConvertCurrencyObjectToLine(ClsCurrencies Currency,string separator="#//#")
{
	string LineOfDataCurrency = "";
	LineOfDataCurrency += Currency.GetCountryName() + separator;
	LineOfDataCurrency += Currency.GetCurrencyCode() + separator;
	LineOfDataCurrency += Currency.GetCurrencyName() + separator;
	LineOfDataCurrency += to_string(Currency.Rate());
	return LineOfDataCurrency;
}
	static  void _SaveCurrencyDataToFile(vector<ClsCurrencies>Vcurrency)
	{
		fstream myfile;
		myfile.open("Currencies.txt", ios::out);
		string DataLine;
		if (myfile.is_open())
		{
			for (ClsCurrencies C : Vcurrency)
			{
				DataLine = _ConvertCurrencyObjectToLine(C);
				myfile << DataLine << endl;
			}
			myfile.close();
		}
	}
	 void _Updated()
	{
		vector<ClsCurrencies>Vcurrencies;
		Vcurrencies = _LoadDataFromFile();
		for (ClsCurrencies& C : Vcurrencies)
		{
			if (C.GetCurrencyCode() == GetCurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(Vcurrencies);
	}
	static ClsCurrencies _GetEmptyCurrencyObject()
	{
		return ClsCurrencies(enMode::emptyMode, "", "", "", 0);
    }
public:
	ClsCurrencies(enMode Mode,string CountryName,string CurrencyCode,string currencyName,float rate)
	{
		_Mode = Mode;
		_CountryName = CountryName;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = currencyName;
		_Rate = rate;
	}
	string GetCountryName()
	{
		return _CountryName;
	}
	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	void UpdatedRate(float NewRate)
	{
		_Rate = NewRate;
		_Updated();
	}
	float Rate()
	{
		return _Rate;
	}
	bool IsEmpty()
	{
		return (_Mode == enMode::emptyMode);
	}
	static ClsCurrencies FindByCurrencyCode(string CurrencyCode)
	{
		CurrencyCode = ClsString::UpperAllString(CurrencyCode);
		
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if(myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsCurrencies Currency = _ConvertLineDataToCurrencyObject(line);
				if (Currency.GetCurrencyCode() == CurrencyCode)
				{
					myfile.close();
					return Currency;
				}
			}
			
			myfile.close();

		}
		_GetEmptyCurrencyObject();
	}
	static ClsCurrencies FindByCountry(string CountryName)
	{
		CountryName = ClsString::UpperAllString(CountryName);
		fstream myfile;
		myfile.open("Currencies.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsCurrencies Currency = _ConvertLineDataToCurrencyObject(line);
				if (ClsString::UpperAllString( Currency.GetCountryName()) == CountryName)
				{
					myfile.close();
					return Currency;
				}
			}

			myfile.close();

		}
		_GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string currencyCode)
	{
		ClsCurrencies C1 = ClsCurrencies::FindByCurrencyCode(currencyCode);
		return (!C1.IsEmpty());
	}
	static vector<ClsCurrencies>GetCurrenciesList()
	{
		return _LoadDataFromFile();
	}
	 float ConvertToUSD(float amount)
	{
		return (float)amount/Rate();
	}
	 float ConvertCurrencyToOtherCurrency(ClsCurrencies currencyTo, float amount)
	 {
		 float AmountInUSD = ConvertToUSD(amount);
		 if (currencyTo.GetCurrencyCode() == "USD")
		 {
			 return AmountInUSD;
		 }
		 else
		 {
			 return  (float)(AmountInUSD * currencyTo.Rate());
		 }
		
		 
	 }
};

