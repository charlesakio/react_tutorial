#include <stdio.h>
#include <string.h>

//Define the student structure
//In other words, define a new data type called Student

typedef struct{
	//Define the structure members
	char name[31];
	int age;
}Student;

int main(){
	//Define pointer structure
	Student *studentPointer;

	//Allocate memory storage for two students
	studentPointer = (Student *) calloc(2, sizeof(Student));

	//Populate the allocated memory with the data
	strcpy(studentPointer->name, "Dave");
	studentPointer->age = 25;

	//Move the pointer to the next location allocated for the data
	studentPointer ++;

	//Since the pointer is in the next location, make a new student
	strcpy(studentPointer->name, "Charles");
	studentPointer->age=23;

	//Print the first student, then the second one.
	studentPointer --;
	printf("Name: %s\nAge: %d\n", studentPointer->name, studentPointer->age);

	//Second student
	studentPointer ++;
	printf("Name: %s\nAge: %d", studentPointer->name, studentPointer->age);
}
