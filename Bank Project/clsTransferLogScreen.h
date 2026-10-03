#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include<iomanip>

class clsTransferLogScreen:protected clsScreen
{
private:
	static void _PrintTransferLog(clsBankClient::stTrnasferLogRecored TrnasferLog) {
		cout << setw(5) << left << "" << "|" << setw(20) << left << TrnasferLog.DateTime;
		cout << "| " << setw(7) << left << TrnasferLog.SourceAccountNumber;
		cout << "| " << setw(7) << left << TrnasferLog.DestnationAccountNumber;
		cout << "| " << setw(15) << left << TrnasferLog.Amount;
		cout << "| " << setw(15) << left << TrnasferLog.SrcAccountBalanceAfter;
		cout << "| " << setw(15) << left << TrnasferLog.DestAccountBalanceAfter;
		cout << "| " << setw(10) << left << TrnasferLog.UserName;
	}

public:
	static void ShowTransferLog() {
		vector<	clsBankClient::stTrnasferLogRecored> vTransferLogRecored = clsBankClient::GetTransfersLogRecored();
		string Title = "Transfer Log List Screen";
		string SubTitle = "(" + to_string(vTransferLogRecored.size()) + ") Recored(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);


		cout << "\n----------------------------------------------------------------";
		cout << "------------------------------------------\n";
		cout << setw(5) << left << "" << "|" << setw(20) << left << "DateTime";
		cout << "| " << setw(7) << left << "SAN";
		cout << "| " << setw(7) << left << "DAN";
		cout << "| " << setw(15) << left << "Amount";
		cout << "| " << setw(15) << left << "SAB";
		cout << "| " << setw(15) << left << "DAB";
		cout << "| " << setw(10) << left << "UserName";
		cout << "\n----------------------------------------------------------------";
		cout << "------------------------------------------\n";
		if (vTransferLogRecored.size() == 0) {
			cout << "\n\t\tNo TRnasfer Availble in System.";
		}
		else {
			for (clsBankClient::stTrnasferLogRecored Line : vTransferLogRecored) {
				_PrintTransferLog(Line);
			}
		}
			cout << "\n----------------------------------------------------------------";
			cout << "------------------------------------------\n";
		
	}
};

