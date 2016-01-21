#include<stdio.h>
//This program demonstrates the scope of variables

int main(int argc, char * argv[]){
	//main scope
	int i = 2;
	{
		int i = 3;
		//second scope
		printf("Variable i in second scope is %d\n", i);
	}
	printf("Variable i in second scope is  %d\n", i);

	return 0;
}//main

