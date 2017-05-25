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
/*因为INT_MIN, INT_MAX是正负无穷，所以我写了int但是我要执行的是char，按道理
应该比较ascii码，但是最终没有输出bool值，大神帮我解惑*/
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
	IsBinarySearchTree(root);//这里没有按预期print出bool值
	printf ("\n");
}