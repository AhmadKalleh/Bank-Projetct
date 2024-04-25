#pragma once
#include<iostream>
#include"clsScreen.h""
#include <iomanip>
#include"clsInputValidate.h"
#include"clsBillListScreen.h"
#include"clsPayBillScreen.h"


class clsBillScreen:protected clsScreen
{

private:

    enum enBillsMenueOptions
    {
        eBillsList = 1,
        ePayBill = 2,
        eTransactions = 3
    };

    static short _ReadBillsMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 3]? ";
        short Choice = clsInputValidate::ReadNumberBetween<short>(1, 3, "Enter Number between 1 to 3? ");
        return Choice;
    }

    static void _GoBackToBillsMenue()
    {
        cout << "\n\nPress any key to go back to Bills Menue...";
        system("pause>0");
        ShowBillsMenue();

    }

    static void  _ShowBillsListScreen()
    {
        clsBillListScreen::ShowBillsList();
    }

    static void  _ShowPayBillScreen()
    {
        clsPayBillScreen::ShowPayBillScreen();
    }

    

    static  void _PerfromTranactionsMenueOption(enBillsMenueOptions BillMenueOption)
    {
        switch (BillMenueOption)
        {
        case enBillsMenueOptions::eBillsList:
        {
            system("cls");
            _ShowBillsListScreen();
            _GoBackToBillsMenue();
            break;
        }
        

        case enBillsMenueOptions::ePayBill:
        {
            system("cls");
            _ShowPayBillScreen();
            _GoBackToBillsMenue();
            break;

        }
 
        case enBillsMenueOptions::eTransactions:
        {

        }
        }

    }

public:

    static void ShowBillsMenue()
    {
        

        system("cls");
        _DrawScreenHeader("\t     Bills Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Bills Menue \n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Bills List.\n";
        cout << setw(37) << left << "" << "\t[2] Pay Bill.\n";
        cout << setw(37) << left << "" << "\t[3] Transactions Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTranactionsMenueOption((enBillsMenueOptions)_ReadBillsMenueOption());
    }

};

