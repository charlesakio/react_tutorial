#include<stdio.h>
#include<stdlib.h>
//Write a factoial program, that is a takes an input 
// Then displays the factorial out put

int factorial(int n) {
  if(n == 0) {
    return 1;
  } else {
    printf("%d * %d = %d\n", n, n-1, n*(n-1));
    return n * factorial(n - 1);
  }
}

int main() {
  int num = 4;
  int fact = factorial(num);
  printf("Factorial: %d", fact);

}//main



