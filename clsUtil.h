#pragma once
#include <string>
#include <cstdlib>
#include<cmath>
#include<vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "clsDate.h"
using namespace std;
class clsUtil
{
private:


public:
	enum enCharType {
		SamallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};

	static void  Srand()
	{
		//Seeds the random number generator in C++, called only once
		srand((unsigned)time(NULL));
	}

	static  int RandomNumber(int From, int To)
	{
		//Function to generate a random number
		int randNum = rand() % (To - From + 1) + From;
		return randNum;
	}

	static char GetRandomCharacter(enCharType CharType)
	{

		//updated this method to accept mixchars
		if (CharType == MixChars)
		{
			//Capital/Samll/Digits only
			CharType = (enCharType)RandomNumber(1, 3);

		}

		switch (CharType)
		{

		case enCharType::SamallLetter:
		{
			return char(RandomNumber(97, 122));
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
	defualt:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		}
	}

	static  string GenerateWord(enCharType CharType, short Length)

	{
		string Word;

		for (int i = 1; i <= Length; i++)

		{

			Word = Word + GetRandomCharacter(CharType);

		}
		return Word;
	}

	static string  GenerateKey(enCharType CharType = CapitalLetter)
	{

		string Key = "";


		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);


		return Key;
	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{

		for (int i = 1; i <= NumberOfKeys; i++)

		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}

	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateKey(CharType);
	}

	static  void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);

	}

	static  void ShuffleArray(int arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}

	}

	static string  Tabs(short NumberOfTabs)
	{
		string t = "";

		for (int i = 1; i < NumberOfTabs; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;

	}

	static string  EncryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string  DecryptText(string Text, short EncryptionKey)
	{

		for (int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}
		return Text;

	}


	static int ReadPositiveNumber(string message)
	{
		int number = 0;
		do
		{
			cout << message << endl;
			cin >> number;

		} while (number <= 0);
		return number;
	}

	enum enPrimeNotPrime { Prime = 1, NotPrime = 2 };

	static enPrimeNotPrime CheckIfNumberIsPrime(int Number)
	{
		int M = round(Number / 2);
		for (int Counter = 2; Counter <= M; Counter++)
		{
			if (Number % Counter == 0)
				return enPrimeNotPrime::NotPrime;
		}
		return enPrimeNotPrime::Prime;
	}

	static void AddNumberToArray(int Number, int arr[100], int& arrLength) {
		arr[arrLength] = Number;
		arrLength++;
	}

	static void CopyArrayUsingAddFunction(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
	{
		for (int i = 0; i < arrLength; i++) {
			AddNumberToArray(arrSource[i], arrDestination, arr2Length);
		}
	}

	static void ReadUserNumbersIntoArray(int arr[100], int& arrLength) {
		bool AddMore = true;
		do {
			AddNumberToArray(ReadPositiveNumber("Enter a number"), arr, arrLength);
			cout << "\nDo you want to add more numbers? [0]: No, [1]: Yes? ";
			cin >> AddMore;
		} while (AddMore);
	}

	static int GenerateRandomNumber(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	static void FillArrayWithRandomNumbers(int arr[100], int& length)
	{
		length = ReadPositiveNumber("Enter a number To fill the array: ");
		for (int i = 0; i < length; i++)
		{
			arr[i] = GenerateRandomNumber(1, 100);
		}
	}

	static void PrintArrayElements(int arr[100], int length)
	{
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	static void CopyArrayInReverse(int arr[100], int arrLength, int arr2[100])
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr2[i] = arr[arrLength - 1 - i];
		}
	}

	static short FindNumberIndex(int arr[100], int arrLength, short Num)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (Num == arr[i])
				return i;
		}
		return -1;
	}

	static bool IsNumberPresentInArray(int arr[100], int arrLength, short Num)
	{
		return FindNumberIndex(arr, arrLength, Num) != -1;
	}

	static void CopyUniqueNumbersToArray(int arrSource[100], int arrDestination[100], int arrLength, int& arr2Length)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (!IsNumberPresentInArray(arrDestination, arr2Length, arrSource[i]))
			{
				AddNumberToArray(arrSource[i], arrDestination, arr2Length);
			}
		}
	}

	static bool IsArrayPalindrome(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
				return false;
		}
		return true;
	}

	static int CountOddNumbers(int arr[100], int Length)
	{
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (arr[i] % 2 != 0)
				count++;
		}
		return count;
	}

	static int CountEvenNumbers(int arr[100], int Length)
	{
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (arr[i] % 2 == 0)
				count++;
		}
		return count;
	}

	static int CountPositiveNumbers(int arr[100], int Length)
	{
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (arr[i] >= 0)
				count++;
		}
		return count;
	}

	static int CountNegativeNumbers(int arr[100], int Length)
	{
		int count = 0;
		for (int i = 0; i < Length; i++) {
			if (arr[i] < 0)
				count++;
		}
		return count;
	}

	static int RoundFloatToInt(float Number)
	{
		if (Number > 0) {
			if (int(Number + 0.5) > int(Number))
				return int(Number + 0.5);
			else
				return int(Number);
		}
		else
		{
			if (int(Number - 0.5) < int(Number))
				return int(Number - 0.5);
			else
				return int(Number);
		}
	}

	static int GetFloorValue(float Number)
	{
		if (Number > 0)
			return int(Number);
		else
			return int(Number) - 1;
	}

	static int ReadValidatedInteger()
	{
		int number;
		cin >> number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "InVaild number please Enter a Number: " << endl;
			cin >> number;
		}
		return number;
	}

	static void Print2DArray10x10(int x[10][10])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10;j++) {
				printf("%0*d  ", 2, x[i][j]);
			}
			cout << "\n";
		}
	}

	static void ReadNumbersIntoVector(vector <int>& vNums)
	{
		char ReadMore = 'Y';
		int Number;
		while (ReadMore == 'Y' || ReadMore == 'y')
		{
			cout << "Please enter a number? ";
			cin >> Number;
			vNums.push_back(Number);
			cout << "\nDo you want to read more numbers? Y/N ?";
			cin >> ReadMore;
		}
	}

	static void PrintIntegerVector(vector <int>& vNums)
	{
		for (int& n : vNums)
		{
			cout << n << endl;
		}
	}

	static void PrintStringVector(vector <string>& vstr)
	{
		for (string& c : vstr)
		{
			cout << c << endl;
		}
	}

	static int CalculatePower(int Base, int Power)
	{
		if (Power == 0)
			return 1;
		else
		{
			return (Base * CalculatePower(Base, Power - 1));
		}
	}

	static void Fill2DArrayWithRandomNumbers(int x[10][10])
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++) {
				x[i][j] = GenerateRandomNumber(1, 99);
			}
		}
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

