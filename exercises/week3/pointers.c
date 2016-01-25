#include <stdio.h>

main() {
	void test (int var);
	int myVar = 50;
	printf("%d\n", myVar);
	test(myVar);
	printf("%d\n", myVar);

}

void test(int var){
	var = var*2;
	printf("%d\n", var);
}
