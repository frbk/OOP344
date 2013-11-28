#include <iostream>
using namespace std;

void PrintBackwards(char *szArr);
void ReverseInPlaceArray(char *szArr, unsigned int len);

void main()
{
	char szArr[80];
	cout << "Input a string: ";
	cin.getline(szArr, 80);
	cout << "Backwards printing the input string through recursion: ";
	PrintBackwards(szArr);
	cout << endl;

	cout << "Before reversing the array: " << szArr << endl;
	ReverseInPlaceArray(szArr, strlen(szArr));
	cout << "After reversing the array: " << szArr << endl;
}


void PrintBackwards(char *cArr)
{
	if (*cArr == 0)
		return;
	else
	{
		PrintBackwards(cArr+1);
		cout << cArr[0];
	}
}

void ReverseInPlaceArray(char *szArr, unsigned int len)
{
	char temp;
	for (int i=0 ; i<len/2 ; i++)
	{
		temp = szArr[i];
		szArr[i] = szArr[len-1-i];
		szArr[len-1-i] = temp;
	}
}

