#include<stdio.h>
#include<string.h>


//Create data structure 'jumper'

typedef struct{
	//Define variable and attributes
	char firstname[30];
	char lastname[30];
	char nationality[50];
	int result;
}Jumper;



//Display all contents of the jumpers array
void printJumpers(Jumper jumpers[], int jumpersLength){
	for(int i = 1; i < jumpersLength; i++){
		printf("FirstName: %s\t LastName: %s\t Nationality: %s\t Result: %d\n",
				jumpers[i].firstname,
				jumpers[i].lastname,
				jumpers[i].nationality,
				jumpers[i].result  
				);
	}
}



//Access File
//Ignore First line
//For every new line append to array jumper
void loadFile(char fileName[10], Jumper jumpers[]){
	//Create temp names for data myCustomers
	char firstname[30];
	char lastname[30];
	char nationality[50];
	int result;
	int counter;

	//Decalre a file pointer
	FILE* input = fopen(fileName, "r+"); //r means read, + means edit.
	//Check if the file opened successfully

	if(input==NULL) perror("Error opening the file... :(]\n");
	else{
		counter = 0;
		//Continue to read till the end of the file
		
		while(!feof(input)){
			char ignore[20];
			fgets(ignore, sizeof(ignore), input);
			fscanf(input, "%s %s %s %d\n", firstname, lastname, nationality, &result); //If variable is number, add & in the beggining of variable for usage.
			if(strcmp(firstname, "") != 0){
			//A record has been found
				strcpy(jumpers[counter].firstname, firstname);
				strcpy(jumpers[counter].lastname, lastname);
				strcpy(jumpers[counter].nationality, nationality);
				jumpers[counter].result = result;
			}
			/*
			printf("FirstName: |%s|\t", jumpers[counter].firstname);
			printf("LastName: |%s|\t", jumpers[counter].lastname);
			printf("Nationality: |%s|\t", jumpers[counter].nationality);
			printf("Results: |%s|\n", jumpers[counter].result);
			*/
			counter++;
		}//while()

		fclose(input);
		printf("File loaded successfully!\n");
	}
}//loadFile


void searchJumpers(int distance, Jumper jumpers[], int jumperSize){
	//Loop through the array of customers
	for(int i = 0; i < jumperSize; i++){
		if(jumpers[i].result >= distance){
			printf("FirstName: %s\t LastName: %s\t Nationality: %s\t Result: %d\n",
				jumpers[i].firstname,
				jumpers[i].lastname,
				jumpers[i].nationality,
				jumpers[i].result  
				);
		} 
	}
}//Search Student

int main(int argc, char* argv[]){
	Jumper jumpers[50];	
	int jumpersLength = sizeof(jumpers)/sizeof(jumpers[0]);
	char filename[30] = "jump.txt";
	int distance = 0;


	//Access file
	loadFile(filename, jumpers);
	//Pass every jumper to array jumpers
	//Display jumpers array
	//printJumpers(jumpers, jumpersLength);
	
	//Get name from user input
	//Pass it to searchStudent function and return number or -1.
	printf("Which result are you looking for\n");
	scanf("%d", &distance);
	searchJumpers(distance, jumpers, jumpersLength);
	
}//
