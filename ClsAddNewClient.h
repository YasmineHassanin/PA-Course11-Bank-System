#pragma once
#include "ClsScreen.h"
#include<iostream>
using namespace std;
class ClsAddNewClient :protected ClsScreen
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

	static void ShowAddNewClientListScreen()
	{
		if (!CheckAccessRights(ClsUser::enPermissions::eAddNewClients))
		{
			return;
		}
		_DrawScreenHeader("\tAdd New Clients screen\n");
			cout << "Please enter the account number you want to add\n";
			string AccountNumber = ClsInputValidate::ReadString();
			while (ClsBankClient::IsClientExist(AccountNumber))
			{
				cout << "Sorry But This Account is already exists,please enter the new account number " << endl;
				AccountNumber = ClsInputValidate::ReadString();
			}
			ClsBankClient NewClient = ClsBankClient::GetAddNewClient(AccountNumber);
			cout << "------------------------------------------------\n";
			cout << "Please enter the information of the client\n";
			cout << "-----------------------------------------------\n";
			ReadClientInfo(NewClient);
			ClsBankClient::enSaveResults SaveResults;
			SaveResults = NewClient.Save();
			switch (SaveResults)
			{
			case ClsBankClient::svSucceeded:
			{
				cout << "The Client Added successfully" << endl;
				_PrintClient(NewClient);
				break;
			}
			case ClsBankClient::svFaildEmptyObject:
			{
				cout << "The Client not saved cause it's empty " << endl;
				break;
			}
			case ClsBankClient::enSaveFailedClientAlreadyExist:
			{

				cout << "The Client not saved cause it's already exist" << endl;
				break;
			}
			}

		}
	
};

