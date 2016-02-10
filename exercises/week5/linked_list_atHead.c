#include<stdio.h>
#include<stdlib.h>

//The program builds a linked list of integers entered by the use
//If the use enter zero the program stops to read new numbers
//Each new integer will be added at the head of the list
typedef struct node{
	//Define the node members
	int num; //This represents data
	struct node* next; //Next pointer 
}Node, *NodePtr;

//Write a function to print the list
void printList(NodePtr np){
	while(np!=NULL){  //As long as there is a node, loop
		printf("\n %d \n", np->num);
		np = np -> next; // Move to next node
	}
}

//Make a new node
NodePtr makeNode(int n){

	//Allocate memory
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> num = n;
	np -> next = NULL;
	return np;
}//makeNode


//Length function
int length(NodePtr top){
	int n = 0; //Initialize the counter to 0
	NodePtr curr = top; //Starts from the first node
	
	while(curr!=NULL){
		n++;
		curr = curr -> next;
	}
	return n;
}// length

int main(){
	int n;
	//Define a linked list: requires 3 pointers
	// 1.) First: points to the first node(Don't change this)
	// 2.) Last: (optional)
	// 3.) Np: points to the new node and be used for movement 
	
	NodePtr first, np, last;
	
	//Set the first pointer to NULL to indicate it is empty
	first = NULL;

	//Read the first number
	printf("Please enter a list of numbers. End input by Zero");
	scanf("%d", &n);

	while(n!=0){
		//Create the node for this data
		np = makeNode(n);
		if(first == NULL){
			first = np; //Make first point to the new node
		}else{
			//Make the new node to point to the current first node
			np -> next = first;
			first = np;
		}
		//Read another
		scanf("%d", &n);		
	}
	printf("The linked list contains: %d integers", length(first));
	
	//Print all items
	printList(first);
}


//
