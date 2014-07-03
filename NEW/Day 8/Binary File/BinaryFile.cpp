#include <iostream>
#include <fstream>
#include <string>

#define SIZE_BUF   15

using namespace std;

void main()
{
	char bFileName[] = "file.dat";
	int iBuf[SIZE_BUF] = {1, 6, 8, 3, 7, 2, 9 ,5};
	int i;

	ofstream  oFile(bFileName, ios::binary);
	cout << "Displaing the buffer iBuf that will be saved to the file" << endl;
	for ( i=0 ; i<SIZE_BUF ; i++ )
		cout << iBuf[i] << ", ";
	cout << endl << endl;
	// Saving the buffer iBuf in the file
	oFile.write(reinterpret_cast<char *>(iBuf), sizeof(iBuf));
	oFile.close();

	// Erasing the buffer iBuf
	for ( i=0 ; i<SIZE_BUF ; i++ )
		iBuf[i] = 0;

	cout << "Displaing the buffer iBuf after erase" << endl;
	for ( i=0 ; i<SIZE_BUF ; i++ )
		cout << iBuf[i] << ", ";
	cout << endl << endl;

	ifstream  iFile(bFileName, ios::binary);
	iFile.read(reinterpret_cast<char *>(iBuf), sizeof(iBuf));
   while (!iFile.eof())
   {
      cout << "Read another record." << endl;
      iFile.read(reinterpret_cast<char *>(iBuf), sizeof(iBuf));
   }
	iFile.close();

	cout << "Displaing the buffer iBuf filled with the data from the file" << endl;
	for ( i=0 ; i<SIZE_BUF ; i++ )
		cout << iBuf[i] << ", ";
	cout << endl << endl;

	return;
}
