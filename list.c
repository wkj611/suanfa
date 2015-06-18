/*link list
 by wkj
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
typedef int Keytype;
typedef struct listnode{
    listnode * next;
    Keytype key; 	
} ListType;
ListType * Initlist();
ListType * Insert1(ListType *header,Keytype key);
int main(){
	  ListType *header;
	  header = Initlist();
	  
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
    return header;	
}
ListType * Insert1(ListType *header,Keytype key){
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