#include<stdio.h>
#include<string.h>
#include<math.h>


int main(int argc, char * argv[]){
	
	int i = 0;

	//Define an array: data-type nameOfTheArray[size]
	char lastName[10] = "charles";
	double result;

	for(i = 0; i < 100; i++){
		result += sqrt(i);
	}

	printf("The sum of all square root is: %f\n", result);
	
	return 0;
}//main

