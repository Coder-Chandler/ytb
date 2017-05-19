//Reverse a Linked List using reversive
//2017-05-19 20:16:22 
#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head;
struct Node *Insert(struct Node *head, int data)
{
	Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp -> data = data;
	temp -> next = NULL;
	//printf (" %d",temp -> data);
	if (head == NULL)
	{
		head = temp;
	}
	else
	{
		Node *temp1 = head;
		while (temp1 -> next != NULL)
		{
			temp1 = temp1 -> next;
			//printf ("%d",temp1 -> data);
		}
		temp1 -> next = temp;
		//printf ("%d",temp1 -> data);
	}
	//printf ("%d",temp -> data);
	return head;
	
}
void print(struct Node *p)
{
	struct Node *temp2 = p;
	while(temp2 != NULL)
	{
		printf (" %d",temp2 -> data);
		temp2 = temp2 -> next;
	}
	printf ("\n");
}
void Reverse(struct Node *p)//reverse linklist using reverse
{
	if (p -> next == NULL)
	{
		head = p;
		return;
	}
	Reverse(p -> next);
	struct Node *q = p -> next;
	q -> next = p;
	p -> next =NULL;
}
int main()
{
	head = NULL;
	head = Insert(head,2);
	head = Insert(head,5);
	head = Insert(head,7);
	head = Insert(head,3);
	head = Insert(head,9);
	print(head);
	Reverse(head);
	print(head);
	//printf ("\n");
}

