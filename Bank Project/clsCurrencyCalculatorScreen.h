#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsCurrencyCalculatorScreen:protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency,string Title) {
		cout << "\n"<<Title<<"\n";
		cout << "----------------------------------\n";
		cout << "Country     :" << Currency.Country() << endl;
		cout << "Code        :" << Currency.CurrencyCode() << endl;
		cout << "Name        :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)    :" << Currency.Rate() << endl;
		cout << "----------------------------------\n";

	}

	static float _ReadAmount() {

		cout << "\n Enter Amount To Exchange : ";
		float Amount = 0;
		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;

		
	}

	static void _PrintCalculationResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo) {
		_PrintCurrencyCard(CurrencyFrom, "Convert From :");
		float AmonutInUSD = CurrencyFrom.ConvertToUSD(Amount);
		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << AmonutInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD") {
			return;
		}
		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(CurrencyTo, "To:");

		float AmountInCurrrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << Amount << " " << CurrencyFrom.CurrencyCode()
			<< " = " << AmountInCurrrencyTo << " " << CurrencyTo.CurrencyCode();
		
	}


	static clsCurrency _GetCurrency(string Message) {
		cout << Message ;
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::isCurrencyExist(CurrencyCode)) {
			cout << "\Currency is not found, choose another one: ";

			CurrencyCode = clsInputValidate::ReadString();

		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

public:
	static void _ShowCurrencyCalcolatScreen() {
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y') {

			system("cls");
			clsScreen::_DrawScreenHeader("\t Curency Calcolat Screen");

			
			clsCurrency CurrencyFrom = _GetCurrency("\nPlase Enter Currency1 Code : ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlase Enter Currency2 Code : ");

			float Amount = _ReadAmount();
			_PrintCalculationResults(Amount,CurrencyFrom, CurrencyTo);

			cout << "\n Do you want to perform amother calculator ?y/n?";
			cin >> Continue;
		} 
	}
};

