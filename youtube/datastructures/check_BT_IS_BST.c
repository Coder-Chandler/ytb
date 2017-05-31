//Check if a binary tree is binary search tree or not
#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;
struct BstNode
{
	//int data;
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
		cout<<current -> data<<" ";
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
bool IsBstUtil(struct BstNode *root, int minValue, int maxValue)
{
	if (root == NULL) return true;
	if (root -> data > minValue && root -> data < maxValue
		&& IsBstUtil(root -> left, minValue, root -> data)
		&& IsBstUtil(root -> right, root -> data, maxValue))
		return true;	
	else return false;
}
bool IsBinarySearchTree(struct BstNode *root)
{
	return IsBstUtil(root, INT_MIN, INT_MAX);
}
int main()
{
	struct BstNode *root = NULL;//Creating an empty tree
	root = Insert(root, 'G');
	root = Insert(root, 'D');
	root = Insert(root, 'P');
	root = Insert(root, 'A');
	root = Insert(root, 'E');
	root = Insert(root, 'O');
	root = Insert(root, 'R');
	root = Insert(root, 'Y');
	root = Insert(root, 'Z');
	//root = Insert(root, 'I');
	//root = Insert(root, 'X');
	//root = Insert(root, 'Z');
	//root = Insert(root, 'Y');
	printf ("Levelorder-");
	levelorder(root);
	printf ("\n");
	bool b = IsBinarySearchTree(root);
	printf ("%s" ,b == false ? "false":"true");
	printf ("\n");
}
