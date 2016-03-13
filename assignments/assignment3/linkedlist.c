#include <stdio.h>
#include <stdlib.h> 
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// This program builds a linked list of integers 
// entered by the user
// if the user entered zero, the program stops to read integers
// and prints out the integers from the list

// define the data structure of a node
typedef struct node{
	char name[20];
  int n;
	struct node *next; 
}Node, *NodePtr;

// define a struct for the linked list 
typedef struct{
	NodePtr first,np,last;
}LinkedList; 

// Make a node
NodePtr makeNode(char userName[20], int n){
	// allocate memory to the node 
	NodePtr np= (NodePtr) malloc(sizeof(Node));
	// set the node members to the values
  strcpy(np->name, userName);
	np->n=n;
	np->next=NULL; //because it will be added to the last node
	return np; 
}

int countLinked(NodePtr movingPtr){
  int count;

  while(movingPtr != NULL){
    count ++;
    movingPtr =movingPtr -> next;
  }
  return count;
}

LinkedList deleteFirstNode(LinkedList myList) {
  NodePtr tempNode = myList.first;
  myList.first = myList.first->next;
  free(tempNode);
  return myList;
}

// we want to write a function that prints it
void printList(NodePtr movingPtr){
	while(movingPtr!=NULL){ // as long as there is a node
    double taxes;
    taxes = movingPtr -> n * 0.13;
    printf("%s \t", movingPtr->name);
		printf("%d \t", movingPtr->n); 
    printf("%.2f\n", taxes);
		movingPtr=movingPtr->next; // go on to the next node
	}
}

// TODO: Convert to dynamic char later
int isEnd(char name[20]){
  //Compare input to exit
  //if true, return true
  //else, return false
  int input;
  if(strcmp(name, "exit") == 0){
    input = 1;
  } else {
    input = 0;
  }
  return input;
}


int main(){
	int n; 
  char name[20];
  int input;
	// create a linked list variable 
	LinkedList myList;
	myList.first= NULL;    // myList is empty

  // get the first name 
  printf("Enter a name: ");
  scanf("%s", name);
  input = isEnd(name);

	// get the first integer from the user 
	printf("Enter a number: ");
	scanf("%d", &n); 
	
	while(input != 1){
    //create a new node to keep n
		myList.np=makeNode(name, n);

    if(myList.first==NULL) { 
      myList.first=myList.np; 
    } else  {
      // make the current last node points to the new node
      myList.last->next=myList.np;
    }
			
		//update the last pointer
		myList.last=myList.np;
    // get another name
    printf("Enter a name: ");
    scanf("%s", name);
    input = isEnd(name);
    
    if (input == 1){
      break;
    }

    // get another number 
    printf("Enter a number: ");
		scanf("%d",&n);
    
  }
  printList(myList.first);

  myList = deleteFirstNode(myList);

  printList(myList.first);


  
  //printList(myList.first);



}
