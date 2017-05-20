//Stack-Array based implementation
#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void Push(int x)
{
	if (top == MAX_SIZE-1)
	{
		printf ("ERROR : stack overflow\n");
		return;
	}
	top++;
	A[top] = x;
}
void Pop()
{
	if (top == -1)
	{
		printf ("ERROR : no element to pop\n");
		return;
	}
	top--;
}
int Top()
{
	return A[top];
}
void Print()
{
	int i;
	printf ("stack ; ");
	for (i = 0; i<=top; i++)
	{
		printf (" %d",A[i]);
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
	printf ("\n");	
}
