#pragma once
#include<iostream>
#include"ClsDateLibrary.h"
#include<string>
#include"ClsString.h"
class ClsInputValidate
{
public:

	static bool IsNumberBetweenTheRange(short Number, short from, short To)
	{
		if (Number >= from && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetweenTheRange(int Number, int from, int To)
	{
		if (Number >= from && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetweenTheRange(float Number, float from, float To)
	{
		if (Number >= from && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsNumberBetweenTheRange(double Number, double from, double To)
	{
		if (Number >= from && Number <= To)
			return true;
		else
			return false;
	}
	static bool IsDateValid(ClsDateLibrary Date1)
	{
		return	ClsDateLibrary::IsTheDateIsValidOrNot(Date1);
	}
	static bool IsDateBetween(ClsDateLibrary Date, ClsDateLibrary DateFrom, ClsDateLibrary DateTo)
	{
		if ((ClsDateLibrary::IsDate1AfterDate2(Date, DateFrom) || ClsDateLibrary::IsDate1EqualDate2(Date, DateFrom))
			&&
			( ClsDateLibrary::IsDate1BeforeDate2(Date, DateTo) || ClsDateLibrary::IsDate1EqualDate2(Date, DateTo)));
		{
			return true;
		}
		
		if ((ClsDateLibrary::IsDate1BeforeDate2(Date, DateTo) || ClsDateLibrary::IsDate1EqualDate2(Date, DateTo))
			&&
			(ClsDateLibrary::IsDate1AfterDate2(Date, DateFrom) || ClsDateLibrary::IsDate1EqualDate2(Date, DateFrom)));
		{
			return true;
		}
		return false;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number,Please Enter Again: \n")
	{
		int Number;
		while(!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number,Please Enter Again: \n")
	{
		double Number;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static int ReadIntNumberBetween(int from, int to, string ErrorMessage = "Invalid Number,Please Enter Again: \n")
	{
		int Number = ReadIntNumber();
		while (!IsNumberBetweenTheRange(Number,from,to))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}
	static double ReadDblNumberBetween(double from, double to, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();
		while (!IsNumberBetweenTheRange(Number, from, to))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}
};

