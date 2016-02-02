#include <stdio.h>

int n1 = 3;  //Global variables acces to 
int n2 = 7;  // All functions  underneath this line

int main(){
	int add(void);
	int i;
	int total = 0;

	for (i=0; i<3; i++){
		printf("Total is %d\n", total);
		total = add();
	}

	printf("Total is %d\n", total);
	return 0;

}//main()

int add(void){
	int sum = 0; //If there is no static added. Sum variable will go back to 0 every instance.
	sum = sum + n1 + n2;
	return sum;
}//add
