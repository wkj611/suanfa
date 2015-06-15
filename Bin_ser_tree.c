#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;	
} BSTNode;
BSTNode * Creatbstnode(int);
void Insertbst(BSTNode *root,int key);
void BstInorder(BSTNode *);


int main(){
	  int i,in;
	  printf("please enter the root's key:\n");
	  scanf("%d",&in);
	  BSTNode *root = Creatbstnode(in);//creat root node
	  for(i = 0;i<6;i++){
	  	  printf("please enter the node's key:\n");
	  	  scanf("%d",&in);
	      Insertbst(root,in);
	  }
	  printf("the in order result is :\n");
	  BstInorder(root);
	  printf("\n");
    return 0;	
}
BSTNode * Creatbstnode(const int key){
    BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));//malloc failed
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void Insertbst(BSTNode *root,int key){
    BSTNode *node = Creatbstnode(key);
    if(root == NULL)
    {    
    	root = node;
    }//root node is NULL
    if(root->key>key)
    {
        Insertbst(root->left,key);	  
    }
    else if(root->key<key)
    {
    	  Insertbst(root->right,key);
    }
}
void BstInorder(BSTNode * BST){
	  
    if(BST){
        BstInorder(BST->left);
        printf("%4d",BST->key);
        BstInorder(BST->right);
    }    		
}
