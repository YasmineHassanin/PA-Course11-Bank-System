#pragma once
#include "ClsPerson.h"
#include"ClsInputValidate.h"
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
class ClsBankClient : public ClsPerson
{
	
private:
	enum enMode { EmptyMode = 0, UpdatedMode = 1,AddNew=2 };
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedToDelete = false;
	struct stTransferLogsData;
	static ClsBankClient _ConvertLineToClientObject(string Line,string Separator="#//#")
	{
		vector<string>Vclient;
		Vclient = ClsString::SplitString(Line, Separator);
		return ClsBankClient(enMode::UpdatedMode,Vclient[0], Vclient[1], Vclient[2], Vclient[3], Vclient[4], Vclient[5], stod(Vclient[6]));
	}
	static ClsBankClient _GetEmptyClientObject()
	{
		return ClsBankClient(enMode::EmptyMode, "", "", "", "", "","", 0);
	}
	static vector< ClsBankClient> _LoadClientsDataFromFile()
	{
		vector<ClsBankClient>Vclient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);/*Read mode*/
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile, line))
			{
				ClsBankClient Client = _ConvertLineToClientObject(line);
				Vclient.push_back(Client);
			}
			MyFile.close();
		}
		return Vclient;
	}
	static string _ConvertClientObjectToLine(ClsBankClient Client,string Separator="#//#")
	{
		string LinesAfterConvertObject = "";
		LinesAfterConvertObject += Client.FName + Separator;
		LinesAfterConvertObject += Client.LName + Separator;
		LinesAfterConvertObject += Client.Email + Separator;
		LinesAfterConvertObject += Client.Phone + Separator;
		LinesAfterConvertObject += Client.GetAccountNumber() + Separator;
		LinesAfterConvertObject += Client.PinCode + Separator;
		LinesAfterConvertObject += to_string(Client.accountBalnce);
		return LinesAfterConvertObject;
	}
	static void _SaveClientDataToFile(vector<ClsBankClient>Vclient)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);/*Overwrite mode*/
		string DataLine;
		if (MyFile.is_open())
		{
			for (ClsBankClient C : Vclient)
			{
				if (C.MarkedForDelete() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
				
			}
			MyFile.close();
		}
	}
	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}
	 void _Update()
	{
		vector<ClsBankClient>_Vclient;
		_Vclient = _LoadClientsDataFromFile();
		for (ClsBankClient& C : _Vclient)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_Vclient);

	}
	 string _PrepareTransferDataLog(float Amount,ClsBankClient DestinationClient,string UserName,string Separator="#//#")
	 {
		 string TransferLogRecord = "";
		 TransferLogRecord += ClsDateLibrary::GetSystemTimeDateString() + Separator;
		 TransferLogRecord += GetAccountNumber() + Separator;
		 TransferLogRecord += DestinationClient.GetAccountNumber() + Separator;
		 TransferLogRecord += to_string(Amount) + Separator;
		 TransferLogRecord += to_string(accountBalnce) + Separator;
		 TransferLogRecord += to_string(DestinationClient.accountBalnce) + Separator;
		 TransferLogRecord += UserName;
		 return TransferLogRecord;

	 }
	 static	 stTransferLogsData _ConvertDataLineTransferLogsToRecord(string line,string separator="#//#")
	 {
		 stTransferLogsData TransferRecordData;
		 vector<string> VTransferRecordStoredDate= ClsString::SplitString(line, separator);
		 TransferRecordData.DateTime = VTransferRecordStoredDate[0];
		 TransferRecordData.S_acountNumber = VTransferRecordStoredDate[1];
		 TransferRecordData.D_accountnumber = VTransferRecordStoredDate[2];
		 TransferRecordData.amount = stoi(VTransferRecordStoredDate[3]);
		 TransferRecordData.S_accountBalance = stod(VTransferRecordStoredDate[4]);
		 TransferRecordData.D_accountBalance = stod(VTransferRecordStoredDate[5]);
		 TransferRecordData.UserName = VTransferRecordStoredDate[6];
		 return TransferRecordData;
	 }
	 
	void _RegisterTransferLog(float Amount, ClsBankClient DestinationClient, string USERNAME)
	 {
		string DataLine = _PrepareTransferDataLog(Amount, DestinationClient,USERNAME);
		fstream myfile;
		myfile.open("TransferLog.txt", ios::out|ios::app);
		if(myfile.is_open())
		{
			myfile << DataLine << endl;
			myfile.close();
		}
	 }
	
	void _AddNew()
	 {
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	 }
public:
	
	//string MyFile = "Clients.txt";
	ClsBankClient(enMode mode,string FirstName, string LName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		:ClsPerson(FirstName, LName, Email, Phone)
	{
		_Mode = mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}
	struct stTransferLogsData
	{
		string DateTime;
		string S_acountNumber;
		string D_accountnumber;
		float amount;
		float S_accountBalance;
		float D_accountBalance;
		string UserName;
	};
	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}
	bool MarkedForDelete()
	{
		return _MarkedToDelete;
	}
	string GetAccountNumber()
	{
		return _AccountNumber;
	}
	void SetPinCode(string pincode)
	{
		 _PinCode= pincode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	void setAccountBalance(float accountbalance)
	{
		_AccountBalance = accountbalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = setAccountBalance))float accountBalnce;
	/*No UI code relted inside Object*/
	//void Print()
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FName;
	//	cout << "\nLastName    : " << LName;
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc. Number : " << _AccountNumber;
	//	cout << "\nPassword    : " << _PinCode;
	//	cout << "\nBalance     : " << _AccountBalance;
	//	cout << "\n___________________\n";

	//}
	static	ClsBankClient GetAddNewClient(string AccountNumber)
	{
		return ClsBankClient(enMode::AddNew, "", "", "", "", AccountNumber, "", 0);
	}

	static ClsBankClient Find(string AccountNumber)
	{
		vector<ClsBankClient>Vclient;
		fstream MyFile;
		/*Read Only*/
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsBankClient Client = _ConvertLineToClientObject(Line, "#//#");
				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static ClsBankClient Find(string AccountNumber,string PinCode)
	{
		vector<ClsBankClient>Vclient;
		fstream MyFile;
		/*Read Only*/
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				ClsBankClient Client = _ConvertLineToClientObject(Line, "#//#");
				if (Client.GetAccountNumber() == AccountNumber&&Client.GetPinCode()==PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{

		ClsBankClient Client1 = ClsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1 ,enSaveFailedClientAlreadyExist=2};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case ClsBankClient::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}
			
		case ClsBankClient::UpdatedMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case ClsBankClient::AddNew:
			_AddNew();
			_Mode = enMode::UpdatedMode;
			return enSaveResults::svSucceeded;
			
		}
	}
	 bool Delete()
	{
		 vector<ClsBankClient>Vclients;
		 Vclients = _LoadClientsDataFromFile();
		 for (ClsBankClient& C : Vclients)
		 {
			 if (C.GetAccountNumber() == _AccountNumber)
			 {
				 C._MarkedToDelete = true;
				 break;
			 }
		 }
		 _SaveClientDataToFile(Vclients);
		 *this = _GetEmptyClientObject();
		 return true;
	}
	static vector<ClsBankClient> GetClientsList()
	 {
		 return _LoadClientsDataFromFile();
	}
      static double	GetTotalBalance()
	{
	vector<ClsBankClient>Vclients = ClsBankClient::GetClientsList();
	double TotalaccountBalance=0;
	for (ClsBankClient client : Vclients)
	{
		TotalaccountBalance += client.accountBalnce;
	}
	return TotalaccountBalance;
	}
	  void Deposit(double Amount)
	  {
		  _AccountBalance += Amount;
		  Save();
	  }
	  bool WithDraw(double Amount)
	  {
		  if (Amount > _AccountBalance)
		  {
			  return false;
		  }
		  else
		  {
			  _AccountBalance -= Amount;
			  Save();
		  }
		  //return true;
	  }
	  bool Transfer(float amount,ClsBankClient & DestinationClient,string UserName)
	  {
		  if (amount > accountBalnce)
			  return false;
		  WithDraw(amount);
		  DestinationClient.Deposit(amount);
		  _RegisterTransferLog(amount, DestinationClient, UserName);
		  return true;
	  }
	
	  static vector<stTransferLogsData>GetTransferLogList()
	  {
		  vector<stTransferLogsData>VloginUsers;
		  fstream myfile;
		  myfile.open("TransferLog.txt", ios::in);/*Read mode */
		  if (myfile.is_open())
		  {
			  string line;
			  stTransferLogsData LoginRegisterRecord;
			  while (getline(myfile, line))
			  {
				  LoginRegisterRecord = _ConvertDataLineTransferLogsToRecord(line);
				  VloginUsers.push_back(LoginRegisterRecord);
			  }
			  myfile.close();
		  }
		  return VloginUsers;
	  }
};

