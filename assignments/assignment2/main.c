#include<stdio.h>
#include<string.h>
#include<math.h>


//Create data structure 'jumper'

typedef struct{
	//Define variable and attributes
	char firstname[30];
	char lastname[30];
	char nationality[50];
	float result;
}Jumper;


//Formula for surface area of a cube
// SA = 6A^2
int surfaceArea(int number){
	return 6 * pow(number, 2);
}

//Formula for volume of a cube
// V = A^3
int volume(int surfaceArea){
	return pow(surfaceArea, 3);
}



int main(int argc, char* argv[]){
	///Given side length of a cube L, the volume of the cube is L3and the surface area of the cube is 6L2.
	// Write a C program which takes the side length of a cube and 
	// prints the volume and the surface area of the cube
	
	//SA Test 1, Supply 2 = SA => 24;
	int test1 = surfaceArea(2);
	printf("%d", test1);
	//**Passed, Answer is 24
	

	//V Test1, Supply test1 result = V => 8;
	//*int vTest1 = volume(test1);
	//*printf("%d", vTest1);
	//**Failed, Answer = 2413824
	
	//V Test2, Supply Hardcoded test1 result 24 = V => 8;
	//int vTest2 = volume(24);
	//printf("%d", vTest2);
	//Same answer as vTest1;
	

	//V Test3, Change "%d" to "\n%d" to create new line and supply 2 instead V => 8;
	int vTest3 = volume(2);
	printf("\n%d", vTest3);
	//Test passed, Answer is 8
}//
