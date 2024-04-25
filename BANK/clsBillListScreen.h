#pragma once
#include"clsBill.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iostream>
#include <iomanip>


class clsBillListScreen:protected clsScreen
{

private:

    static void PrintBillRecordLine(clsBill Bill)
    {
        cout << setw(8) << left << "" << "| " << setw(40) << left << Bill.DateTime();
        cout << "| " << setw(15) << left << Bill.AccountNumber();
        cout << "| " << setw(15) << left << Bill.GetBillName();
        cout << "| " << setw(15) << left << Bill.Price();
    }

public:

	static void ShowBillsList()
	{

		_DrawScreenHeader("\t  Bills List Screen");

		cout << "\nPlease Enter AccountNumber that you want to show All Bills for this Number: ";
		string AccountNumber = clsInputValidate::ReadString();


		clsBill Bill = clsBill::Find(AccountNumber);

		vector<clsBill> vBills = Bill.GetBillsList(AccountNumber);

		cout << "\n\n\t\t\t\t\t===================================\n";
		cout << "\t\t\t\t\t             (" + to_string(vBills.size()) + ") Bill(s).\n";
		cout << "\t\t\t\t\t===================================\n";


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(40) << "Date/Time";
        cout << "| " << left << setw(15) << "Acc.N";
        cout << "| " << left << setw(15) << "Name";
        cout << "| " << left << setw(15) << "Price($)";


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vBills.size() == 0)
            cout << "\t\t\t\t       No Bills Available In the System!";
        else

            for (clsBill Bill : vBills)
            {

                PrintBillRecordLine(Bill);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;



	}


};

