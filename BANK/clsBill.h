#pragma once
#include"clsBankClient.h"
#include"clsDate.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include<iostream>

class clsBill
{

private:

	
	string _BillName;
	string _AccountNumber;
	string _DateTime;
	float _Price;
	bool _MarkForDelete = false;


	static clsBill _ConvertLinetoBillObject(string Line, string Seperator = "#//#")
	{
		vector<string> vBillData;
		vBillData = clsString::Split(Line, Seperator);

		return clsBill(vBillData[0], vBillData[1], vBillData[2],
			stof(vBillData[3]));

	}

	static string _ConverBillObjectToLine(clsBill Bill, string Seperator = "#//#")
	{

		string stBillRecord = "";

		stBillRecord += clsDate::GetSystemDateTimeString() + Seperator;
		stBillRecord += Bill.GetBillName() + Seperator;
		stBillRecord += Bill.AccountNumber() + Seperator;
		stBillRecord += to_string(Bill.Price());
		

		return stBillRecord;

	}

	vector <clsBill> _LoadBillsDataFromFile(string AccountNumber)
	{

		vector <clsBill> vBills;

		fstream MyFile;
		MyFile.open("BillsLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;


			while (getline(MyFile, Line))
			{

				clsBill Bill = _ConvertLinetoBillObject(Line);
				if (Bill.AccountNumber() == AccountNumber)
				{
					vBills.push_back(Bill);
				}
			}

			MyFile.close();

		}

		return vBills;

	}


	void _AddNew()
	{

		_AddDataLineToFile(_ConverBillObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("BillsLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{

			MyFile << stDataLine << endl;

			MyFile.close();
		}

	}

	static clsBill _GetEmptyBillObject()
	{
		return clsBill("", "", "",0);
	}

public:


	clsBill(string DateTime , string BillName , string AccountNumber, float Price)
	{
	
		_BillName = BillName;
		_AccountNumber = AccountNumber;
		_DateTime = DateTime;
		_Price = Price;
	}

	bool IsEmpty()
	{
		return (_AccountNumber == "" && _BillName == "" && _Price == 0 && _DateTime == "");
	}

	bool MarkForDeleted()
	{
		return _MarkForDelete;
	}


	string AccountNumber()
	{
		return _AccountNumber;
	}

	string GetBillName()
	{
		return _BillName;
	}


	
	float Price()
	{
		return _Price;
	}


	string DateTime()
	{
		return _DateTime;
	}

	static clsBill Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open("BillsLog.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBill Bill = _ConvertLinetoBillObject(Line);
				if (Bill.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Bill;
				}

			}

			MyFile.close();

		}
		return _GetEmptyBillObject();
	}

	static bool IsBillExist(string AccountNumber)
	{

		clsBill Bill = clsBill::Find(AccountNumber);
		return (!Bill.IsEmpty());
	}

	vector<clsBill> GetBillsList(string AccountNumber)
	{
		return _LoadBillsDataFromFile(AccountNumber);
	}

	bool PayBill(clsBankClient &Client)
	{
		if (Client.Withdraw(Price()))
		{
			_AddNew();
			return true;
		}

		return false;
	}




};

