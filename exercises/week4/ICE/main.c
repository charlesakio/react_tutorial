#include <stdio.h>
#include <stdlib.h>

int length;
int width;
int area;
int perimeter;

int findPerimeter(void);

int main() {

	//Ask for width
	printf("Enter width");
	scanf("%d", &width);

	//Ask for height
	printf("Enter length");
	scanf("%d", &length);

	area = findPerimeter();
	
	printf("%d", area);
}//main
