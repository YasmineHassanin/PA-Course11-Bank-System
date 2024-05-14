#pragma once
#include "ClsScreen.h"
#include"ClsBankClient.h"
#include<iostream>
using namespace std;
class ClsUpdateClientScreen : protected ClsScreen
{
private:
	static ClsBankClient ReadClientInfo(ClsBankClient& Client)
	{
		cout << "Please Start To Update The FirstName: ";
		Client.FName = ClsInputValidate::ReadString();
		cout << "Please Update The LastName: ";
		Client.LName = ClsInputValidate::ReadString();
		cout << "Please Update an Email: ";
		Client.Email = ClsInputValidate::ReadString();
		cout << "Please Update The Phone Number : ";
		Client.Phone = ClsInputValidate::ReadString();
		cout << "Please Update The Pin Code: ";
		Client.PinCode = ClsInputValidate::ReadString();
		cout << "Please Update The Account Balance: ";
		Client.accountBalnce = ClsInputValidate::ReadFloatNumber();
		return Client;

	}
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
	static void UpdateClientScreen()
	{
		_DrawScreenHeader("\tUpdate Clients Screen\n");
			cout << "Please enter The Account Number You Want :  ";
			string AccountNumber = ClsInputValidate::ReadString();
			while (!ClsBankClient::IsClientExist(AccountNumber))
			{
				cout << "This Client is Not Exist ,please try again : " << endl;
				AccountNumber = ClsInputValidate::ReadString();
			}
			ClsBankClient Client = ClsBankClient::Find(AccountNumber);
			_PrintClient(Client);
			cout << "\nAre you sure you want to update this client y/n? ";

			char Answer = 'n';
			cin >> Answer;

			if (Answer == 'y' || Answer == 'Y')
			{

				cout << "\n\nUpdate Client Info:";
				cout << "\n____________________\n";
			ReadClientInfo(Client);
			ClsBankClient::enSaveResults SaveResult;
			SaveResult = Client.Save();
			switch (SaveResult)
			{
			case ClsBankClient::svSucceeded:
				cout << "Account Updated Successfully\n";
				_PrintClient(Client);
				break;
			case ClsBankClient::svFaildEmptyObject:
				cout << "Faild Updated !" << endl;
				break;
			}
			
		}
	}
};

