//**Write a C program that read 100 integers from the attached file(integers.txt)into an array and 
//copy the integers from the array into a Binary Search Tree (BST). 
//The program prints out the following:
//  - The number of comparisons made to search for a given integer in the BST
//  - The number of comparisons made to search for the same integer in the array
#include <stdio.h>
#include <stdlib.h>
# include <ctype.h>

//Define the Node data
typedef struct {
  int number;
  int frequency;
}NodeData;

//Define the tree Node
typedef struct treeNode{
  NodeData data;
  struct treeNode *left, *right;
}TreeNode, *TreeNodePtr;

//Define the binary tree
typedef struct {
  TreeNodePtr root;
}BinaryTree;

//Create a Nodedata
NodeData newNodeData(int num[], int n){
  NodeData temp;
  temp.number = num;
  temp.frequency = n;
  return temp;
}

//Allocate a memory for a node data
//Then, create a tree node

TreeNodePtr newTreeNode(NodeData d){
  TreeNodePtr p = (TreeNodePtr) malloc(sizeof(TreeNode));
  p -> data = d;
  p -> left = p -> right = NULL;
  return p;
}

int getNumbers(FILE *file, int numArray[]){
  
  int counter = 0;// Initialize counter++ 
  int number = 0; //Initialize number
  
  //Read over non-letters 
  while(!feof(file)) {
      fscanf(file, "%d", &number);
      numArray[counter] = number;
      counter++;
  }//while 
  fclose(file);
  return 0;
}//getword()

TreeNodePtr findOrInsert(BinaryTree bt, NodeData nd) {
  if(bt.root == NULL) {
    return newTreeNode(nd);
  }
  TreeNodePtr curr = bt.root;
  int cmp;
  while((cmp=strcmp))

}

int main() {
  int numArray[100];

  //open the file
  FILE *file = fopen("integers.txt", "r");
  
  if (file == NULL) {
    printf("cannot open the file");
    exit(1);
  }
  
  int tempNum = getNumbers(file, numArray);
  
  if (tempNum == 0) {
    BinaryTree binarySearchTree;
    binarySearchTree.root = NULL;

    for (int i=0; i < (sizeof(numArray)/sizeof(numArray[0])); i++){
      if(binarySearchTree.root == NULL) {
        binarySearchTree.root = newTreeNode(newNodeData(numArray, 1));
      } else {
        TreeNodePtr node = findOrInsert(binarySearchTree, newNodeData(numArray, 0));
        node -> data.frequency++;
      }
    }
  }
}//main()
