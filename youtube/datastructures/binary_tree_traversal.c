//Binary Search Tree - Implementation in C++
#include <iostream>
#include <queue>
using namespace std;
struct BstNode
{
	int data; 
	BstNode *left;
	BstNode *right;
};
BstNode *GetNewNode(int data)
{
	BstNode *newNode = new BstNode();//BstNode *newNode = (struct BstNode*)malloc(sizeof(struct Node)
	newNode -> data = data;
	newNode -> left = newNode -> right = NULL;
	return newNode;
}
BstNode *Insert(BstNode *root, int data)
{
	if (root == NULL)//empty tree
	{
		root = GetNewNode(data);
		return root;
	}
	else if (data <= root -> data)
	{
		root -> left = Insert(root -> left, data);
	}
	else
	{
		root -> right = Insert(root -> right, data);
	}
	return root;
}

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
bool Search(BstNode *root, int data)
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
	root = Insert(root, 5);
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	levelorder(root);
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
