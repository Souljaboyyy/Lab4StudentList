#pragma once
#include<windows.h>
struct Student {
	char* Name;
	char* Surname;
	char* Group;
	int Age;
	long long Number;
	int Marks[5];
	struct Student* next;
};
typedef struct Student Student;
Student* init();
Student* createrandomstudent();
void output(Student* list);
Student* deletestudent(Student* list, int number);
void deletebysurname(Student* list, char* surname);
Student* deletebadstudents(Student* list);
void outputgoodstudents(Student* list);
void outputmates(Student* list, char* group);
BOOL contains(char* string, char* substring);
void outputbysurname(Student* list, char* surname);
void puttofile(Student* list);
void FreeList(Student** list);
void loadfromfile(Student** list);

