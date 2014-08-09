#include "SingleLinkedList.h"
#include <string.h>

SingleLinkedList::SingleLinkedList()
{
	root = 0;
}

SingleLinkedList::~SingleLinkedList()
{
	
	Student *curr = root;
	Student *next;

	while (curr)
	{
		next = curr->next;
		delete curr;
		curr = next;
	}
}
void SingleLinkedList::AddNode(Student *node){
	if (!root){
		root = node;
		return;
	}
	node->next = root;
	root = node;
}
Student *SingleLinkedList::getFirstNode()
{
	return root;
}


Student *SingleLinkedList::getNextNode(Student *node)
{
	return node->next;
}
void SingleLinkedList::BubbleSort(){
	Student *temphead = getFirstNode();
	Student *tempnode = NULL;
	int counter = 0;
	while (temphead){
		temphead = getNextNode(temphead);
		counter++;
	}
	temphead = getFirstNode();
		for (int i = 0; i < counter;i++){
			while (counter > 0 ){
			//	cout << "a" << endl;
				if (strcmp(temphead->getLastName(), temphead->next->getLastName()) > 0){
				//	cout << strcat(temphead->getLastName(), temphead->getFirstName())  << endl;
				//	cout << "s" << endl;
					tempnode = temphead;
					temphead = temphead->next;
					temphead->next = tempnode;
				//	temphead = getNextNode(temphead);
				}
				counter--;
			}
			//temphead = getFirstNode();
	}
}

void SingleLinkedList::SortCourses(){
	Student *nd;
	//char* tmp;
	char *temp;
	for (nd = getFirstNode(); nd; nd = getNextNode(nd)){
		for (int i = 0; i < nd->getCourseCount();i++){
			for (int j =  0; j< nd->getCourseCount();j++){
				//cout << nd->getCourses()[i].Name << " " << nd->getCourses()[j].Name << " " << strcmp(nd->getCourses()[i].Name, nd->getCourses()[j].Name) << endl;
				if (strcmp(nd->getCourses()[i].Name, nd->getCourses()[j].Name)> 0 && (int)nd->getCourses()[i].Semester == (int)nd->getCourses()[j].Semester){
				//	cout << nd->Courses[i].Name << endl; //test
					temp = nd->Courses[i].Name;
				//	cout << "temp "<< temp << endl;
					strcpy_s(nd->Courses[i].Name, nd->Courses[j].Name);
				//	cout << "at i  " << nd->Courses[i].Name << endl;
					strcpy_s(nd->Courses[j].Name, temp);
				//	cout << "at j  " << nd->Courses[j].Name << endl;
					//cout << tmp << endl;
					//nd->Courses[i].Name = nd->Courses[j].Name;
				//	nd->getCourses()[i].Name = nd->getCourses()[j].Name;
					//nd->getCourses()[j].Name = tmp;
					//cout << nd->getCourses()[i].Name << " " << strcmp(nd->getCourses()[i].Name, nd->getCourses()[i + 1].Name) << endl;
					i++;
				}
			}
		}
		//cout << " " << endl;
	}
	}
/*
void SingleLinkedList::SortCourses(){
	Student *nd;
	char *temp;
	unsigned int First, i;
	int Min;
	for (nd = getFirstNode(); nd; nd = getNextNode(nd)){
		for (First = 0; First < nd->getCourseCount() - 1; First++){
			Min = First;
			for (i = First; i < nd->getCourseCount(); i++){
				if (strcmp(nd->getCourses()[Min].Name, nd->getCourses()[i].Name)> 0 && (int)nd->getCourses()[Min].Semester == (int)nd->getCourses()[i].Semester){
					Min = i;
				}
			}
			temp = nd->Courses[Min].Name;
			strcpy_s(nd->Courses[Min].Name, nd->Courses[First].Name);
			strcpy_s(nd->Courses[First].Name, temp);
		}
	}
	}*/
/*
void SingleLinkedList::SortCourses(){
	Student *nd;
	char *temp;
	int flag,len;
	unsigned int i;
	flag = 1;
	for (nd = getFirstNode(); nd; nd = getNextNode(nd)){
		len = nd->getCourseCount();
		while (flag){
			flag = 0;
			for (i = 0; i <len - 1;i++){
				if (strcmp(nd->getCourses()[i].Name, nd->getCourses()[i+1].Name)> 0 && (int)nd->getCourses()[i].Semester == (int)nd->getCourses()[i+1].Semester){
					temp = nd->getCourses()[i].Name;
					strcpy_s(nd->getCourses()[i].Name, nd->getCourses()[i + 1].Name);
					strcpy_s(nd->getCourses()[i].Name, temp);
					flag = 1;
				}
			}
			len--;
		}
	}

}*/
