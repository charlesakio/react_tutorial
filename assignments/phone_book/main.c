#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxWordSize 20

//Define a structure for the data
typedef struct { 
  char word[MaxWordSize + 1];
  //@@
  //Hide for now, until I figure out how Binary search works
  //char firstName[MaxWordSize+1];
  //char lastName[MaxWordSize+1];
  //int phoneNumber;
  //@@
}NodeData;

//Define treenode 
typedef struct Node{
  NodeData data;
  struct Node *leftChild, *rightChild;
}Node, *NodePtr;

//Define the Binary Tree
typedef struct {
  NodePtr root;
}BinaryTree;

main () {
    NodePtr buildTree(FILE *);
    void preOrder(NodePtr);

    //**
    //Open the file
    //**
    FILE *file = fopen("btree.txt", "r");
    if(file != NULL) {
      
      //**
      //Declare the binary tree
      //**
      BinaryTree node;

      //Build the tree
      node.root = buildTree(file);

      printf("\n The pre-order traversal is:");
      preOrder(node.root);
   
    } else {
      printf("File error");
    }
}// main

NodePtr buildTree(FILE *in) {
  char str[MaxWordSize + 1];

  fscanf(in, "%s", str);
  printf(" str %s", str);
  
  //**
  //Returns null if character is equal to @
  if(strcmp(str, "@") == 0) {
    return NULL;
  }
  NodePtr pointer = (NodePtr) malloc(sizeof(Node));

  strcpy(pointer -> data.word, str);
  printf("Root %s \n", pointer -> data.word);

  pointer -> leftChild = buildTree(in);
  printf("Left Children %s \n", pointer -> leftChild -> data.word);

  pointer -> rightChild = buildTree(in);
  printf("Right Children %s \n", pointer -> rightChild -> data.word);

  return pointer;
}//buildTree

void visit(NodePtr node) {
  printf("%s", node -> data.word);
}//visit

void preOrder(NodePtr node) {
  if(node != NULL) {
    visit(node);
    preOrder(node -> leftChild);
    preOrder(node -> rightChild);
  }
}//preOrder
