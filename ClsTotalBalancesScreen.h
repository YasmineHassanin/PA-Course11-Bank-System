#pragma once
#include "ClsScreen.h"
#include"ClsBankClient.h"
#include"Clsutil.h"
#include<iostream>
using namespace std;
class ClsTotalBalancesScreen :protected ClsScreen
{
private:
	static void PrintClientRecordTotalBalance(ClsBankClient Client)
	{
		cout << "|" << setw(15) << left << Client.GetAccountNumber();
		cout << "|" << setw(20) << left << Client.FullName();
		cout << "|" << setw(12) << left << Client.accountBalnce;
	}
public:
	 static void ShowTotalBalanceScreen()
	{
		vector<ClsBankClient>Vclients = ClsBankClient::GetClientsList();
		string Title = "\tTotal BAlances Screen\n";
		string subtitle = "\tClients List ( " +to_string( Vclients.size()) + ") Client\n";
		_DrawScreenHeader(Title,subtitle);
		
		cout << setw(25) << left << "" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout <<setw(25)<<left<<"" <<"|" << setw(15) << "Account Number";
		cout << "|" << setw(40) << "Client Name";
		cout << "|" << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		double ToatalBalance = ClsBankClient::GetTotalBalance();
		if (Vclients.size() == 0)

			cout << "No clients are exist in the system" << endl;

		else
		{
			for (ClsBankClient Client : Vclients)
			{
				PrintClientRecordTotalBalance(Client);
				cout << endl;
			}
		}
		cout << setw(25) << left << "" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout <<setw(8)<<left<<""<<"\n\t\t\t\t\tTotal Balance = : " << ToatalBalance << endl;
		cout <<setw(8)<<left<<""<< "\t\t\t ( " << Clsutil::NumberToText(ToatalBalance) << " )" << endl;

	}
};

