/*link list
 by wkj
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef int Keytype;
typedef struct listnode{
    struct listnode * next;
    Keytype key; 	
} ListType;
ListType * Initlist();
ListType * Inserttail(ListType *header,Keytype key);
void PrintList(ListType *header);
int main(){
	  ListType *header;
	  int i;
	  Keytype in;
	  header = Initlist();
	  for(i=0;i<6;i++){
	  	  printf("enter the key\n");
	  	  scanf("%d",&in);
	      Inserttail(header,in);
	  }
	  PrintList(header);
	  
}
ListType * Initlist(){
    ListType * header = (ListType *)malloc(sizeof(ListType));
    header->next = NULL;
    return header;	
}
ListType * Creatnode(Keytype key){
    ListType * node = (ListType *)malloc(sizeof(ListType));
    node->key = key;
    node->next = NULL;
    return node;	
}
ListType * Inserttail(ListType *header,Keytype key){
	  ListType *p = header;
	  if(header==NULL){
	      header = Initlist();
	  }
	  else{
	      while(p->next){
	          p = p->next;
	      }
	      p->next = Creatnode(key);
	  }
	  return header;
}
void PrintList(ListType *header){
    ListType *p = header->next;
    printf("the list's keys are: \n");
    while(p){
    	  printf("%4d",p->key);
        p = p->next;
    }
    printf("\n");
}