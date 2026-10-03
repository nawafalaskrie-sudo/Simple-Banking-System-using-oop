#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsUpdateCurrencyRateScreen:protected clsScreen
{
private:

	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\n Currency Card:\n";
		cout << "----------------------------------\n";
		cout << "Country     :" << Currency.Country() << endl;
		cout << "Code        :" << Currency.CurrencyCode() << endl;
		cout << "Name        :" << Currency.CurrencyName() << endl;
		cout << "Rate(1$)    :" << Currency.Rate() << endl;
		cout << "----------------------------------\n";

	}

	static void _ShowResults(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\n Currency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else {
			cout << "\n Currency Was NOT Found :-(\n";

		}
	}

	static float _ReadRate() {

		cout << "\n Enter New Rate : ";
		float NewRate = 0;
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen() {

		clsScreen::_DrawScreenHeader("\t Update Currency Screen");

		cout << "\n Plase Enter CurrencyCode : ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::isCurrencyExist(CurrencyCode)) {
			cout << "\Currency is not found, choose another one: ";


			 CurrencyCode = clsInputValidate::ReadString();

		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrencyCard(Currency);

			char Answer='n';

			cout << "\n Are you sure you want to update the rate od this Currency ? y/n?";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y') {
				cout << "\n\n Update Currency Rate:";
				cout << "\n------------------------------\n";
				cout << "\n Enter New Rate :";

				Currency.UpdateRate(_ReadRate());
				cout << "\n Currency Rate Update successfully :-)\n ";
				_PrintCurrencyCard(Currency);
				
			
		}
	}
};

