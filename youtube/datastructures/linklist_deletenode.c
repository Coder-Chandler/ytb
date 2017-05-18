//Link List : Delete a node at nth position
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;//Global
void Insert(int data)//insert an integer at end of node
{
    struct Node *temp = (struct Node*)sizeof(struct Node));
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
	while (temp2 -> next != NULL)
        {
	    printf (" %d",temp2 -> data);
	    temp2 = temp2 -> next;
	}
    }
    printf ("\n");
}
void Delete(int n)//delete node at position
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
