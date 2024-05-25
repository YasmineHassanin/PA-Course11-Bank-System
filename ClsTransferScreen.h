#pragma once
#include "ClsScreen.h"
#include<iostream>
#include"ClsBankClient.h"
#include"ClsInputValidate.h"
using namespace std;
class ClsTransferScreen :protected ClsScreen
{
private:
		static void _PrintClient(ClsBankClient Client)
		{
			cout << "\nClient Card : ";
			cout << "\nFull Name     : " << Client.FullName();
			cout << "\nAcc. Number : " << Client.GetAccountNumber();
			cout << "\nBalance     : " << Client.accountBalnce;
			cout << "\n_____________________\n";
		}
		static string _ReadAccountNumber()
		{
			string AccountNumber = "";
			cout<< "Please enter the Account Number : ";
		 AccountNumber = ClsInputValidate::ReadString();
			if (!ClsBankClient::IsClientExist(AccountNumber))
			{
				cout << "This AccountNumber is not exist,try with another one\n";
				AccountNumber = ClsInputValidate::ReadString();
			}
			return AccountNumber;
		}
		static float _ReadAmount(ClsBankClient SourceClient)
		{
			float amount = 0;
			cout << "please enter Transfer amount\n";
			amount = ClsInputValidate::ReadFloatNumber();
			if (amount > SourceClient.accountBalnce)
			{
				cout << "Amount exceeds the available Balance,enter another amount\n ";
				amount = ClsInputValidate::ReadFloatNumber();
			}
			return amount;
		}
public:
	static void ShowTransferScreen()
	{
		char answer = 'n';
		_DrawScreenHeader("\tTransfer Screen\n");
		ClsBankClient SourceClient = ClsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);
		ClsBankClient DestinationClient = ClsBankClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);
		float Amount = _ReadAmount(SourceClient);
		cout << "Are you sure you want to perform this operation? : ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.username))
			{
				cout << "\nTransfer done successfully\n ";
			}
			else
			{
				cout << "Transfer Failed\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}
};

