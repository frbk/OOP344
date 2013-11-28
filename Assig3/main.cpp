/*
Fedor Barannik
SIN:028-127-108
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Course.h"
#include "StudentRecordData.h"
#include "SingleLinkedList.h"
#include "Student.h"

using namespace std;

int main(){
	//variable declaration
   double Marks[MAX_COURSES];
   unsigned int Age;
   unsigned int ID;
   unsigned int CourseCount;
   char FirstName[LEN_FN];
   char LastName[LEN_FN];
   Course  Courses[MAX_COURSES];
   char input[] = "OOP344.dat";
   char output[] = "OUTPUT.txt";
   Student *node;
   Student *nd;
   SingleLinkedList lList;

	//Open file and get info into the memory
   
   ifstream ifile(input,ios::binary);
   ifile.seekg(0, ios::end);
   int FileSize = ifile.tellg();
   int RecCount = FileSize / sizeof(Student);
   ifile.seekg(0);
   RecCount = RecCount+1;
  // cout << FileSize << " " << RecCount << endl;*/
  // while(!ifile.eof()){
   for (int k = 0 ; k<RecCount ; k++ ){
   	for(int i=0;i < MAX_COURSES;i++){
   		Marks[i] = 0;
   	}
   	ifile.read(reinterpret_cast<char *>(&Marks),sizeof(double)*18);
   	ifile.read(reinterpret_cast<char *>(&Age),sizeof(Age));
   	ifile.read(reinterpret_cast<char *>(&ID),sizeof(ID));
   	ifile.read(reinterpret_cast<char *>(&CourseCount),sizeof(CourseCount));
   	ifile.read(reinterpret_cast<char *>(&FirstName),sizeof(FirstName));
   	ifile.read(reinterpret_cast<char *>(&LastName),sizeof(LastName));
   	for(int i = 0; i < MAX_COURSES;i++){
   		ifile.read(reinterpret_cast<char *>(&Courses[i].Semester),sizeof(Courses[i].Semester));
   		ifile.read(reinterpret_cast<char *>(&Courses[i].Name),sizeof(Courses[i].Name));
   	}
   	node = new Student(Marks,Age,ID,CourseCount,FirstName,LastName,Courses);
   	lList.AddNode(node);
   }
   ifile.close();
	//sort node (from smallest to largest)
   lList.BubbleSort();
	//Write info from memory into file 
   ofstream ofile(output,ios::out);
   ofile.precision(2);
   ofile.setf(ios::fixed,ios::floatfield);
    ofile <<setw(10)<<"Last Name" << setw(12)<<"First Name"<<setw(5)<< "Age" << setw(12)<< "Student ID" <<setw(15)<<"Course" <<setw(8)<<"Marks\n";
    ofile <<setw(10)<< "========="<< setw(12)<<"=========="<<setw(5)<< "===" << setw(12)<< "==========" <<setw(15)<<"======" <<setw(8)<<"=====\n";
     for (nd = lList.getFirstNode(); nd; nd = lList.getNextNode(nd)){
     	 ofile <<setw(10)<< nd->getLastName() <<setw(12)<<nd->getFirstName()<<setw(5)<<nd->getAge()<< setw(12)<<nd->getID() <<setw(22)<<setprecision(2)<<nd->getAverage()<<endl;
       for(int i = 0; i < nd->getCourseCount();i++){
         if(((int)nd->getCourses()[i].Semester) != ((int)nd->getCourses()[i-1].Semester)){
            ofile<<setw(45)<<"Sem "<<(int)nd->getCourses()[i].Semester<<":"<<setw(7) <<nd->getCourses()[i].Name<< setw(7)<<setprecision(2)<<nd->getMarks()[i]<<endl;            
         }else{
            ofile<<setw(54)<<nd->getCourses()[i].Name<< setw(7)<<setprecision(2)<<nd->getMarks()[i]<<endl;
         }
       }
     }
   ofile.close();

	return 0;
}
/*Sample output
 Last Name  First Name  Age  Student ID         Course  Marks
 =========  ==========  ===  ==========         ======  =====
   Dursley    Caroline   26      849371                  0.00
                                         Sem 1: APC100   0.00
                                                EAC150   0.00
                                                ICA002   0.00
                                                IOS110   0.00
                                                IPC144   0.00
                                         Sem 2: ULI101   0.00
                                                DBS201   0.00
                                                IBC233   0.00
                                                INT222   0.00
                                                OOP244   0.00
                                         Sem 3: DBS301   0.00
                                                INT322   0.00
                                                SYS366   0.00
                                                BAC344   0.00
                                                OOP344   0.00
*/