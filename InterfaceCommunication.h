#pragma once
#include<iostream>
#include<string>
using namespace std;
class InterfaceCommunication
{

	virtual void SendEmail(string title, string Body) = 0;
	virtual void SendFax(string title, string Body) = 0;
	virtual void SendSMS(string title, string Body) = 0;

};

