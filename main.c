#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include"Header.h"

 /*struct Student {
	char* Name;
	char* Surname;
	char* Group;
	int Age;
	long long Number;
	int Marks[5];
	struct Student* next;
};
 typedef struct Student Student;

 char* mass1[5] = { "Petr","Nikata","Sasha","Maksim","Nastya" };
 char* mass2[5] = { "Petrov","Sobolev","Nikiforof","Ivanov","Mir" };
 char* mass3[5] = { "MK-101","MP-301","MK-201","MT-402","MN-102" };

 Student* init() {
	 Student *student=(Student*)malloc(sizeof(Student));
	 char buff[256];
	 printf("Name : ");
	 gets_s(buff, 255);
	 student->Name = (char*)malloc(sizeof(char)* (strlen(buff)+1));
	 strcpy_s(student->Name, strlen(buff) + 1, buff);

	 printf("Surname : ");
	 gets_s(buff, 255);
	 student->Surname = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
	 strcpy_s(student->Surname, strlen(buff) + 1, buff);

	 printf("Group : ");
	 gets_s(buff, 255);
	 student->Group = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
	 strcpy_s(student->Group, strlen(buff) + 1, buff);

	 printf("Age : ");
	 scanf_s("%d", &student->Age);
	 
	 
	 printf("Number : ");
	 scanf_s("%lli", &student->Number);
	

	 printf("Marks : ");
	 for (int i = 0; i < 5; i++)
		 scanf_s("%d", &student->Marks[i]);
	 
	 char dop;
	 gets_s(&dop,1);
	 student->next = 0;
	 return student;
 }

 Student* createrandomstudent();

 void add(Student** list,BOOL flag) {
	
	 if ((*list) == NULL)
	 {
		 if (flag == FALSE)
			*list = init();
		 else
			*list = createrandomstudent();

		 return;
	 }
 	
	 while ((*list)->next != 0) {
		 list = &((*list)->next);
	 }
	 if (flag == FALSE)
		 (*list)->next = init();
	 else
		 (*list)->next = createrandomstudent();
 }

 void output(Student* list) {
	 if (list == NULL)
	 {
		 printf("List is empty\n");
		 return;
	 }
 	
	 while (list != 0) {
		 printf("Name %s\n", list->Name);
		 printf("Surname %s\n", list->Surname);
		 printf("Group %s\n", list->Group);
		 printf("Age %d\n", list->Age);
		 printf("Number %lli\n", list->Number);
		 printf("Marks ");
		 for (int i = 0; i < 5; i++)
			 printf("%d ", list->Marks[i]);
		 printf("\n");
		 list=list->next;
	 }
	 printf("\n");
 }

 Student* createrandomstudent() {
	 Student* student = (Student*)malloc(sizeof(Student));
	 char buff[256];
	 
	 int rnd = rand() % 5;
	 strcpy_s(buff, strlen(mass1[rnd]) + 1, mass1[rnd]);
	 student->Name = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
	 strcpy_s(student->Name, strlen(buff) + 1, buff);

	 rnd = rand() % 5;
	 strcpy_s(buff, strlen(mass2[rnd])+ 1, mass2[rnd]);
	 student->Surname = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
	 strcpy_s(student->Surname, strlen(buff) + 1, buff);

	 
	 rnd = rand() % 5;
	 strcpy_s(buff, strlen(mass3[rnd]) + 1, mass3[rnd]);
	 student->Group = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
	 strcpy_s(student->Group, strlen(buff) + 1, buff);

	 student->Age = rand() % 30 + 18;


	 student->Number=rand();


	 for (int i = 0; i < 5; i++)
		 student->Marks[i] = rand() % 5;

	 
	 student->next = 0;
	 return student;
 }

Student* deletestudent(Student* list, int number)
 {
	Student* temp = list;
	int i = 1;

 	if (number != 1)
 	{
 		while (i != number - 1)
 		{
 			temp = temp->next;
			++i;
 		}

 		Student* temp = list->next->next;
		free(list->next);
		list->next = temp;
 	}
	else
	{
		if (list->next == NULL)
		{
			free(list);
			return NULL;
		}
		else
		{
			list = list->next;
			free(temp);
			return list;
		}
	}
 	
 }

 void deletebysurname(Student* list, char* surname) {
	 while ((list->next != NULL)&&strcmp(surname,list->next->Surname)) {
		 list = list->next;
	 }
	 if ((list->next)!=NULL)
	 { 
		Student* huist = list->next->next;
		free(list->next);
		list->next = huist; 
	 }
 }

 Student* deletebadstudents(Student* list) {
	 Student* temp=list;
	 int kolvo = 1;
	 while (temp != 0) {
		 int sum = 0;
		 for (int i = 0; i < 5; i++)
			 sum += temp->Marks[i];
		 if (sum / (double)5 < 4) 
		 {
			list = deletestudent(list, kolvo);
			temp = list;
			kolvo = 1;
			continue;
		 }
		 kolvo++;
		 temp = temp->next;
	 }

	 return list;
 }

void outputgoodstudents(Student* list)
 {
	 if (list == NULL)
	 {
		 printf("List is empty\n");
		 return;
	 }
 	
	 while (list != 0) {
		int sum = 0;

	 	for (int i = 0; i < 5; ++i)
	 	{
			sum += list->Marks[i];
	 	}
	 	
	 	if (sum / (double)5 >= 4)
	 	{
			 printf("Name %s\n", list->Name);
		 	printf("Surname %s\n", list->Surname);
		 	printf("Group %s\n", list->Group);
		 	printf("Age %d\n", list->Age);
		 	printf("Number %lli\n", list->Number);
		 	printf("Marks ");
		 	for (int i = 0; i < 5; i++)
		 		printf("%d ", list->Marks[i]);
		 	printf("\n");
		 }
	 	
		 list=list->next;
	 }
	 printf("\n");
 }

void outputmates(Student* list, char* group)
 {
	 if (list == NULL)
	 {
		 printf("List is empty\n");
		 return;
	 }
 	
	 while (list != 0) 
	 {
	 	if (!strcmp(list->Group, group))
	 	{
			printf("Name %s\n", list->Name);
		 	printf("Surname %s\n", list->Surname);
		 	printf("Group %s\n", list->Group);
		 	printf("Age %d\n", list->Age);
		 	printf("Number %lli\n", list->Number);
		 	printf("Marks ");
		 	for (int i = 0; i < 5; i++)
		 		printf("%d ", list->Marks[i]);
		 	printf("\n");
		 }
	 	
		 list=list->next;
	 }
	 printf("\n");
 }

 BOOL contains(char* string, char* substring)
 {
	 int i = 0;
 	
	for (i; i < strlen(substring); ++i)
	{
		if (string[i] != substring[i])
			break;
	}

 	if (i + 1 != strlen(substring))
 	{
		return FALSE;
 	}

	return TRUE;
 }

void outputbysurname(Student* list, char* surname)
 {
	 if (list == NULL)
	 {
		 printf("List is empty\n");
		 return;
	 }
 	
	 while (list != 0) 
	 {
	 	if (contains(list->Surname, surname))
	 	{
			printf("Name %s\n", list->Name);
		 	printf("Surname %s\n", list->Surname);
		 	printf("Group %s\n", list->Group);
		 	printf("Age %d\n", list->Age);
		 	printf("Number %lli\n", list->Number);
		 	printf("Marks ");
		 	for (int i = 0; i < 5; i++)
		 		printf("%d ", list->Marks[i]);
		 	printf("\n");
		 }
	 	
		 list=list->next;
	 }
	 printf("\n");
 }

void puttofile(Student* list)
 {
	FILE* outputfile;
	fopen_s(&outputfile, "list.txt", "w");

 	if (list == NULL)
	 {
		 fprintf(outputfile, "List is empty\n");
		 return;
	 }
 	
	 while (list != 0) {
		 fprintf(outputfile, "Name %s\n", list->Name);
		 fprintf(outputfile, "Surname %s\n", list->Surname);
		 fprintf(outputfile, "Group %s\n", list->Group);
		 fprintf(outputfile, "Age %d\n", list->Age);
		 fprintf(outputfile, "Number %lli\n", list->Number);
		 fprintf(outputfile, "Marks ");
		 for (int i = 0; i < 5; i++)
			 fprintf(outputfile, "%d ", list->Marks[i]);
		 fprintf(outputfile, "\n\n");
		 list=list->next;
	 }
	 fclose(outputfile);
 }

void FreeList(Student** list)
 {
	Student* temp = *list;
	*list = (*list)->next;

 	while ((*list)->next != NULL)
 	{
		free(temp);
 		temp = *list;
		*list = (*list)->next;
 	}

	free(temp);
	free(*list);
	*list = NULL;
 }

void loadfromfile(Student** list)
 {
	if (*list != NULL)
	{
		printf("Can't read from file because list isn't empty\n Do you want to create new?");
		char choise = _getch();
		switch (choise)
		{
		case '1':
			{
				FreeList(&list);
				break;
			}
		case '2':
			{
				return;
			}
		}
	}

	FILE* inputfile;
	fopen_s(&inputfile, "list.txt", "r");
 	Student *student = (Student*)malloc(sizeof(Student));
	Student* listhead = student;
 	while (!feof(inputfile))
 	{
		 char buff[256];
		 fseek(inputfile, strlen("Name "), SEEK_CUR);
		 fgets(buff, 255, inputfile);
		 student->Name = (char*)malloc(sizeof(char)* (strlen(buff)+1));
		 strcpy_s(student->Name, strlen(buff) + 1, buff);
		 

 		 fseek(inputfile, strlen("Surname "), SEEK_CUR);
		 fgets(buff, 255, inputfile);
		 student->Surname = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
		 strcpy_s(student->Surname, strlen(buff) + 1, buff);
 		

		 fseek(inputfile, strlen("Group "), SEEK_CUR);
		 fgets(buff, 255, inputfile);
		 student->Group = (char*)malloc(sizeof(char) * (strlen(buff) + 1));
		 strcpy_s(student->Group, strlen(buff) + 1, buff);
 		 

		 fseek(inputfile, strlen("Age "), SEEK_CUR);
		 fscanf_s(inputfile, "%d", &student->Age);
 		 fseek(inputfile, 1, SEEK_CUR);
		 
		 
		 fseek(inputfile, strlen("Number "), SEEK_CUR);
		 fscanf_s(inputfile, "%lli", &student->Number);
		 fseek(inputfile, 1, SEEK_CUR);

		 fseek(inputfile, strlen("Marks "), SEEK_CUR);
		 for (int i = 0; i < 5; i++)
		 {
			 fscanf_s(inputfile, "%d", &student->Marks[i]);
			 fseek(inputfile, 1, SEEK_CUR);
		 }

		 if (!fgets(buff, 256, inputfile))
		 {
			 student->next = (Student*)malloc(sizeof(Student));
			 student = student->next;
		 }
		 else
		 {
			 student->next = NULL;
		 }
 	}

	*list = student;

	fclose(inputfile);
 }*/

