#include<stdio.h>
#include<string.h>

typedef struct {
	//Define members {variables}
	char name[30]; //Name is an array of character, size 30
	char phone[15];
	int age;
}Customer;

//At this point, we own a new data type it's name, Customer
char *gets(char*); //Prototype for gets function to avoid the compiler warning

//Define functions here
void printCustomer(Customer myCustomers[], int customerSize){
		//Print out the data pf the 2 customers
	for(int i = 0; i < customerSize; i++){
		printf("Name: %s\n Phone: %s\n Age: %d\n", 
				myCustomers[i].name, 
				myCustomers[i].phone, 
				myCustomers[i].age
				);
	}
}

int searchStudent(char name[], Customer myCustomers[], int customerSize){
	//Loop through the array of customers
	for(int i = 0; i < customerSize; i++)
		if(strcmp(name, myCustomers[i].name) == 0) 
			return i;
		return -1;
}//Search Student

int main(int argc, char* argv[]){
	//Define an array of two customers
	Customer myCustomers[2];
	int customerSize = sizeof(myCustomers)/sizeof(myCustomers[0]);
	char findName[30];
	
	//Get the data from the user(keyboard)
	for(int i = 0; i < customerSize; i++){
		printf("Enter the name of Customer #%d\n", i+1);
		scanf("%s", myCustomers[i].name);
		printf("Enter the phone of Customer #%d\n", i+1);
		scanf("%s", myCustomers[i].phone);
		printf("Enter the age of Customer #%d\n", i+1);
		scanf("%d", &myCustomers[i].age); 
		//getchar(); //Use getchar
	}

	printCustomer(myCustomers, customerSize);

	//Get name from user input
	//Pass it to searchStudent function and return number or -1.
	printf("Who are you looking for?\n");
	printf("Enter a name to be searched \n");
	scanf("%s", findName);

	//Call the search
	int elementNum = -1;
	elementNum = searchStudent(findName, myCustomers, customerSize);
	
	if (elementNum != -1){
		printf("Found %s at element %d", myCustomers[elementNum].name, elementNum);
	} else {
		printf("Not found");
	}
}//int main

