#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"Global.h"
class clsTransferScreen:protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\n Clinet Card";
		cout << "\n===========================\n";
		cout << "\nFull Bame   : " << Client.FullName();
		cout << "\nAcc, Number : " << Client.AccountNumber();
		cout << "\n Balance      : " << Client.AccountBalance;
		cout << "\n===========================\n";


	}

	static string _ReadAccountNumber() {
		string AccountNumber;
		cout << "\n Please Enter Account Number to Transfer From : ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static float _ReadAmount(clsBankClient SourceClient) {
		float Amount;
		cout << "\Enter Transfer Amount? ";
		Amount = clsInputValidate::ReadFloatNumber();
		while (Amount > SourceClient.AccountBalance) {
			cout << "\n Amount Exceeds the available Balance, Enter another Amount?";
			Amount = clsInputValidate::ReadFloatNumber();
		}
		return Amount;
	}



public:
	static void ShowTransferScreen() {

		clsScreen::_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		float Amount = _ReadAmount(SourceClient);

		cout << "\n Are you sure you want to perform this opration?y/n";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y') {
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName)) {
				cout << "\n Transfer done successfully..\n";
			}
			else {
				cout << "\n Transfer Fail\n";
			}
		}
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}
};

