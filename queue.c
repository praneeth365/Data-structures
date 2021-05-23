#include<stdio.h>
#include<stdlib.h>


typedef struct QueueNode QueueNode ;
typedef QueueNode* Queue ;

struct QueueNode{
	int element ;
	Queue Next ;
} ;

Queue Push_Q(Queue Q,int x)
{
   Queue P=(Queue)malloc(sizeof(QueueNode)) ;
   P->element=x ;
   P->Next=NULL ;

   if(Q==NULL)
   	Q=P ;
   else
   {
   	  Queue Q1=Q ;

   	  while(Q1->Next!=NULL)
   	  	Q1=Q1->Next ;

   	   Q1->Next=P ;
   }
   return Q ;
}

Queue Pop_Q(Queue Q)
{
   if(Q==NULL)
   	return NULL ;

   Queue P ;
   P=Q ;
   Q=Q->Next ;
   free(P) ;
   return Q ;

}

int Top_Q(Queue Q)
{
   if(Q==NULL)
   	return -1 ;
   else
   	return Q->element ;
}

int main(void)
{
	 Queue Q ;
	 Q=Push_Q(Q,3) ;
	 Q=Push_Q(Q,5) ;
	 Q=Push_Q(Q,10) ;
	 Q=Pop_Q(Q) ;
	 printf("%d",Top_Q(Q)) ;
}