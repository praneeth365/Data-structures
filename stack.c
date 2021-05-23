#include<stdio.h>
#include<stdlib.h>

typedef struct StackNode StackNode ;
typedef StackNode*  Stack ;


struct StackNode{
	int element ;
	Stack Next ;
} ;

Stack Push(Stack S,int x)
{
   Stack P=(Stack)malloc(sizeof(StackNode)) ;
   P->element=x ;
   P->Next=NULL ;

   if(S==NULL)
   	S=P ;
   else
   {
   	  P->Next=S ;
   	  S=P ;
   }
   return S ;
}

int Top(Stack S)
{
   if(S==NULL)
   	return -1 ;
   else
   	return S->element ;
}

Stack Pop(Stack S)
{
	if(S==NULL)
		return NULL ;
	
   Stack P=S ;
   S=S->Next ;
   free(P) ;
   return S ;
}


int main(void)
{
   Stack S=NULL ;
   S=Push(S,5) ;
   S=Push(S,6) ;
   S=Push(S,10) ;
   S=Pop(S) ;
   printf("%d",Top(S)) ;
}