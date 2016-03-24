//**Write a C program that read 100 integers from the attached file(integers.txt)into an array and 
//copy the integers from the array into a Binary Search Tree (BST). 
//The program prints out the following:
//  - The number of comparisons made to search for a given integer in the BST
//  - The number of comparisons made to search for the same integer in the array
#include <stdio.h>
#include <stdlib.h>

//Create global array of integers
//Must figure out how 2 dynamically create an array.
int array[200];

void loadFile(){

  FILE * filePointer;
  char c;
  
  //Find the file that will be accessed and passed into variable filePointer
  filePointer = fopen("integers.txt", "r");
  if(filePointer == NULL)  {
    printf("File does not exist");
  } else {
    do {
      int count = 0;

      //Sequentially read every character in a file
      c = getc(filePointer);
      //Print the char to the screen
      putchar(c);
      if(isdigit(c)) {
        //printf("is a digit\n");
        //Change char to int and pass it to the numStorage
        array[count] = c - '0'; 
        count++; 
        //Pass into an array
      } else {
        //printf("is not a digit\n");
      }
    }while (c!=EOF);
    fclose(filePointer);

    for(int i=0; i>sizeof(array); i++) {
      printf("%d\n", array[i]);
    }
  }
 /* 
  for(int i=0; i<sizeof(numStorage); i++){
    printf("%d\n", numStorage[i]);
  }
  */
}//loadFile



int main() {
  //Create array varabile and use it in the 
  loadFile();

  
}//main()
