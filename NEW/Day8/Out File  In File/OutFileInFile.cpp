#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void main()
{
	ofstream  oFile("file.txt");
	oFile << "String1"
		<< ' '
		<< 2
		<< ' '
		<< 3
		<< "String2 String3";
	oFile << "String4"
		<< ' '
		<< 4.1
		<< 5
		<< 'C'
		<< 6.7
		<< endl;
	oFile.close();

	/*
	The extraction operator (>>)
		takes the space/blank (' ') as a separator
		the first non-numeric character identifies the end of a decimal number
		the first non-numeric character and dot (.) identifies the end of a whole number
	*/
	string str1, str2, str3, str4;
	int a, b, m, n;
	double d;
	char ch1, ch2;

	ifstream iFile("file.txt");
	if (!iFile)
	{
		cout << "Error in opening fhe file" << endl;
		return;
	}
	iFile >> str1
		>> a
		>> b
		>> str2
		>> str3
		>> d
		>> ch1
		>> m
		>> ch2
		>> n;
	iFile.close();

	cout << str1 << endl;
	cout << a << endl;
	cout << b << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << d << endl;
	cout << ch1 << endl;
	cout << m << endl;
	cout << ch2 << endl;
	cout << n << endl;

	/*
	The getline() function considers the entire input as a sequence of charactes (a string)
	*/
	char buf[80];
	iFile.open("file.txt");
	if (!iFile)
	{
		cout << "Error in opening fhe file" << endl;
		return;
	}
	iFile.getline(buf, 80, '\n');
	cout << buf << endl;

	return;
}
