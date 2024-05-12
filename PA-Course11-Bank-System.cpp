// PA-Course11-Bank-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"ClsBankClient.h"
using namespace std;

void PrintClientRecordLine(ClsBankClient Client)
{
	cout << "|" << setw(15) << left << Client.GetAccountNumber();
	cout << "|" << setw(20) << left << Client.FullName() ;
	cout << "|" << setw(12) << left << Client.Phone;
	cout << "|" << setw(20) << left << Client.Email;
	cout << "|" << setw(10) << left << Client.PinCode;
	cout << "|" << setw(12) << left << Client.accountBalnce;
}
void PrintClientRecordTotalBalance(ClsBankClient Client)
{
	cout << "|" << setw(15) << left << Client.GetAccountNumber();
	cout << "|" << setw(20) << left << Client.FullName();
	cout << "|" << setw(12) << left << Client.accountBalnce;
}
ClsBankClient ReadClientInfo(ClsBankClient& Client)
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
void UpdateClient()
{
	cout << "Please enter The Account Number You Want :  ";
	string AccountNumber = ClsInputValidate::ReadString();
	while (!ClsBankClient::IsClientExist(AccountNumber))
	{
		cout << "This Client is Not Exist ,please try again : " << endl;
		AccountNumber = ClsInputValidate::ReadString();
	}
	ClsBankClient Client = ClsBankClient::Find(AccountNumber);
	Client.Print();
	cout << "---------------------------------------------\n";
	cout << "Update the Information Of Client : " << endl;
	cout << "----------------------------------------------\n";
	ReadClientInfo(Client);
	ClsBankClient::enSaveResults SaveResult;
	SaveResult = Client.Save();
	switch (SaveResult)
	{
	case ClsBankClient::svSucceeded:
		cout << "Account Updated Successfully\n";
		Client.Print();
		break;
	case ClsBankClient::svFaildEmptyObject:
		cout << "Faild Updated !" << endl;
		break;
		
	}
}
void AddNewClient()
{
	
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
		NewClient.Print();
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
void DeleteCient()
{
	
	cout << "Please enter the accountNumber you want to delete: " << endl;
	string accountNumber = ClsInputValidate::ReadString();
	while (!ClsBankClient::IsClientExist(accountNumber))
	{
		cout << "Sorry this Accountnumber is not found,Please enter trh another one" << endl;
		accountNumber = ClsInputValidate::ReadString();
	}
	ClsBankClient Client = ClsBankClient::Find(accountNumber);
	Client.Print();
	cout << "Are you sure you want to delete this account number?" << endl;
	char answer = 'n';
	cin >> answer;
	if (answer == 'y' || answer == 'Y')
	{
		if (Client.Delete())
		{
			cout << "The Client deleted successfully" << endl;
			Client.Print();
		}
		else
		{
			cout << "Error Client was not deleted!" << endl;
		}
	}


}
void ListClients()
{
	vector<ClsBankClient>Vclients = ClsBankClient::GetClientsList();
	cout << "\t\t\t\tClients List ( " << Vclients.size() << ") Client\t\t\t\t" << endl;
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "|" << setw(15) << "Account Number";
	cout << "|" << setw(20) << "Client Name";
	cout << "|" << setw(12) << "Phone" ;
	cout << "|" << setw(20) << "Email" ;
	cout << "|" << setw(10) << "PinCode";
	cout << "|" << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
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
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	
}
void ShowClientBalances()
{
		vector<ClsBankClient>Vclients = ClsBankClient::GetClientsList();
		cout << "\t\t\t\tClients List ( " << Vclients.size() << ") Client\t\t\t\t" << endl;
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "|" << setw(15) << "Account Number";
		cout << "|" << setw(20) << "Client Name";
		cout << "|" << setw(12) << "Balance";
		cout << "\n_______________________________________________________";
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
		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << "\t\t\tTotal Balance = : " << ToatalBalance << endl;
		cout << "\t\t\t ( " << Clsutil::NumberToText(ToatalBalance) << " )" << endl;

}
int main()
{

	//UpdateClient();
	//AddNewClient();
	//DeleteCient();
	ShowClientBalances();
	system("pause>0");
	return 0;



	/*ClsBankClient Client1= ClsBankClient::Find("A101");
	Client1.Print();
	ClsBankClient Client2 = ClsBankClient::Find("A101", "1239");
	Client2.Print();
	cout << endl;
	cout << "Is Client Exist: " << endl;
	cout<<Client2.IsClientExist("A108");*/
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
