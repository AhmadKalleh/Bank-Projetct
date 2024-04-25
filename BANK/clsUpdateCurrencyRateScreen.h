#pragma once
#include"clsCurrency.h"
#include"clsScreen.h"
#include<iostream>
#include"clsInputValidate.h"
#include <iomanip>


class clsUpdateCurrencyRateScreen :clsScreen
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


public:

    static void ShowUpdateCurrencyRateScreen()
    {
        _DrawScreenHeader("\t   Update Currency Screen");



        cout << "Please Enter Currency Code: ";
        string CurrencyCode = clsInputValidate::ReadString();

        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, choose another one: ";
            CurrencyCode = clsInputValidate::ReadString();
        }

        clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency  y/n?";
        char Answer = 'n';
        cin >> Answer;


        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            cout << "\nEnter New Rate: ";
            float NewRate = clsInputValidate::ReadNumber<float>();
            Currency.UpdateRate(NewRate);

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);

        }

    }
};

