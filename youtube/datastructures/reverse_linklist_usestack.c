//Reverse a Linked List use stack
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head;

void Insert(int data)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	temp -> next = NULL;
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		struct Node *temp1 = head;
		while (temp1 -> next != NULL)
		{
			temp1 = temp1 -> next;
		}
		temp1 -> next = temp;
	}
}
void Reverse()
{
	if (head == NULL) return;
	stack<struct Node*>S;
	struct Node *temp3 = head;
	while (temp3 != NULL)
	{
		S.push(temp3);
		temp3 = temp3 -> next;
	}
	temp3 = S.top(); 
	head = temp3;
	S.pop();
	while (!S.empty())
	{
		temp3 -> next = S.top();
		S.pop();
		temp3 = temp3 -> next;
	}
	temp3 -> next =NULL;
}
void print()
{
	struct Node *temp2 = head;
	if (head == NULL) return;
	printf ("Linklist : ");
	while (temp2 != NULL)
	{
		printf (" %d", temp2 -> data);
		temp2 = temp2 -> next;
	}
	printf ("\n");
}
int main()
{
	head = NULL;
	Insert(2);
	Insert(3);
	Insert(7);
	Insert(5);
	Insert(9);
	print();
	Reverse();
	printf ("Reverse-");
	print();
	printf ("\n");
}

