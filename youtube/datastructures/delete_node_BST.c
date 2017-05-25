//Delete a node from binary search tree
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};
//define a function to find the minimum node
struct Node *FindMin(struct Node *root)
{
	while (root -> left != NULL) root = root -> left;
	return root;
}
struct Node *Delete(struct Node *root, int data)
{
	if (root == NULL) return root;
	else if (data < root -> data) root -> left = Delete(root -> left, data);
	else if (data > root -> data) root -> right = Delete(root -> right, data);
	else//wohoo....i found you,get ready to delete!
	{
		if (root -> left == NULL && root -> right == NULL)//case 1 : no child
		{
			free(root);//C++ --> delete root;
			root == NULL;
		}
		//case 2 : one child
		else if (root -> left == NULL)
		{
			struct Node *temp = root;
			root = root -> right;
			free(temp);//C++ --> delete root;		
		}
		else if (root -> right == NULL)
		{
			struct Node *temp = root;
			root = root -> left;
			free(temp);//C++ --> delete root;
		}
		else//case 3 : two children
		{
			struct Node *temp = FindMin(root -> right);//find the minimum node at right subtree
			root -> data = temp -> data;
			root -> right = Delete(root -> right, temp -> data;);
		}
	}
	return root;
}
//Function to visit nodes in Inorder
void Inorder(struct Node *root)
{
	if (root = NULL)
	{
		Inorder(root -> left);
		printf ("%d", rot -> data);
		Inorder(root -> right);
	}
}
// Function to Insert Node in a Binary Search Tree
struct Node *Insert(struct Node *root, int data)
{
	if (root == NULL)
	{
		Node *root = (struct Node*)malloc(sizeof(struct Node));//C++ --> root = new Node();
		root -> data = data;
		root -> left = root -> right = NULL;
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
int main()
{
	/*Code To Test the logic
	  Creating an example tree
	            5
			   / \
			  3   10
			 / \   \
			1   4   11
    */
    struct Node* root = NULL;
	root = Insert(root,5); root = Insert(root,10);
	root = Insert(root,3); root = Insert(root,4); 
	root = Insert(root,1); root = Insert(root,11);
	//print Nodes before we delete a node
	printf ("Now Inorder : ")
	Inorder(root)
	// Deleting node with value 5, change this value to test other cases
	root = Delete(root,5);
	//Print Nodes in Inorder after we delete 5
	cout<<"Inorder: ";
	Inorder(root);
	cout<<"\n";
}
