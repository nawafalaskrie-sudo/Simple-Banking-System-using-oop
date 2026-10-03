#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
class clsCurrencyExchangeScreen:protected clsScreen
{
private:
    enum enCurrencyExchangeMainMenueOption{eListCurrencies=1,eFindCurrency=2,eUpdateCurrencyRate=3,eCurrencyCalculator=4,eMainMenue=5};

    static short _ReadCurrencyExchangeMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number Between 1-5");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenue() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrencies() {
        //cout << "\n List Currencies well be here..";
        clsListCurrenciesScreen::ShowCurrrenciesList();
    }
    static void _ShowFidCurrency() {
        //cout << "\n Find Currencies well be here..";
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRate() {
        //cout << "\n Update Rate well be here..";

        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void _ShowCurrencyCalculator() {
        //cout << "\n Currency Calculator well be here..";
        clsCurrencyCalculatorScreen::_ShowCurrencyCalcolatScreen();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMainMenueOption Option) {
        switch (Option)
        {
        case enCurrencyExchangeMainMenueOption::eListCurrencies:
            system("cls");
            _ShowListCurrencies();
            _GoBackToCurrencyExchangeMenue();
            break;
        case enCurrencyExchangeMainMenueOption::eFindCurrency:
            system("cls");
            _ShowFidCurrency();
            _GoBackToCurrencyExchangeMenue();
            break;
        case enCurrencyExchangeMainMenueOption::eUpdateCurrencyRate:
            system("cls");
            _ShowUpdateRate();
            _GoBackToCurrencyExchangeMenue();
            break;
        case enCurrencyExchangeMainMenueOption::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToCurrencyExchangeMenue();
            break;
        case enCurrencyExchangeMainMenueOption::eMainMenue:
            break;

        }
    }

public:
	static void ShowCurrencyExchangeScreen() {
        system("cls");
		clsScreen::_DrawScreenHeader("\tCurrency Exchange Main Screen");

		
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMainMenueOption)_ReadCurrencyExchangeMenueOption());
	}
};

