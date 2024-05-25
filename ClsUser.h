#pragma once
#include "ClsPerson.h"
#include"ClsInputValidate.h"
#include"Clsutil.h"
#include<string>
#include<vector>
#include<iomanip>
#include<fstream>
#include"Global.h"
class ClsUser :public ClsPerson
{
private:
	enum enUsersMode
	{
		eEmptyMode = 0, eUpdatedMode = 1, AddNewMode = 2
	};
	string _UserName;
	string _Password;
	int _Permission;
	enUsersMode _Mode;
	bool _MarkedToDeleted = false;
	struct stLoginRegisterRecord;
	
	/*static  stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line,string separator="#//#")
	 {
		stLoginRegisterRecord loginregisterrecord;
		vector<string>loginregisterDataLine = ClsString::SplitString(line, separator);
		loginregisterrecord.DateTime = loginregisterDataLine[0];
		loginregisterrecord.Username = DectyptedPassword( loginregisterDataLine[1]);
	loginregisterrecord.Password =  loginregisterDataLine[2];
		loginregisterrecord.permissions = stoi(loginregisterDataLine[3]);
		return loginregisterrecord;
	 }*/
	static  stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string line, string separator = "#//#")
	{
		stLoginRegisterRecord loginregisterrecord;
		vector<string>loginregisterDataLine = ClsString::SplitString(line, separator);
		loginregisterrecord.DateTime = loginregisterDataLine[0];
		loginregisterrecord.Username = loginregisterDataLine[1];
		loginregisterrecord.Password = loginregisterDataLine[2];
		loginregisterrecord.permissions = stoi(loginregisterDataLine[3]);
		return loginregisterrecord;
	}
	//string _PrepareLoginRecord(string separator = "#//#")
	//{
	//	string LogginLine = "";
	//	LogginLine += ClsDateLibrary::GetSystemTimeDateString() + separator;
	//	LogginLine += username + separator;
	//	LogginLine +=  EnctyptedPassword(password)+ separator;
	//	LogginLine += to_string(permission);
	//	return LogginLine;
	//}
	string _PrepareLoginRecord(string separator = "#//#")
	{
		string LogginLine = "";
		LogginLine += ClsDateLibrary::GetSystemTimeDateString() + separator;
		LogginLine += username + separator;
		LogginLine +=  password+ separator;
		LogginLine += to_string(permission);
		return LogginLine;
	}
	/*static ClsUser _ConvertLineUserObject(string line, string separator = "#//#")
	{
		vector <string>VUser = ClsString::SplitString(line, separator);
		return ClsUser(enUsersMode::eUpdatedMode, VUser[0], VUser[1], VUser[2], VUser[3], VUser[4],DectyptedPassword( VUser[5]), stoi(VUser[6]));
	}*/
	static ClsUser _ConvertLineUserObject(string line, string separator = "#//#")
	{
		vector <string>VUser = ClsString::SplitString(line, separator);
		return ClsUser(enUsersMode::eUpdatedMode, VUser[0], VUser[1], VUser[2], VUser[3], VUser[4],VUser[5], stoi(VUser[6]));
	}
	static vector<ClsUser> _LoadDataLineFromFile()
	{
		vector <ClsUser>VUser;
		fstream myfile;
		myfile.open("Users.txt", ios::in);/*Read mode */
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsUser user = _ConvertLineUserObject(line);
				VUser.push_back(user);
			}
			myfile.close();
		}
		return VUser;
	}
	/*static string _ConvertUserObjectToLine(ClsUser user, string separator = "#//#")
	{
		string LineUserData = "";
		LineUserData += user.FName + separator;
		LineUserData += user.LName + separator;
		LineUserData += user.Email + separator;
		LineUserData += user.Phone + separator;
		LineUserData += user.username + separator;
		LineUserData +=EnctyptedPassword(user.password)+ separator;
		LineUserData += to_string(user.permission);
		return LineUserData;
	}*/
	static string _ConvertUserObjectToLine(ClsUser user, string separator = "#//#")
	{
		string LineUserData = "";
		LineUserData += user.FName + separator;
		LineUserData += user.LName + separator;
		LineUserData += user.Email + separator;
		LineUserData += user.Phone + separator;
		LineUserData += user.username + separator;
		LineUserData +=user.password+ separator;
		LineUserData += to_string(user.permission);
		return LineUserData;
	}
	static void _AddDataLineToFile(string stDataLine)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out|ios::app);
		if (myfile.is_open())
		{
			myfile << stDataLine << endl;
			myfile.close();
		}
		
	}
	static ClsUser _GetEmptyUserObject()
	{
		return ClsUser(enUsersMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
	
	
    static void	_SaveUserDataToFile(vector<ClsUser>VUser)
	{
		fstream myfile;
		myfile.open("Users.txt", ios::out);/*Overwrite*/
		if (myfile.is_open())
		{
			string line;
			for (ClsUser U : VUser)
			{
				if (U._MarkedToDeleted == false)
				{
					line = _ConvertUserObjectToLine(U);
					myfile << line << endl;

				}
			}
			myfile.close();
		}
	}
	 void _Update()
	{
		vector <ClsUser>_VUser;
		_VUser = _LoadDataLineFromFile();
		for (ClsUser& U : _VUser)
		{
			if (U.GetUserName() == GetUserName())
			{
				U = *this;
			}
		}
		_SaveUserDataToFile(_VUser);
	}
	 void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}
	 static string EnctyptedPassword(string Password)
	 {
		 return Clsutil::encryptionText(Password,2);
	 }
	 static string DectyptedPassword(string Password)
	 {
		 return Clsutil::decryptionText(Password, 2);
	 }
public:
	ClsUser(enUsersMode mode,string Firstname, string Lastname, string Email, string Phone, string username, string password, int permission)
		:ClsPerson(Firstname, Lastname, Email, Phone)
	{
		_Mode = mode;
		_UserName = username;
		_Password = password;
		_Permission = permission;
	}
	struct stLoginRegisterRecord
	{
		string DateTime;
		string Username;
		string Password;
		int permissions;
	};
	/*Set Username*/
	void SetUserName(string username)
	{
		_UserName = username;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName))string username;
	/*Set Password*/
	void SetPassword(string password)
	{
		_Password = password;
	}
	string Getpassword()
	{
		return _Password;
	}
	__declspec(property(get = Getpassword, put = SetPassword))string password;
	/*Set Permission*/
	void SetPermission(int Permission)
	{
		_Permission = Permission;
	}
	int GetPermission()
	{
		return _Permission;
	}
	__declspec(property(get = GetPermission, put = SetPermission))int permission;
	static ClsUser Find(string username)
	{
		vector<ClsUser>Vuser;
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if(myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsUser user = _ConvertLineUserObject(line,"#//#");
				if (user.GetUserName() == username)
				{
					myfile.close();
					return user;
				}
			}
			
			myfile.close();
		}
		return _GetEmptyUserObject();
	}
	static ClsUser Find(string username, string password)
	{
		vector <ClsUser>Vuser;
		fstream myfile;
		myfile.open("Users.txt", ios::in);
		if (myfile.is_open())
		{
			string line;
			while (getline(myfile, line))
			{
				ClsUser user = _ConvertLineUserObject(line,"#//#");
				if (user.GetUserName() == username && user.Getpassword() == password)
				{
					myfile.close();
					return user;
				}
			}
			myfile.close();
		}
		return _GetEmptyUserObject();
	}
	bool IsEmpty()
	{
		return (_Mode == enUsersMode::eEmptyMode);
	}
	static bool IsUserExist(string username)
	{
		/*Is user is found or not*/
		ClsUser user = ClsUser::Find(username);
		return (!user.IsEmpty());
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, enSaveFaileduserAlreadyExist = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enUsersMode::eEmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}
		case enUsersMode::eUpdatedMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
			break;
		}
		case enUsersMode::AddNewMode:
		{
			if (IsUserExist(_UserName))
			{
				return enSaveResults::enSaveFaileduserAlreadyExist;
			}
			else
			{
				_AddNew();
				_Mode = enUsersMode::eUpdatedMode;
				return enSaveResults::svSucceeded;
			}
		}

		}
	}
	static ClsUser GetAddNewUser(string Username)
	{
		return ClsUser(enUsersMode::AddNewMode, "", "", "", "", Username, "", 0);
	}
	bool MarkedForDeleted()
	{
		return _MarkedToDeleted;
	}
	 bool DeleteUsers()
	{
		vector <ClsUser>VUser;
		VUser = _LoadDataLineFromFile();
		for (ClsUser &U:VUser)
		{
			if (U.GetUserName()==_UserName)
			{
				U._MarkedToDeleted = true;
				break;
			}
		}
		_SaveUserDataToFile(VUser);
		*this = _GetEmptyUserObject();
		return true;
	}
	 static vector<ClsUser>GetUsersList()
	 {
		 return _LoadDataLineFromFile();
	 }
	//void Print()
	//{
	//	cout << "\nUser Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FName;
	//	cout << "\nLastName    : " << LName;
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nusername    :" << _UserName;
	//	cout << "\nPassword    : " << _Password;
	//	cout << "\nPermission  : " << _Permission;
	//	cout << "\n___________________\n";

	//}
	enum enPermissions
	{
		eAll=-1,eShowListClients=1,eAddNewClients=2,eDeleteClients=4,eUpdateClients=8,eFindClients=16,eTransaction=32,eManageUsers=64,eLoginRegister=128
	};
	 bool CheckAccessPrmissions(enPermissions permissions)
	{
		 /*this->permission ,for object (Currentuser)*/
		 if (this->permission == enPermissions::eAll)
			 return true;
		 if ((permissions & this->permission) == permissions)
			 return true;
		 else
			 return false;
	}
	  void RegisterLogin()
	 {
		  string stDataLine = _PrepareLoginRecord();
		 fstream myfile;
		 myfile.open("LoginRegister.txt", ios::out | ios::app);
		 if (myfile.is_open())
		 {
			 myfile << stDataLine << endl;
			 myfile.close();
		 }
	 }
	
	  static vector<stLoginRegisterRecord>GetLoginRegisterList()
	  {
		  vector<stLoginRegisterRecord>VloginUsers;
		  fstream myfile;
		  myfile.open("LoginRegister.txt", ios::in);/*Read mode */
		  if (myfile.is_open())
		  {
			  string line;
			  stLoginRegisterRecord LoginRegisterRecord;
			  while (getline(myfile, line))
			  {
				  LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(line);
				  VloginUsers.push_back(LoginRegisterRecord);
			  }
			  myfile.close();
		  }
		  return VloginUsers;
	  }
};

