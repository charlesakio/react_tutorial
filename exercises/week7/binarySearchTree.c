/*Algorithm goal:
  To find the n number of frequency of every word in the file.

1.) Create an empty binary search tree(BST)
2.) While (!EOF) do:
  a.) get the word
  b.) search for the word into the BST,
      if the word is found, increment frequency count 
      if the word is not found, insert into the BST and set
      it's frequency to 1
3.) Print the BST using the in-order traversing to print it in alphabetical order including the frequencies
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MaxWordSize 20

//Define the NodeData
typedef struct {
  char word[MaxWordSize + 1];
  int frequency;
}NodeData; 

//Define the tree Node
typedef struct treeNode {
  NodeData data;
  struct treeNode * left, *right;
}TreeNode, *TreeNodePtr;

//Define the binary tree
typedef struct {
  TreeNodePtr root;
}BinaryTree;

//Write the function getWord to read a word from the file
int getWord(FILE *in, char str[]) {
  char ch;
  int n=0;

  //Read over non-letters
  while(!isalpha(ch=getc(ch) && ch!=EOF)); //empty while body
  if(ch===EOF) return 0;
  str[n++] = tolower(ch);
  while(isalpha(ch=getc(in)) && ch!=EOF);
    if(n<MaxWordSize) str[n++]=tolower(ch);
  str[n]='\0'; // to indicate the end of the string
  return 1;
}

//Find or insert function
TreeNodePtr findOrInsert(BinaryTree bt, NodeData d) {
  if(bt.root==NULL)  return newTreeNode(d);
  TreeNodePtr curr = bt.root;
  int cmp;
  while((cmp=strcmp(d.word, d.word->data.word))!=0) {
    if(cmp<0) {
      if(curr->left==NULL)
        return curr->left=newTreeNode(d);
      curr=curr->left;
    } else { //Add the new node to the right of the current one
      if(curr->right==NULL)
        return curr->right=newTreeNode(d);
      curr=curr->right;
    }
  }
  return curr;
}


