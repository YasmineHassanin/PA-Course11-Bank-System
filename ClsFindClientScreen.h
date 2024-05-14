#pragma once
#include "ClsScreen.h"
#include"ClsBankClient.h"
#include<iostream>
using namespace std;
class ClsFindClientScreen :protected ClsScreen
{
private:
	static void _PrintClient(ClsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FName;
		cout << "\nLastName    : " << Client.LName;
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.GetAccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.accountBalnce;
		cout << "\n___________________\n";

	}
public:
	static void FindClientScreen()
	{
		_DrawScreenHeader("\tFind Clients screen\n");
		cout << "Please enter the account number you want to find\n";
		string AccountNumber = ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Sorry But This Account is not exists,please enter the new account number " << endl;
			AccountNumber = ClsInputValidate::ReadString();
		}
		ClsBankClient Client = ClsBankClient::Find(AccountNumber);
		if (!Client.IsEmpty())
		{
			cout << "Client is found\n";
		}
		else
		{
			cout << "Client was not found\n";
		}
		_PrintClient(Client);
}

};

