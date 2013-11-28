#include <iostream>
using namespace std;

void MergeSort(int arr[], int len, int arrTmp[]);

void main()
{
	int arr[] = {6,8,2,14,7,11,1,12,5,9,3,4,15,10,13};
	int len = sizeof(arr)/sizeof(arr[0]);
	cout << "Before Merge Sort" << endl;
	for ( int i=0 ; i<len ; i++)
		cout << arr[i] << ", ";
	cout << endl;

	int *arrTmp = new int[len];
	MergeSort(arr, len, arrTmp);
	cout << "After Merge Sort" << endl;
	for ( int i=0 ; i<len ; i++)
		cout << arr[i] << ", ";
	cout << endl;
	delete arrTmp;
}

void MergeSort(int arr[], int len, int arrTmp[])
{
	int Temp;
	int len1, i, j, k;
	len1 = len/2;
	int *arr2 = arr + len1;
	int len2 = len - len1;

	if (len>2)
	{
		MergeSort(arr, len1, arrTmp);
		MergeSort(arr2, len2, arrTmp);
	}
	else if (len==2 && arr[0]>arr[1])
	{
		Temp = arr[0];
		arr[0] = arr[1];
		arr[1] = Temp;
	}

	i = j = k = 0;
	while (i<len1 || j<len2)
	{
		if (i<len1 && j<len2)
		{
			if (arr[i] < arr2[j])
				arrTmp[k++] = arr[i++];
			else
				arrTmp[k++] = arr2[j++];
		}
		else if (i<len1)
			arrTmp[k++] = arr[i++];
		else
			arrTmp[k++] = arr2[j++];
	}
	for ( i=0 ; i<len ; i++)
		arr[i] = arrTmp[i];
}
