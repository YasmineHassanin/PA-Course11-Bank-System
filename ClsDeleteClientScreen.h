#pragma once
#include "ClsScreen.h"
#include"ClsInputValidate.h"
#include"ClsBankClient.h"
#include<iostream>
using namespace std;
class ClsDeleteClientScreen :protected ClsScreen
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
	static void DeleteCientScreen()
{
		_DrawScreenHeader("\tDelete Clients Screen\n");
	cout << "Please enter the accountNumber you want to delete: " << endl;
	string accountNumber = ClsInputValidate::ReadString();
	while (!ClsBankClient::IsClientExist(accountNumber))
	{
		cout << "Sorry this Accountnumber is not found,Please enter trh another one" << endl;
		accountNumber = ClsInputValidate::ReadString();
	}
	ClsBankClient Client = ClsBankClient::Find(accountNumber);
	_PrintClient(Client);
	cout << "Are you sure you want to delete this account number?" << endl;
	char answer = 'n';
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (Client.Delete())
		{
			cout << "The Client deleted successfully" << endl;
			_PrintClient(Client);
		}
		else
		{
			cout << "Error Client was not deleted!" << endl;
		}
	}


}
};

