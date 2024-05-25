// PA-Course11-Bank-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include"ClsMainScreen.h"
//#include"ClsLoginScreen.h"
#include"ClsCurrencies.h"
//#include"ClsUser.h"
using namespace std;

static void Print(ClsCurrencies Currency)
{
	cout << "\nCurrency Card:\n";
	cout << "_____________________________\n";
	cout << "\nCountry    : " << Currency.GetCountryName();
	cout << "\nCode       : " << Currency.GetCurrencyCode();
	cout << "\nName       : " << Currency.GetCurrencyName();
	cout << "\nRate(1$) = : " << Currency.Rate();

	cout << "\n_____________________________\n";

}
int main()
{
	
		ClsCurrencies CurrencyObj1 = CurrencyObj1.FindByCurrencyCode("USD");
		if (CurrencyObj1.IsEmpty())
		{
			cout << "NotFound\n";
		}
		else
		{
			Print(CurrencyObj1);
		}
		ClsCurrencies CurrencyObj2 = CurrencyObj2.FindByCountry("egypt");
		if (CurrencyObj2.IsEmpty())
		{
			cout << "Not found\n";
		}
		else
		{
			Print(CurrencyObj2);
		}
		cout << "After Updating: ";
		CurrencyObj2.UpdatedRate(30);
		Print(CurrencyObj2);

	system("pause>0");
	return 0;


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
