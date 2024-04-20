#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "clsScreen.h"
#include "clsBankClient.h"

using namespace std; 
class clsTransferLogScreen: protected clsScreen
{

private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.Datetime;
		cout << "| " << setw(8) << left << TransferLogRecord.Username;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.SrcBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.DestBalanceAfter;
	}

public:
	static void _ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vRecords;
		vRecords = clsBankClient::GetTransfersLogList();
		string title = "\t Transfer Log List Screen";
		string subtitle = "\t   (" + to_string(vRecords.size()) + ") Record(s)";
		_DrawScreenHeader(title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "User";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Balance";
		cout << "| " << left << setw(10) << "d.Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vRecords.size() == 0)
		{
			cout << "\t\t\t\tNo Transfers done In the System";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord& Record : vRecords)
			{
				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
};

