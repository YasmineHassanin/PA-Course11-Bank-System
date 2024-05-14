#pragma once
#include<iostream>
#include<iomanip>
#include"ClsBankClient.h"
#include"ClsScreen.h"
using namespace std;
class ClsShowClintsList:protected ClsScreen
{
private:
	static void PrintClientRecordLine(ClsBankClient Client)
{
	cout <<setw(8)<<left<<""<< "|" << setw(15) << left << Client.GetAccountNumber();
	cout << "|" << setw(20) << left << Client.FullName() ;
	cout << "|" << setw(12) << left << Client.Phone;
	cout << "|" << setw(20) << left << Client.Email;
	cout << "|" << setw(10) << left << Client.PinCode;
	cout << "|" << setw(12) << left << Client.accountBalnce;
}
public:
static void ShowListClients()
	{
		vector<ClsBankClient>Vclients = ClsBankClient::GetClientsList();
		string title = "\tClients list Screen\n";
		string subtitle = "\t ( " + (to_string(Vclients.size())) + " ) Clients\t";
		_DrawScreenHeader(title, subtitle);
		cout<< setw(8)<<left<<"" << "\n\t_______________________________________________________";
		cout << "" << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "|" << left<< setw(15) << "Account Number";
		cout << "|" << setw(20) << "Client Name";
		cout << "|" << setw(12) << "Phone" ;
		cout << "|" << setw(20) << "Email" ;
		cout << "|" << setw(10) << "PinCode";
		cout << "|" << setw(12) << "Balance";
		cout << setw(8) << left << ""<<"\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		
		if (Vclients.size() == 0)
		
			cout << "No clients are exist in the system" << endl;
	
		else
		{
			for (ClsBankClient Client : Vclients)
			{
				PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << setw(8) << left <<"" << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	
		
	}


};

