#include<stdio.h>

//Write a program that prints hello 10 times;

//Pseudocde:
//Loop ten times,and output ten 'hellos'

int main() {
	int i = 0;
	int j = 0;

	for(i = 10; i > 0; i--){
		printf("\n");
		for(j = 0; j < i; j++){
			printf("* ");
		}//j
	}//i
	return 0;
}//main


