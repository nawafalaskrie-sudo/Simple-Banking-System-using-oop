#pragma once
#include"clsCurrency.h"
#include"clsString.h"
#include"clsScreen.h"
#include<vector>
#include<iomanip>
class clsListCurrenciesScreen:protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency) {
        cout << setw(8) << left << "" << "| " <<left<< setw(30)  << Currency.Country();
        cout << "| " << left << setw(8)  << Currency.CurrencyCode();
        cout << "| " << left << setw(45) << Currency.CurrencyName();
        cout << "| " << left << setw(10) << Currency.Rate();
       
	}

public:
    static void ShowCurrrenciesList() {
        vector<clsCurrency>vCurrecy = clsCurrency::GetAllUSDRates();
        string Title = "\t Currencies List Screen";
        string SubTitle ="\t ("+to_string(vCurrecy.size()) + "Currency";
        clsScreen::_DrawScreenHeader(Title,SubTitle);

        cout << setw(8) << left << "" << "\n\t-----------------------------------------------------------";
        cout << "--------------------------------------------------\n";

        cout << setw(8) << left << "" <<"| "<<left<<setw(30) << "Country";
        cout <<"| " << left << setw(8)  << "Code";
        cout <<"| " << left << setw(45) << "Name";
        cout <<"| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t-----------------------------------------------------------";
        cout << "--------------------------------------------------\n";
        if (vCurrecy.size() == 0) {
            cout<< "\t\t\t\t No Currencies Avalible In the System\n";
        }
        else {
            for (clsCurrency C : vCurrecy) {
                _PrintCurrency(C);
                cout << endl;
            }

        }
        cout << setw(8) << left << "" << "\n\t-----------------------------------------------------------";
        cout << "--------------------------------------------------\n";
    }
};

