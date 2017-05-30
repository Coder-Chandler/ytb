//Binary Search Tree - Implementation in C/C++
#include <stdio.h>
#include <stdlib.h>
//#include <iostream>
#include <queue>
//#include <string>
using namespace std;
struct BstNode
{
	int data0;
	char data; 
	struct BstNode *left;
	struct BstNode *right;
};
struct BstNode *GetNewNode(char data)
{	
	//C++ -->BstNode *newNode = new BstNode();
	BstNode *newNode = (struct BstNode*)malloc(sizeof(struct BstNode));	
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}
struct BstNode *Insert(struct BstNode *root, char data)
{
	if (root == NULL)//empty tree
	{
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root -> data 	)
	{
		root -> left = Insert(root -> left, data);
	}
	else
	{
		root -> right = Insert(root -> right, data);
	}
	return root;
}
//Breadth-first
void levelorder(struct BstNode *root)
{
	if (root == NULL) return;
	queue <struct BstNode*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while (!Q.empty())
	{
		struct BstNode *current = Q.front();
		printf ("%c ", current -> data);
		if (current -> left != NULL)
		{
			Q.push(current -> left);
		}
		if (current -> right != NULL)
		{
			Q.push(current -> right);
		}
		Q.pop();//removing the element at front
	}
}
//Deepth-first-preorder traversal-<root><left><right>
void preorder(struct BstNode *root)
{
	if (root == NULL) return;
	printf ("%c ", root -> data);
	preorder(root -> left);
	preorder(root -> right);
}
//Deepth-first-Inorder traversal-<left><root><right>
void inorder(struct BstNode *root)
{
	if (root == NULL) return;
	inorder(root -> left);
	printf ("%c ", root -> data);
	inorder(root -> right);
}
//Deepth-first-postorder traversal-<left><right><root>
void postorder(struct BstNode *root)
{
	if (root == NULL) return;
	postorder(root -> left);
	postorder(root -> right);
	printf ("%c ", root -> data);
}
bool Search(BstNode *root, char data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root -> data == data)
	{
		return true;
	}
	else if (data <= root -> data)
	{
		return Search(root -> left, data);
	}
	else
	{
		return Search(root -> right, data);
	}	
}
int main()
{
	BstNode *root = NULL;//Creating an empty tree
	root = Insert(root, 'F');
	root = Insert(root, 'D');
	root = Insert(root, 'J');
	root = Insert(root, 'B');
	root = Insert(root, 'E');
	root = Insert(root, 'G');
	root = Insert(root, 'K');
	root = Insert(root, 'A');
	root = Insert(root, 'C');
	root = Insert(root, 'I');
	printf ("Levelorder-");
	levelorder(root);
	printf ("\n");
	printf ("Preorder-");
	preorder(root);
	printf ("\n");
	printf ("Inorder-");
	inorder(root);
	printf ("\n");
	printf ("Postorder-");
	postorder(root);
	printf ("\n");
	//Ask usr to enter a number
	char data;
	printf ("Enter number be serched : ");
	scanf ("%c",&data);
	if (Search(root, data) == true) printf ("Found");
	else printf ("Not Found");	
	printf ("\n");
}
