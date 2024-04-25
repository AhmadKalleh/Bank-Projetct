#pragma once
#include"clsScreen.h"
#include<iostream>
#include <iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsBill.h"
#include"clsDate.h"

class clsPayBillScreen:protected clsScreen
{

private:

	static string  _GetBillName(short Choice)
	{
		string arrBill[5] = { "","Electronic","Water","Telephone","Internet" };
		return arrBill[Choice];
	}

public:

	static void ShowPayBillScreen()
	{
		_DrawScreenHeader("\t    Pay Bill Screen");


		cout << "\nEnter Account Number that you want to Pay A Bill: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		cout << "\nwhat is Bill that you want to pay it ,[1] : Electronic     [2] : Water    [3] : Telephone    [4] : Internet  ? ";
		short Choice = clsInputValidate::ReadNumberBetween(1, 4);

		cout << "\nEnter Price: ";
		float Price = clsInputValidate::ReadNumber<float>();

		clsBill Bill(clsDate::GetSystemDateTimeString(), _GetBillName(Choice), AccountNumber, Price);

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Bill.PayBill(Client1))
			{
				cout << "\nThe Bill has been paid successfully -)\n";
			}
			else
			{
				cout << "\nSorry -( ,Your Balance is not enough to pay the Bill ....\n";
			}
		}

		

	}

};

