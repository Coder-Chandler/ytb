//Reverse linklist
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void Reverse(struct Node *p)
{
    struct Node *current, *prev, *next;
    current = p;
    prev = NULL;
    while (current != NULL)
    {
		next = current -> next;
		current -> next = prev;
		prev = current;
		current = next;
    }
    head = prev;
}
struct Node *Insert (struct Node *head, int data)
{
    Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
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
		}
		temp1 -> next = temp;
    }
    return head;
}
void print(struct Node *head)
{
    Node *temp2 = head;
    while (temp2 != NULL)
    {
		printf (" %d",temp2 -> data);
		temp2 = temp2 -> next;
    }
    printf ("\n");
}
int main()
{
    head = NULL;//Local variable
    //head = Insert(head,2);
    //head = Insert(head,4);
    //head = Insert(head,6);
    //head = Insert(head,8);
    int n;
    printf ("Enter the numbers of your integer : ");
    scanf ("%d",&n);
    for (int i = 0; i<n; i++)
    {   
		int m;
		printf ("Enter your integer : ");
		scanf ("%d",&m);
        head = Insert(head,m);
    } 
    print(head);
    Reverse(head);
    print(head);   
}
