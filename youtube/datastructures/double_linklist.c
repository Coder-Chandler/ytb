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
struct Node *delete_givendata(int data)
{
	struct Node *current = head;
	struct Node *temp = NULL;
	struct Node *temp1 = NULL;
	if (head == NULL) return NULL;
	while (current -> data != data)
	{
		current = current -> next;
	}
	if (current == head && current -> next != NULL)
	{
		head = current -> next;
		current -> next -> prev = NULL;
		free(current);
		return head;
	}
	else if (current -> prev != NULL && current -> next == NULL)
	{
		current -> prev -> next = NULL;
		free(current);
		return head;
	}
	else if (head -> next == NULL)
	{
		head = NULL;
		free(current);
		return head;
	}
	temp = current -> prev;
	temp1 = current -> next;
	temp -> next = temp1;
	temp1 -> prev =  temp;
	free(current);
	return head;
}
void Print()
{
	struct Node *temp = head;
	if (head == NULL) 
	{
		printf ("Forword : No data, Empty list !\n");
		return;//empty list,exit
	}
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
	if  (head == NULL) 
	{
		printf ("Reverse : No data, Empty list !\n");
		return;//empty list,exit
	}
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
	InsertAtHead(10);Print();ReversePrint();
	printf ("delete data from head to tail\n");
	delete_begin();
	InsertAtHead(9);Print();ReversePrint();
	InsertAtHead(6);Print();ReversePrint();
	InsertAtHead(5);Print();ReversePrint();
	InsertAtHead(12);Print();ReversePrint();
	InsertAtHead(33);Print();ReversePrint();
	InsertAtHead(10);Print();ReversePrint();
	printf ("delete given data\n");
	head = delete_givendata(9);Print();ReversePrint();
	head = delete_givendata(12);Print();ReversePrint();
	head = delete_givendata(10);Print();ReversePrint();
	head = delete_givendata(33);Print();ReversePrint();
	head = delete_givendata(6);Print();ReversePrint();
	head = delete_givendata(5);Print();ReversePrint();
	printf ("\n");
}
	

