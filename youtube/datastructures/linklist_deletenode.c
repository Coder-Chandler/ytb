//Link List : Delete a node at nth position
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;//Global
struct Node *Insert(int data)//insert an integer at end of node
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp -> next = NULL;
    if (head == NULL) head = temp;
    else
    {
        Node *temp1 = head;
	while (temp1 -> next != NULL) temp1 = temp1 -> next;
        temp1 -> next = temp;
    }
    return head;
}
void print()//print all element in the list
{
    if (head == NULL) return;
    else
    {
	Node *temp2 = head;
	while (temp2 != NULL)
        {
	    printf (" %d",temp2 -> data);
	    temp2 = temp2 -> next;
	}
    }
    printf ("\n");
}
void Delete(int n)//delete node at position
{
    Node *temp3 = head;
    if (n == 1)
    {
	head = temp3 -> next;//head now points to second node 
        free(temp3);
        return;
    }
    int i;
    for (i = 0; i<n-2; i++)
    {
	temp3 = temp3 -> next;//temp3 points to (n-1)th node
    }
    struct Node *temp4 = temp3 -> next;
    temp3 -> next = temp4 -> next;
    free(temp4);
}
int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    print();
    int n;
    printf ("Enter a position\n");
    scanf ("%d",&n);
    Delete(n);
    print();
}
