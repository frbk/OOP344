#include <iostream>

using namespace std;
template <class T>
int find(T arr[], T val, unsigned int size)
{
	for (int i=0 ; i<size ; i++)
	{
		if (val == arr[i])
			return i;
	}
	return -1;
}


void main()
{
	char cArr[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	char cValF = 'e', cValN = 'k';
	short sArr[]= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	short sValF = 3, sValN = 15;
	long lArr[] = {101, 102, 103, 104, 105, 106, 107, 108, 109};
	long lValF = 102, lValN = 222;
	double dArr[]= {11.11, 22.22, 33.33, 44.44, 55.55, 66.66, 77.77, 88.88, 99.99};
	double dValF = 77.77, dValN = 444.444;

	cout << cValF << " found at index=" << find(cArr, cValF, sizeof(cArr)/sizeof(cArr[0])) << endl;
	cout << cValN << " found at index=" << find(cArr, cValN, sizeof(cArr)/sizeof(cArr[0])) << endl;
	cout << sValF << " found at index=" << find(sArr, sValF, sizeof(sArr)/sizeof(sArr[0])) << endl;
	cout << sValN << " found at index=" << find(sArr, sValN, sizeof(sArr)/sizeof(sArr[0])) << endl;
	cout << lValF << " found at index=" << find(lArr, lValF, sizeof(lArr)/sizeof(lArr[0])) << endl;
	cout << lValN << " found at index=" << find(lArr, lValN, sizeof(lArr)/sizeof(lArr[0])) << endl;
	cout << dValF << " found at index=" << find(dArr, dValF, sizeof(dArr)/sizeof(dArr[0])) << endl;
	cout << dValN << " found at index=" << find(dArr, dValN, sizeof(dArr)/sizeof(dArr[0])) << endl;
}
