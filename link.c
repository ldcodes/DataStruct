#include <stdio.h>
#include <stdlib.h>


typedef struct N *Node;

struct N{
 int data;
 Node next;
};

Node head ;



Node findbyindex(Node head, int i){
   int j ;
   Node  p= head;
   for(j=0 ; p != NULL; j++){
     if(j != i)
       p = p->next;
     else
       return p;
   }
   return NULL;
}
// find
  Node findbyValue(Node head, int v){
  Node p = head;
  while(p != NULL && p->data != v){
    p = p->next;
  }
  return p;
}

void insert(Node head, Node n){
  Node p= head,t;
  while(p->next != NULL)
     p = p->next;
  t = (Node)malloc(sizeof(Node));
  t ->data = n->data;
  t->next = NULL;
  p->next= t;
}

int  insert1(Node  head ,Node n ,int index){
  int j = 0;
  Node p= head ,t;
  if(index == 0 ){
    p = (Node)malloc(sizeof(Node));// not struct Node
    p->data= n->data;
    p->next = head;
    head = p;
    return 0;
  }

  for(j=0 ;p != NULL ;j++,p=p->next){
    if(j+1 == index){
        t = (Node)malloc(sizeof(Node));
        t->data = n->data;
        t->next = p->next;
        p->next = t;
        return 0;
    }
  }
  return -1;
}
void p(Node h){
  Node p = h;
  while(p != NULL){
    printf("%d \t",p->data);
    p = p->next;
  }
  printf("\n");
}

void det(Node n,int v){
   Node p = n;
   if(p->data == v){
       *n = *(n->next);
   }

  else {
   while(p->next != NULL && p->next->data != v)
     p = p->next;
     if(p->next != NULL && p->next->data == v){
        p->next = p->next->next;
     }
   }
}
int main(){
  Node head = (Node)malloc(sizeof(Node)) , t= (Node)malloc(sizeof(Node));
  head->data = 0;
  head->next = NULL;
  t->data = -1;
  t->next = NULL;
  printf("insert 1 result :%d\n", insert1(head,t,2));
  p(head);
  printf("insert 2 result :%d\n", insert1(head,t,1));
  p(head);
    t->data =2;
  insert(head,t);
  p(head);
  t->data =3;
  printf("insert 2 result :%d\n", insert1(head,t,1));
  p(head);
  printf("insert 2 result :%d\n", insert1(head,t,10));
  p(head);
    t->data =10;
  printf("insert 2 result :%d\n", insert1(head,t,2));
  p(head);
  //0       3       10      -1      2
 /* printf(" %d \t%d \t %d\n", findbyindex(head,0)->data,findbyindex(head,4)->data,findbyindex(head,6));
    printf(" %d \t%d \t %d\n", findbyValue(head,0)->data,findbyValue(head,-1)->data,findbyValue(head,101));//,findbyValue
*/

    det(head,0);
    p(head);
    det(head,3);
    p(head);
    det(head,2);
    p(head);
     return 0;
}
