// PA-Course11-Bank-System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include"ClsBankClient.h"
#include"ClsLoginScreen.h"
using namespace std;


int main()
{

	while (true)
{
	ClsLoginScreen::ShowLoginScreen();
}
	//ClsMainScreen::ShowMainMenueScreen();
       system("pause>0");
       return 0;



	/*ClsBankClient Client1= ClsBankClient::Find("A101");
	Client1.Print();
	ClsBankClient Client2 = ClsBankClient::Find("A101", "1239");
	Client2.Print();
	cout << endl;
	cout << "Is Client Exist: " << endl;
	cout<<Client2.IsClientExist("A108");*/
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
