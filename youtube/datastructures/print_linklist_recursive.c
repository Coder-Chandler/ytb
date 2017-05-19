//Print Linked List using Recursive
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void print(struct Node *p)
{
    if (p == NULL) return;
    printf ("%d",p -> data);
    print(p -> next);//print the linklist using recursive !
}
struct Node *Insert(Node *head, int data)//insert data at the end of linklist
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
int main()
{
    struct Node *head = NULL;//Local variable
    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,5);
    print(head);
    printf ("\n");
}
