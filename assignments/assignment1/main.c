#include<stdio.h>
#include<string.h>


//Create data structure 'jumper'

typedef struct{
	//Define variable and attributes
	char firstname[30];
	char lastname[30];
	char nationality[50];
	float result;
}Jumper;



//Display all contents of the jumpers array
void printJumpers(Jumper jumpers[], int jumpersLength){
	for(int i = 1; i < jumpersLength; i++){
		printf("FirstName: %s\t LastName: %s\t Nationality: %s\t Result: %.02f\n",
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
	char nationality[30];
	float result = 0;
	int counter;
	char tmp[30];
	//Decalre a file pointer
	FILE* input = fopen(fileName, "r+"); //r means read, + means edit.
	//Check if the file opened successfully

	if(input==NULL) perror("Error opening the file... :(]\n");
	else{
		counter = 0;
		//Skips throught the first line
		fscanf(input,"%s %s %s %s",tmp, tmp, tmp, tmp);
		while(!feof(input)){
		fscanf(input, "%s %s %s %f\n", firstname, lastname, nationality, &result); //If variable is number, add & in the beggining of variable for usage.
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
			printf("Nationality: |%s|", jumpers[counter].nationality);
			printf("Results: |%.02f|\n", jumpers[counter].result);
			*/
			counter++;
		}//while()

		fclose(input);
		printf("File loaded successfully!\n");
	}
}//loadFile


void searchJumpers(float distance, Jumper jumpers[], int jumperSize){
	//Loop through the array of customers
	for(int i = 0; i < jumperSize; i++){
		if(jumpers[i].result > distance){
			printf("FirstName: %s\t LastName: %s\t Nationality: %s\t Result: %.02f\n",
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
	float distance = 0;


	//Access file
	loadFile(filename, jumpers);
	//Pass every jumper to array jumpers
	//Display jumpers array
	//printJumpers(jumpers, jumpersLength);
	
	//Get name from user input
	//Pass it to searchStudent function and return number or -1.
	printf("\nWhich result are you looking for\n");
	scanf("%f", &distance);
	searchJumpers(distance, jumpers, jumpersLength);
	
}//
