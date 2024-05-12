#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include"ClsDateLibrary.h"
using namespace std;
class Clsutil
{

public:
   
    enum en_rondomtype { smallLetters = 1, capitalLetters = 2, specialcahr = 3, digit = 4, MixChars = 5
    };
    enum en_primnumber { prime = 1, notprime = 2 };
    ///////////////////////////////////////////////////////////////////////////////////////
	static void Srand()
	{
        //Seeds The Rondom Number generator in C++,Called Only once
		srand((unsigned)time(NULL));
	}
	 static int Rondom(int from, int to)
	{
		int rondomnumber = rand() % (to - from + 1) + from;
		return rondomnumber;
	}

     /*Second way to Get Rondom Charchter*/
  static char GetRandomCharacter(en_rondomtype CharType)
  {
      //updated this method to accept mixchars
      if (CharType == MixChars)
      {
          //Capital/Samll/Digits only
          CharType = (en_rondomtype)Rondom(1, 3);
      }
      switch (CharType)
      {

      case en_rondomtype::smallLetters:
      {
          return char(Rondom(97, 122));
          break;
      }
      case en_rondomtype::capitalLetters:
      {
          return char(Rondom(65, 90));
          break;
      }
      case en_rondomtype::specialcahr:
      {
          return char(Rondom(33, 47));
          break;
      }
      case en_rondomtype::digit:
      {
          return char(Rondom(48, 57));
          break;
      }
  defualt:
      {
          return char(Rondom(65, 90));
          break;
      }
      }
  }
  ///////////////////////////////////////////////////////////////////////
 static string  generateword(en_rondomtype chartype, int length)
  {
      string word;

      for (int i = 1; i <= length; i++)
      {
          word = word + GetRandomCharacter(chartype);
      }
      return word;

  }
 static string generatekey(en_rondomtype CharType = capitalLetters)
  {
      string key = "";
      key = generateword(en_rondomtype::capitalLetters, 4) + "-";
      key = key + generateword(en_rondomtype::capitalLetters, 4) + "-";
      key = key + generateword(en_rondomtype::capitalLetters, 4) + "-";
      key = key + generateword(en_rondomtype::capitalLetters, 4);
      return key;
  }
 static void generatekeys(short numberofkeys)
  {
      for (int i = 1; i <= numberofkeys; i++)
      {
          cout << "Keys[" << i << "]:" << generatekey() << endl;
      }
  }
 /////////////////////////////////////////////////////////////////////////////
   static  void FillMatrexWithRondomNumbers(int arr[3][3], short rows, short col)
     {
         for (int i = 0; i < rows; i++)
         {
             for (int j = 0; j < col; j++)
             {
                 arr[i][j] = Rondom(1, 10);
             }
         }
     }
   static void multiplyTWOmatrex(int arr[3][3], int arr2[3][3], int Multiplyarr[3][3], short rows, short col)
   {
       for (int i = 0; i < rows; i++)
       {
           for (int j = 0; j < col; j++)
           {
               Multiplyarr[i][j] = arr[i][j] * arr2[i][j];
           }
       }
   }
   ////////////////////////////////////////////////////////////////////////////
   static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
   {
       for (int i = 0; i < arrLength; i++)
           arr[i] = Rondom(From, To);
   }
   static void FillArrayWithRandomWords(string arr[100], int arrLength, en_rondomtype CharType, short Wordlength)
   {
       for (int i = 0; i < arrLength; i++)
           arr[i] = generateword(CharType, Wordlength);
   }
   static void FillArrayWithRandomKeys(string arr[100], int arrLength, en_rondomtype CharType)
   {
       for (int i = 0; i < arrLength; i++)
           arr[i] = generatekey(CharType);
   }
   ///////////////////////////////////////////////////////////////////////////////////
   static void swap(int& num1, int& num2)
   {
       int temp;
       temp = num1;
       num1 = num2;
       num2 = temp;
   }
   static void swap(double & num1, double& num2)
   {
       double temp;
       temp = num1;
       num1 = num2;
       num2 = temp;
   }
   static void swap(bool& num1, bool& num2)
   {
       bool temp;
       temp = num1;
       num1 = num2;
       num2 = temp;
   }
   static void swap(string& num1, string& num2)
   {
       string temp;
       temp = num1;
       num1 = num2;
       num2 = temp;
   }
   static void swap(char& num1, char& num2)
   {
       char temp;
       temp = num1;
       num1 = num2;
       num2 = temp;
   }
   static  void Swap(ClsDateLibrary & A,ClsDateLibrary & B)
   {
       ClsDateLibrary::SwapTwoDates(A, B);
   }
   //////////////////////////////////////////////////////////////////////////////////////
  static void shufflingarray(int array[100], int length)
   {
       for (int i = 0; i < length; i++)
       {
           swap(array[Rondom(1, length) - 1], array[Rondom(1, length) - 1]);
       }
   }
  static  void shufflingarray(string array[100], int length)
   {
       for (int i = 0; i < length; i++)
       {
           swap(array[Rondom(1, length) - 1], array[Rondom(1, length) - 1]);
       }
   }

  //////////////////////////////////////////////////////////////////////////////////
  static string encryptionText(string text, int encryptionKey)
  {
      for (int i = 0; i <= text.length(); i++)
      {
          text[i] = char((int)text[i] + encryptionKey);

      }
      return text;
  }
  static string decryptionText(string text, int encryptionKey)
  {
      for (int i = 0; i <= text.length(); i++)
      {
          text[i] = char((int)text[i] - encryptionKey);

      }
      return text;
  }
  ///////////////////////////////////////////////////////////////////////////////////
  static string Tabs(short NumberofTabs)
  {
      string tab = "";
      for (int i = 1; i < NumberofTabs; i++)
      {
          tab = tab + "\t";
      }
      return tab;
  }
   //////////////////////////////////////////////////////////////////////////////////
  
 static bool retrialpassword(string password)
 {
     int counter = 0;
     string word = "";
     for (int i = 65; i < 90; i++)
     {
         for (int j = 65; j <= 90; j++)
         {
             for (int k = 65; k <= 90; k++)
             {
                 counter++;
                 word = word + char(i);
                 word = word + char(j);
                 word = word + char(k);

                 cout << "Trial[" << counter << "]:" << word << endl;
                 if (word == password)
                 {
                     cout << "the password is :" << word << endl <<
                         "found after " << counter << "Trial(s)" << endl;
                     return true;
                 }
                 word = "";
             }
         }
     }
     return false;
 }
 static string NumberToText(int Number)
 {

     if (Number == 0)
     {
         return "";
     }

     if (Number >= 1 && Number <= 19)
     {
         string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
     "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
       "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

         return  arr[Number] + " ";

     }

     if (Number >= 20 && Number <= 99)
     {
         string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
         return  arr[Number / 10] + " " + NumberToText(Number % 10);
     }

     if (Number >= 100 && Number <= 199)
     {
         return  "One Hundred " + NumberToText(Number % 100);
     }

     if (Number >= 200 && Number <= 999)
     {
         return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
     }

     if (Number >= 1000 && Number <= 1999)
     {
         return  "One Thousand " + NumberToText(Number % 1000);
     }

     if (Number >= 2000 && Number <= 999999)
     {
         return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
     }

     if (Number >= 1000000 && Number <= 1999999)
     {
         return  "One Million " + NumberToText(Number % 1000000);
     }

     if (Number >= 2000000 && Number <= 999999999)
     {
         return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
     }

     if (Number >= 1000000000 && Number <= 1999999999)
     {
         return  "One Billion " + NumberToText(Number % 1000000000);
     }
     else
     {
         return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
     }


 }


};