#pragma once
#include "ClsScreen.h"
#include"ClsBankClient.h"
#include<iostream>
using namespace std;
class ClsWithdrawScreen :protected ClsScreen
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

	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("\tWithDraw Screen\n");
		cout << "\nPlease enter the Account Number you want\n";
		string accountnumber = ClsInputValidate::ReadString();
		while (!ClsBankClient::IsClientExist(accountnumber))
		{
			cout << "Sorry this Client is not found,please enter another account number\n";
			accountnumber = ClsInputValidate::ReadString();
		}
		ClsBankClient Client = ClsBankClient::Find(accountnumber);
		_PrintClient(Client);
		cout << "Please enter the Withdraw Amount \n";
		double Amount = 0;
		Amount = ClsInputValidate::ReadDblNumber();
		cout << "Are you sure you want to perform this transaction?\n";
		char answer = 'n';
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (Client.WithDraw(Amount))
			{
				cout << "\nThis Amount withdrawed successfully\n";
				cout << "The Updated new balance after transaction is : " << Client.accountBalnce << endl;
			}
			else
			{
				cout << "Cannot withdraw, InSuffecient Balance\n";
				cout << "The Amount you want is : " << Amount;
				cout << "\nYour Balance is " << Client.accountBalnce << endl;
			}
		}
		else
		{
			cout << "Error this operation is Failed\n";
		}

	}
};

