#pragma once
#include<iostream>
#include"ClsInputValidate.h"
#include"InterfaceCommunication.h"
#include"ClsString.h"
class ClsPerson:public InterfaceCommunication
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	ClsPerson(string FName, string LName, string Email, string Phone)
	{
		_FirstName = FName;
		_LastName = LName;
		_Email = Email;
		_Phone = Phone;
	}
	/*Set FirstNmae*/
	void SetFName(string Name)
	{
		_FirstName = Name;
	}
	string GetFName()
	{
		return _FirstName;
	}
	__declspec(property(get = GetFName, put = SetFName))string FName;
	/*Set FirstNmae*/
	void SetLName(string Name)
	{
		_LastName = Name;
	}
	string GetLName()
	{
		return _LastName;
	}
	__declspec(property(get = GetLName, put = SetLName))string LName;
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
	void SetEmail(string Email)
	{
		_Email = Email;
	}
	string GetEmail()
	{
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	void SetPhone(string Phone)
	{
		_Phone = Phone;
	}
	string GetPhone()
	{
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;
	void SendEmail(string title, string Body)
	{

	}
	void SendFax(string title, string Body)
	{

	}
	void SendSMS(string title, string Body)
	{

	}

};

