#pragma once
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"

using namespace std;
class clsCurrency
{
private:
	enum enMode{EmptyMode=0,UpdateMode=1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Seperator = "#//#") {

		vector<string>CurrencyData = clsString::Split(Line, Seperator);

		clsCurrency Currency(enMode::UpdateMode, CurrencyData[0], CurrencyData[1], CurrencyData[2], stod(CurrencyData[3]));
		return Currency;

	}


	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#") {
		string stCurrencyRecored="";
		stCurrencyRecored += Currency.Country() + Seperator;
		stCurrencyRecored += Currency.CurrencyCode() + Seperator;
		stCurrencyRecored += Currency.CurrencyName() + Seperator;
		stCurrencyRecored +=to_string( Currency.Rate()) ;

		return stCurrencyRecored;

	}


 

	static vector<clsCurrency> _LoadCurrencysDataFromFile() {

		vector<clsCurrency> vCurrencyData;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in );

		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencyData.push_back(Currency);
			}

			MyFile.close();
		}
		return vCurrencyData;
	}
 

	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrency) {
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

        string DataLine;

		if (MyFile.is_open()) {
			for (clsCurrency C : vCurrency) {
				DataLine = _ConvertCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();
		}
	}


  

	void _Update() {

        vector<clsCurrency>vCurrency;
        vCurrency= _LoadCurrencysDataFromFile();
		for (clsCurrency &C : vCurrency) {
			if ( C.CurrencyCode()==CurrencyCode()) {
				C = *this;
				break;
			}

		}
		_SaveCurrencyDataToFile(vCurrency);

	}

 

	static clsCurrency _GetEmptyCurrencyObject() {
		return clsCurrency (enMode::EmptyMode,"","","",0);
		
	}

  
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate=Rate;
	}

 

	string Country() {
		return _Country;
	}

	

	string CurrencyCode() {
		return _CurrencyCode;
	}

	

	string CurrencyName() {
		return _CurrencyName;
	}

	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}

	double Rate() {
		return _Rate;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

  

	static clsCurrency FindByCode(string CurrencyCode) {

		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);

					if (Currency.CurrencyCode() == CurrencyCode) {
						MyFile.close();
						return Currency;
					}
				
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();

	}

  

	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open()) {
			string Line;
			while (getline(MyFile, Line)) {

				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);


		if (clsString::UpperAllString( Currency.Country()) == Country) {
					MyFile.close();
					return Currency;
				}

			}
			MyFile.close();
		}

		return _GetEmptyCurrencyObject();

	}

 

	static bool isCurrencyExist(string CurrencyCode) {
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return (!Currency.IsEmpty());
	}

    static vector <clsCurrency> GetAllUSDRates()
    {

        return _LoadCurrencysDataFromFile();

    }

	 float ConvertToUSD( float Amount) {
		return (float)( Amount/Rate());
	}

	 float ConvertToOtherCurrency( float Amount, clsCurrency CurrencyTo) {
		 float AmountInUSD = ConvertToUSD(Amount);
		 if (CurrencyTo.CurrencyCode() == "USD") {
			 return AmountInUSD;
		 }
		 
		 return (float) (AmountInUSD * CurrencyTo.Rate());
	 }

};


