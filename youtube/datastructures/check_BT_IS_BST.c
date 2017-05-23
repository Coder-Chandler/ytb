//Check if a binary tree is binary search tree or not
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
struct BtNode
{
	char data;
	struct Node *left;
	struct Node *right;
}
struct BtNode *GetNewNode(char data)
{
	BtNode *newnode = (struct BtNode*)malloc(sizeof(struct BtNode));
	newnode -> data = data;
	newnode -> left = newnode -> right = NULL;
	return newnode;
}
struct BtNode *Insert(struct BtNode *root, char data)
{
	if (root == NULL)
	{
		root = GetNewNode(char data);
		return root;
	}
	else if (data <= root -> data)
	{
		root -> left = Insert(root -> left, char data);
	}
	else
	{
		root -> right = Insert(root -> right, char data);
	}
	return root;
}
//Breadth-first
void levelorder(struct BtNode *root)
{
	if (root == NULL) return;
	queue <struct BtNode*> Q;
	Q.push(root);
	//while there is at least one discovered node
	while (!Q.empty())
	{
		struct BtNode *current = Q.front();
		printf ("%c ", current -> data);
		if (current -> left == NULL)
		{
			Q.push(current -> left);
		}
		if (curent -> right == NULL)
		{
			Q.push(current -> right);
		}
		Q.pop();//removing the element at front
	}
}
bool IsBstUtil(BtNode *root, char minValue, char maxValue)
{
	if (root == NULL) return true;
	if (root -> data > minValue && root -> data < maxValue
		&& IsBstUtil(root -> left, minValue, root -> data)
		&& IsBstUtil(root -> right, root -> data, maxValue))
		return true;
	else return false;
}
bool IsBinarySearchTree(BtNode *root)
{
	return IsBstUtil(root, INT_MIN, INT_MAX);
}
int main()
{
	BtNode *root = NULL;//Creating an empty tree
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
}
