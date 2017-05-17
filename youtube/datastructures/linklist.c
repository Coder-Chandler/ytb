//Link LIst: Inserting a node at beginning
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;//global variable,can be accessed anywhere
Node *Insert(Node *head, int x)
{
    struct Node *temp = (Node*)malloc(sizeof(struct Node));
    temp -> data = x;
    temp -> next = NULL;
    if (head != NULL) temp -> next = head;
    head = temp;
}
void print(Node *head)
{
    printf ("List is: ");
    while (head != NULL)
    {
        printf (" %d", head -> data);
         head = head -> next;
    }
    printf ("\n"); 
}
int main()
{
    Node *head = NULL;//emoty list
    printf ("How many numbers\n");
    int n, i, x;
    scanf("%d",&n);
    for (i = 0; i<n; i++)
    {
        printf ("Enter the number \n");
        scanf ("%d",&x);
        head = Insert(head,x);
        print(head);
    }
}
