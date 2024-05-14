#pragma once
#include<iostream>
#include<string>
using namespace std;
class ClsScreen
{


protected:
	static void _DrawScreenHeader(string title,string subTitle="")
	{
		cout<<"\t\t\t\t__________________________________________";
		cout << "\n\n\t\t\t\t" << title;
		if (subTitle != "")
		{
			cout << "\n\t\t\t\t"<<subTitle << endl;
		}
		cout << "\n\t\t\t\t__________________________________________\n\n";
	}
};

