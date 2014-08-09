#include <iostream>
using namespace std;

void main(int argc, char *argv[], char *env[])
{
	int i;
	for (i=0 ; env[i] ; i++)
		cout << env[i] << endl;
	cout << endl;

	for (i=0 ; i<argc ; i++)
		cout << argv[i] << endl;
	cout << endl;
}