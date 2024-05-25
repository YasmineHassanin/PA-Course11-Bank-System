#pragma once
#include "ClsScreen.h"
#include"ClsBankClient.h"
class ClsTransferLogsScreen :protected ClsScreen
{
private:
	static void PrintTransferLogRecordLine(ClsBankClient::stTransferLogsData TransferlogRegister)
	{
		cout << setw(8) << left << "" << "|" << setw(35) << left << TransferlogRegister.DateTime;
		cout << "|" << setw(10) << left << TransferlogRegister.S_acountNumber;
		cout << "|" << setw(10) << left << TransferlogRegister.D_accountnumber;
		cout << "|" << setw(10) << left << TransferlogRegister.amount;
		cout << "|" << setw(10) << left << TransferlogRegister.S_accountBalance;
		cout << "|" << setw(10) << left << TransferlogRegister.D_accountBalance;
		cout << "|" << setw(10) << left << TransferlogRegister.UserName;
	}
public:
	static void ShowTransferLogsData()
	{
		vector<ClsBankClient::stTransferLogsData>VtransferLogsRegisterData=ClsBankClient::GetTransferLogList();
		string title = "\tTransfer Logs List Screen\n";
		string subtitle = "\t " + to_string(VtransferLogsRegisterData.size()) + " Record(s)\n";
		_DrawScreenHeader(title, subtitle);
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "|" << left << setw(35) << "Date/Time";
		cout << "|" << left << setw(10) << "S.Acc";
		cout << "|" << left << setw(10) << "D.Acc";
		cout << "|" << left << setw(10) << "Amount";
		cout << "|" << left << setw(10) << "S.Balance";
		cout << "|" << left << setw(10) << "D.Balance";
		cout << "|" << left << setw(10) << "UserName";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		if (VtransferLogsRegisterData.size() == 0)
		{
			cout << "No Transfer logs available\n";
		}
		else
		{
			for (ClsBankClient::stTransferLogsData TransferLog : VtransferLogsRegisterData)
			{
				PrintTransferLogRecordLine(TransferLog);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

