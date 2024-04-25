#pragma once

#include<iostream>
#include"clsDate.h";
#include"clsString.h";
using namespace std;

class clsPeriod
{

public:

	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}


	static	bool isOverLapPeriods(clsPeriod period1, clsPeriod period2)
	{
		if ((
			(clsDate::CompareDates(period2.EndDate, period1.StartDate)) == clsDate::enDateCompare::Before)
			|| (clsDate::CompareDates(period2.StartDate, period1.EndDate) == clsDate::enDateCompare::After))
			return false;
		else
			return true;
	}

	bool isOverLapPeriods(clsPeriod period2)
	{
		return isOverLapPeriods(*this, period2);
	}

	static	int periodLenghtInDays(clsPeriod Period, bool IncludeEndDate = false)
	{
		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDate);
	}

	int periodLenghtInDays(bool IncludeEndDate = false)
	{
		return periodLenghtInDays(*this, IncludeEndDate);
	}

	static	bool isDateinPeriod(clsDate Date, clsPeriod Period)
	{
		return  !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before
			|| clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
	}

	bool isDateinPeriod(clsDate Date)
	{
		return isDateinPeriod(Date, *this);
	}

	static	short countOverLapsDays(clsPeriod period1, clsPeriod period2)
	{
		short OverLapsDays = 0;
		int Period1Lenght = periodLenghtInDays(period1, true);
		int Period2Lenght = periodLenghtInDays(period2, true);

		if (Period1Lenght < Period2Lenght)
		{
			while (clsDate::IsDate1BeforeDate2(period1.StartDate, period1.EndDate))
			{
				if (isDateinPeriod(period1.StartDate, period2))
					OverLapsDays++;

				period1.StartDate = clsDate::AddOneDay(period1.StartDate);

			}
		}
		else
		{
			while (clsDate::IsDate1BeforeDate2(period2.StartDate, period2.EndDate))
			{
				if (isDateinPeriod(period2.StartDate, period1))
					OverLapsDays++;

				period2.StartDate = clsDate::AddOneDay(period2.StartDate);

			}
		}
		return OverLapsDays;
	}

	short countOverLapsDays(clsPeriod period2)
	{
		return countOverLapsDays(*this, period2);
	}
};

