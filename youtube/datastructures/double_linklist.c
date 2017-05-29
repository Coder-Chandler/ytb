//Double Linked LIst-Implemenration
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
	
};
struct Node *head;
struct Node *GetNewNode(int x)
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));//get the heap through malloc
	newNode -> data = x;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	return newNode;
}
void InsertAtHead(int x)
{
	struct Node *newNode = GetNewNode(x);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	head -> prev = newNode;
	newNode -> next = head;
	head = newNode;
}
void delete_begin()
{
	while (head != NULL)
	{
		struct Node *temp = head;
		if (temp -> next == NULL)
		{
			head = NULL;
			free(temp);
			return;
		}
		temp -> next -> prev = NULL;
		head = temp -> next;
		free(temp);
	}
}
void Print()
{
	struct Node *temp = head;
	if (head == NULL) return;//empty list,exit
	printf ("Forword : ");
	while (temp != NULL) 
	{
		printf (" %d", temp -> data);
		temp = temp -> next;
	}
	printf ("\n");
}
void ReversePrint()
{
	struct Node *temp1 = head;
	if  (head == NULL) return;//empty list,exit
	//going to last node
	while (temp1 -> next != NULL)
	{
		temp1 = temp1 -> next;
	}
	//travelling backword using prev pointer
	printf ("Reverse : ");
	while (temp1 != NULL)
	{
		printf (" %d", temp1 -> data);
		temp1 = temp1 -> prev;
	}
	printf ("\n");
}
int main()
{
	head = NULL;//empty list
	InsertAtHead(2);Print();ReversePrint();
	InsertAtHead(4);Print();ReversePrint();
	InsertAtHead(7);Print();ReversePrint();
	InsertAtHead(8);Print();ReversePrint();
	InsertAtHead(3);Print();ReversePrint();
	delete_begin();
	InsertAtHead(9);Print();ReversePrint();
	InsertAtHead(6);Print();ReversePrint();
	InsertAtHead(5);Print();ReversePrint();
	printf ("\n");
}
	