int main(){
	srand(time(NULL));

	Student* list = createrandomstudent();

 	while (1)
 	{
 		printf("1. Add \n2. Add random\n3. Show list\n4. Delete student by number\n5. Delete student by surname\n6. Delete bad students\n7. Show mates\n8. Show good students\n9. Output into file\na. Read from file\nb. Show by surname\n");
		char choose;
		choose = _getch();
 		switch(choose)
 		{
			case '1':
				{
					add(&list, FALSE);
					break;
				}
			case '2':
				{
					add(&list, TRUE);
					break;
				}
			case '3':
				{
					output(list);
					break;
				}
			case '4':
				{
					int student;
					scanf_s("%d", &student);
					list = deletestudent(list, student);
					break;
				}
			case '5':
				{
					char surname[256];
					gets_s(surname, 256);
					deletebysurname(list, surname);
					break;
				}
 			case '6':
				{
					list = deletebadstudents(list);
					break;
				}
			case '7':
				{
				char group[256];
				gets_s(group, 256);
				outputmates(list, group);
				break;
				}
			case '8':
				{
					outputgoodstudents(list);
					break;
				}
			case '9':
				{
					puttofile(list);
					break;
				}
			case 'a':
				{
					loadfromfile(&list);
					break;
				}
			case 'b':
				{
					char surname[256];
					gets_s(surname, 256);
					outputbysurname(list, surname);
					break;
				}
 			
 		}
 	}
 	
	system("pause");
	return 0;
}