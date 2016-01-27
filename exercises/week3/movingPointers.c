#include <stdio.h>

main(){
	char *charPointer = "Sheridan";
	for(int i=0; i<8; i++){
		printf(" %c: %u\n", *charPointer, charPointer); //%u means unsigned integer
		charPointer++;
	}
}
