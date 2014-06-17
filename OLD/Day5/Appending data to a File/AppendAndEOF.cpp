#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void main()
{
	char FileName[] = "file.txt";
	ofstream  oFile(FileName);

	// Line 1
	oFile << "Line 1" << ' ' << 2 << ' ' << 3 << "String2 String3";
	oFile << "String4" << ' ' << 4.1 << 5 << 'C' << 6.7 << endl;

	// Line 2
	oFile << "Line 2" << ' ' << 20 << ' ' << 30 << "String20 String30";
	oFile << "String40" << ' ' << 40.1 << 50 << 'C' << 60.7 << endl;

	// Line 3
	oFile << "Line 3" << ' ' << 200 << ' ' << 300 << "String200 String300";
	oFile << "String400" << ' ' << 400.1 << 500 << 'C' << 600.7 << endl;

	// Character I/O
	char iBuf[] = "This is a great example of Character I/O\n";
	for (int i=0 ; iBuf[i] ; i++)
		oFile.put(iBuf[i]);
	oFile.close();

	char buf[80];
	ifstream iFile;

	iFile.open(FileName);
	if (!iFile)
	{
		cout << "Error in opening fhe file" << endl;
		return;
	}
	while (!iFile.eof())
	{
		iFile.getline(buf, 80, '\n');
		cout << buf << endl;
	}
	iFile.close();


	char iBufTrunc[] = "This is a great example of Truncating a file when open";
	char iBufApp[] = "This is a great example of Appending to an existing file";
	// The ios_base::out is implicit value that truncates the file when open
	oFile.open(FileName /*, ios_base::out*/);
	oFile << iBufTrunc << endl;
	oFile.close();

	oFile.open(FileName , ios_base::app);
	oFile << iBufApp << endl;
	oFile.close();

	iFile.clear();  // the EOF flag remained set on the iFile object from previous usage and needs to be cleared.
	iFile.open(FileName);
	if (iFile.fail())
	{
		cout << "Error in opening fhe file" << endl;
		return;
	}
	while (!iFile.eof())
	{
		iFile.getline(buf, 80, '\n');
		cout << buf << endl;
	}
	iFile.close();
	cout << "End Of Program" << endl;

	return;
}
