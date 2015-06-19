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
ListType * Insertheader(ListType *header,Keytype key);
void PrintList(ListType *header);
int ListLength(ListType *header);
Keytype *find(ListType *header,Keytype key);
void Delete(ListType *header,Keytype key);
int main(){
	  ListType *header;
	  int i;
	  Keytype in,keyfind,keydelete;
	  header = Initlist();
	  for(i=0;i<6;i++){
	  	  printf("enter the key\n");
	  	  scanf("%d",&in);
	      Insertheader(header,in);
	  }
	  printf("please enter the key you want to find\n");
	  scanf("%d",&keyfind);
	  if(find(header,keyfind))
	      printf("the key's addr is : %p and the key is:%d\n",find(header,keyfind),*find(header,keyfind));
	  else
	  	  printf("the key is not in the list\n");
	  PrintList(header);
	  printf("the list's length is :%d\n",ListLength(header));
	  printf("the key you want to delete:\n");
	  scanf("%d",&keydelete);
	  Delete(header,keydelete);
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
ListType * Insertheader(ListType *header,Keytype key){
    ListType * p;
    if(header==NULL){
        header = Initlist();
    }
    else{
    	  p = Creatnode(key);
        p->next = header->next;
        header->next = p;
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
Keytype *find(ListType *header,Keytype key){
    ListType * p = header->next;
    Keytype *pkey;
    while(p){
        if(p->key == key){
            pkey = &p->key;
            break;
        }
        else 
        	  p = p->next;
    }
    if(!p) 
    	  return NULL;
    else
        return pkey;
}
int ListLength(ListType * header){
    ListType *p = header;
    int count = 1;
    if(p==NULL)
        return 0;
    else
    	  while((p = p->next))
    	      count++;
    return count;
}
void Delete(ListType *header,Keytype key){
    ListType * p,*q;
    p = header;
    q = p->next;
    while(q){
        if(q->key == key){
        	  p->next = q->next;
        	  free(q);
        	  break;
        }
        else{
        	  p = p->next;
        	  q = q->next;
        }  
    }
}