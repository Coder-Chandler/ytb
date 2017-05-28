//Stack Link List implementation
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *link;
};
struct Node *top = NULL;//Global
void Push(int x)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	/*TO avoid the stack overflow
	,we can't just push data in the stack, 
	Dynamic memory allocation will be the best !
	stack -->> heap*/
	temp -> data = x;//put the data in the heap !
	temp -> link = top;
	/*not equal NULL,
	because every time you push a data at the top of the stack,
	the new data link will points to the top data,
	then the top data will change to the new data you pushed
	*/
	top = temp;
	/*every time when a new data has been pushed at the top 
	of the stack,the top data pointer will change his pointing*/
	printf ("Push-");
}
void Pop()
{
	struct Node *temp1;
	//Use temp1 to remember the address of the top data
	if (top == NULL) return;//empty stack
	temp1 = top;//remember the address of the top data
	top = top -> link;//Change the top data pointer 
	free(temp1);
	/*Free the memory which stored the data that we want to remove*/
	printf ("Pop-");
}
void Top()
{
	printf ("%d",top -> data);
}
void Print()
{
	struct Node *temp2 = top;
	if (top == NULL) return;
	printf ("stack :");
	printf ("top->");
	while (temp2 != NULL)
	{
		printf (" %d->", temp2 -> data);
		temp2 = temp2 -> link;
	}
	printf ("NULL");
	printf ("\n");
}
void Reverse()
{
	struct Node *current, *next, *prev;
	current = top;
	prev = NULL;
	while (current != NULL)
	{
		next = current -> link;
		current -> link = prev;
		prev = current;
		current = next;
	}
	top = prev;
}
void ReversePrint()
{
	struct Node *temp3 = top;
	if (top == NULL) return;
	printf ("stackReverse : ");
	while ( temp3 !=NULL)
	{
	    printf (" %d", temp3 -> data);
	    temp3 = temp3 -> link;
	}
	printf ("\n");
}
int main()
{
	Push(2); Print();
	Push(5); Print();
	Push(10);Print();
	Pop(); Print();
	Push(12); Print();
	printf("Reverse-");
	Reverse(); Print();
	Push(11); Print();
	Push(17); Print();
	Push(19); Print();
	Pop(); Print();
	printf("Reverse-");
	Reverse(); Print();
	printf ("\n");	
}

