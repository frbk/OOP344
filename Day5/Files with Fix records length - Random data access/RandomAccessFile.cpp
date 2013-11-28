#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Student
{
	unsigned int	Age;
	char			fName[30];
	char			lName[30];
	double			Average;
public:
	Student() {}
	void initStudent(unsigned int age, char *fn, char *ln, double ave)
	{
		Age = age;
		strcpy(fName, fn);
		strcpy(lName, ln);
		Average = ave;
	}
	unsigned int getAge() {return Age;}
	string getFirstName() {return fName;}
	string getLastName() {return lName;}
	double getAverage() {return Average;}
};

void main()
{
	int i;
	char yn;
	char bFileName[] = "RandomAccess.dat";
	Student cs;
	cout << "Recording the students in the file." << endl;

	ofstream  oFile(bFileName, ios::binary);
	cs.initStudent(20,"John", "Stuart", .76);
	if (oFile.fail())
	{
		cout << "File fails to open for write" << endl;
		return;
	}
	oFile.write(reinterpret_cast<char *>(&cs), sizeof(cs));
	cs.initStudent(23,"Paul", "Newman", .83),
	oFile.write(reinterpret_cast<char *>(&cs), sizeof(cs));
	cs.initStudent(21, "Mat", "Nielson", .86);
	oFile.write(reinterpret_cast<char *>(&cs), sizeof(cs));
	cs.initStudent(20,"Sam","Cohen", .71);
	oFile.write(reinterpret_cast<char *>(&cs), sizeof(cs));
	cs.initStudent(22,"Angelina","Jolie", .79);
	oFile.write(reinterpret_cast<char *>(&cs), sizeof(cs));
	oFile.close();

	cout << "Display all records in the file" << endl;
	ifstream iFile(bFileName, ios::binary);
	if (iFile.fail())
	{
		cout << "File fails to open for read" << endl;
		return;
	}
	/*
	Possible seek values for the direction parameter:
		ios::beg
		ios::cur
		ios::end
	*/
	iFile.seekg(0, ios::end);					// Position the prompt at the end of the file
	int FileSize = iFile.tellg();				// Get the size of the file
	int RecCount = FileSize / sizeof(Student);	// Calculate the number of records in the file
	iFile.seekg(0);								// Reposition the Prompt at the begining of he file
	for ( i = 0 ; i<RecCount ; i++ )
	{
		iFile.read(reinterpret_cast<char *>(&cs), sizeof(cs));
		cout << "Id= " << i << "  "
			 << setw(15) << cs.getFirstName()
		     << setw(15) << cs.getLastName()
			 << " Age=" << cs.getAge()
			 << " Average=" << cs.getAverage()
			 << endl;
	}

	cout << endl;

	do {
		do {
			cout << "Enter the Student Id you want to review: ";
			cin >> i;
		} while ( i < 0 || i >= RecCount );
		iFile.seekg( i * sizeof(Student));		// Position the prompt at the start of the record
		iFile.clear();
		iFile.read(reinterpret_cast<char *>(&cs), sizeof(Student));
		if (!iFile.fail())
		{
			cout << "Id= " << i << "  "
				 << setw(15) << cs.getFirstName()
			     << setw(15) << cs.getLastName()
				 << " Age=" << cs.getAge()
				 << " Average=" << cs.getAverage()
				 << endl;
		}
		else
			cout << "Error when reading the file" << endl;

		cout << "Continue <Y/N> ? : ";
		cin >> yn;
	} while (yn!='n' && yn!='N');
	iFile.close();


	return;
}
