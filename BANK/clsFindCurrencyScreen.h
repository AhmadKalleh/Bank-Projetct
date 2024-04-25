#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include<iostream>
#include"clsInputValidate.h"
#include <iomanip>

class clsFindCurrencyScreen:protected clsScreen
{
private:

    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:";
        cout << "\n_________________________________\n";
        cout << "\nCountry   : " << Currency.Country();
        cout << "\nCode      : " << Currency.CurrencyCode();
        cout << "\nName      : " << Currency.CurrencyName();
        cout << "\nRate(1$)  : " << Currency.Rate();
        cout << "\n_________________________________\n";

    }

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}

		else
		{
			cout << "\nCurrency was not Found:-(\n";
		}

	}

public:
	static void ShowFindCurrencyScreen()
	{
	
		_DrawScreenHeader("\t   Find Currency Screen");


		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadNumberBetween<short>(1, 2);

		switch (Choice)
		{
			case 1:
			{
				cout << "\nPlease Enter CurrencyCode: ";
				string CurrencyCode = clsInputValidate::ReadString();
				clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
				_ShowResults(Currency);
				break;
			}

			case 2:
			{
				cout << "\nPlease Enter Country Name: ";
				string CountryName = clsInputValidate::ReadString();
				clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
				_ShowResults(Currency);
				break;
			}

		}	

	}

};

