#include <stdio.h>
#include <stdlib.h>
#define N 12 //The size of the pointers array
#define Empty 0

//Define the node structure
typedef struct node {
  int num,
  struct *next;
}Node, *NodePtr;

//Creating a new element
NodePtr newNode(int n){
  //allocate memory
  NodePtr p = (NodePtr) malloc(sizeof(Node));

  //Insert the data into the Node
  p -> num = n;
  p -> next = NULL;
  return p;
}

//Search function
int searchKey(int key, NodePtr hash[], int n) {
  //Apply the function to get the location of the list
  int k = key % n + 1;
  NodePtr current = hash[k];
  NodePtr previous = NULL;
}
//returns 1 if the numbers is found
//otherwise return 0


int main() {
  int j, key; //temp variables for processing

  FILE *in = fopen("numbers.txt", "r");

  if(in == NULL){
    printf("File not found");
    exit(1);
  }

  //At this point, we are sure that the file has been open
  //Define array of pointer to model the hash table
  
  NodePtr hash[N+1];
  //Initialize the hash table elements to NULL
  for(j=1; j<=N; j++) {
    hash[j] = NULL;

    int uniqueNum; //count the unique numbers
    while(fscanf(in, "%d", &key) == 1) {

      //search for the key in the hash table
      //if key is not found,
      //increment uniqueNum variable
      
    }//while
  }//for
}//main
