#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct Node{
    int key;
    struct Node *left;
    struct Node *right;	
} BSTNode;
BSTNode * Creatbstnode(int);
void Insertbst1(BSTNode **root,int key);
BSTNode * Insertbst2(BSTNode *root,int key);
void BstInorder(BSTNode *);


int main(){
	  int i,in;
	  printf("please enter the root's key:\n");
	  scanf("%d",&in);
	  BSTNode *root = Creatbstnode(in);//creat root node
	  for(i = 0;i<6;i++){
	  	  printf("please enter the node's key:\n");
	  	  scanf("%d",&in);
	     // Insertbst1(&root,in);
	      Insertbst2(root,in);
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
void Insertbst1(BSTNode **root,int key){
    BSTNode *node = Creatbstnode(key);
    if(*root == NULL)
    {    
    	*root = node;
    }//root node is NULL
    else if(((*root)->key)>key)
        Insertbst1(&((*root)->left),key);	      
    //else if(((*root)->key)<key)
    else
    	  Insertbst1(&((*root)->right),key);
    
}
BSTNode * Insertbst2(BSTNode *root,int key){
    BSTNode *node = Creatbstnode(key);
    if(root == NULL)
    {    
    	root = node;
    }//root node is NULL
   else if(root->key>key)
    {
        root->left = Insertbst2(root->left,key);	  
    }
    else
    {
    	  root->right = Insertbst2(root->right,key);
    }
    return root;
}
void BstInorder(BSTNode * BST){
	  
    if(BST){
        BstInorder(BST->left);
        printf("%4d",BST->key);
        BstInorder(BST->right);
    }    		
}
