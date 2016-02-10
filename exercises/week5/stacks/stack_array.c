#include <stdio.h>
#include <stdlib.h>
#define MaxStack 10 //Define a constant in c

typedef struct{
	int top;
	int ST[MaxStack];

}StackType, *Stack;

//Define all the stack functions


Stack initStack(){
	//Allocate memory
	Stack sp = (Stack) malloc(sizeof(StackType));
	
	//Setting thr top to -1 (means it is empty)
	sp -> top = -1;  //sp is the pointer and pointed to top and is allocated to -1(empty)
	return sp;
} //Create a stack

int empty(Stack s){ //Check if the stack is empty
	return(s -> top == -1);
}

void push(Stack s, int n){
	if(s -> top == MaxStack -1){
		printf("\n error: stack overflow, tooooooooooooo muuuuuuuuuuuccccccchhhhh memory");
		printf("\n clean up your memory please!!! :)");
		exit(1); //End the program
	}
	//Increase s to move to next container
	++(s -> top);
	s -> ST[s -> top] = n;
}

int pop(Stack s){
	if(emtpy(s)){
		printf("\n Error: Stack is empty");
		return(-99999999);
	}
	//At this point, it is confirmed that the stack is empty
	int hold = s -> top -> num; //Hold the value of the current top
	NodePtr tempPtr = s -> top;
	s -> top = s -> top -> next;
	free(tempPtr);	
	return hold;
}

int main(){
	int n;
	//Create an empty stack
	Stack s = initStack();

	printf("Enter a list of integers. Enter 0 to end");
	
	//Read the first integer
	scanf("%d", &n);

	//Continue reading numbers and pushing them into the stack
	//Till the user enters 0
	
	while(n!=0){
		push(s, n);
		scanf("%d", &n);
	}
	
	//Print the values from the stack
	while(!empty(s)){
		printf("%d\n", pop(s));
	}
}



