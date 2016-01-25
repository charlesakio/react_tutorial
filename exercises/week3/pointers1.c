#include <stdio.h>

main() {
	void test (int *ptr); //Tell c compiler that test is a function. Only do this if the function is declared at teh botton.
	int myVar = 50;
	printf("%d\n", myVar);
	test(&myVar);
	printf("%d\n", myVar);

}

void test(int *ptr){
	*ptr = *ptr*2;
	printf("%d\n", *ptr);
}
