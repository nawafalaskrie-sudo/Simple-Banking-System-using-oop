#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
class clsFindCurrencyScreen:protected clsScreen
{
private:
	//enum enFindType{eCode=1,eCountry=2};
	
	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\n Currency Card:\n";
		cout << "----------------------------------\n";
		cout << "Country     :" << Currency.Country()<<endl;
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

	/*static int _ReadFindType() {

		cout << "Find By: [1] Code or [2] Country ?";
		short Choise = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number Between 1-2?");
		return Choise;
	}

	static void _FindByCode() {
		cout << "\n Plase enter Country?";
		string Code = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		while (!clsCurrency::isCurrencyExist(Code)) {
			cout << "\Currency is not found, choose another one: ";
			 Code = clsInputValidate::ReadString();
			clsCurrency Curency = clsCurrency::FindByCode(Code);

		}
		_PrintCurrencyCard(Currency);
	}

	static void _FindByCountry() {
		cout << "\n Plase enter Currency Code?";
		string CountryName = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
		while (!clsCurrency::isCurrencyExist(Currency.CurrencyCode()) )
		{
			cout << "\Currency is not found, choose another one: ";
			CountryName = clsInputValidate::ReadString();
			clsCurrency Curency = clsCurrency::FindByCode(Currency.CurrencyCode());

		}
		_PrintCurrencyCard(Currency);
	}

	static void _PerformeFindTypeOption(enFindType FindType) {
		switch (FindType)
		{
		case enFindType::eCode:
			_FindByCode();
			break;
		case enFindType::eCountry:
			_FindByCountry();
			break;
	
		}

	}*/

public:
	static void ShowFindCurrencyScreen() {
		clsScreen::_DrawScreenHeader("\t Find  Currency Screen");

		cout << "Find By: [1] Code or [2] Country ?";
		short Answer = clsInputValidate::ReadShortNumberBetween(1, 2, "Enter Number Between 1-2?");

		if (Answer == 1) {
			cout << "\n Plase enter CurrencyCode?";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else if (Answer == 2) {
			cout << "\n Plase enter Country?";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
		//_PerformeFindTypeOption((enFindType) _ReadFindType());
	}
};

