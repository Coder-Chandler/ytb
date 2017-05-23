//Binary Search Tree - Implementation in C/C++
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct BstNode
{
	//int data;
	char data; 
	BstNode *left;
	BstNode *right;
};
BstNode *GetNewNode(char data)
{
	BstNode *newNode = new BstNode();//BstNode *newNode = (struct BstNode*)malloc(sizeof(struct Node)
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
//Deepth-first-preorder traversal
void preorder(struct BstNode *root)
{
	if (root == NULL) return;
	printf ("%s ", root -> data);
	preorder(root -> left);
	preorder(root -> right);
}
//Deepth-first-Inorder traversal
void inorder(struct BstNode *root)
{
	if (root == NULL) return;
	inorder(root -> left);
	printf ("%s ", root -> data);
	inorder(root -> right);
}
//Deepth-first-postorder traversal
void postorder(struct BstNode *root)
{
	if (root == NULL) return;
	postorder(root -> left);
	postorder(root -> right);
	printf ("%s ", root -> data);
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
	root = Insert(root, "ROOT");
	root = Insert(root, "Lx");
	root = Insert(root, "Rx");
	root = Insert(root, "SHILCC");
	root = Insert(root, "Chandler");
	root = Insert(root, "coder");
	levelorder(root);
	preorder(root);
	inorder(root);
	postorder(root);
	cout<<"\n";
	//Ask usr to enter a number
	/*
	int number;
	cout<<"Enter number be serched\n";
	cin>>number;
	if (Search(root, number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";	
	*/
}
