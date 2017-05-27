//C program to Delete a node in AVL TREE
#include <stdio.h>
#include <stdlib.h>
//An VL TREE node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
//A utility fuction to get maximum of two integers
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int height(struct Node *N)
{
	if (N == NULL) return 0;
	return N -> height;
}
//Helper function that allocates a new node with the given key and NULL left and right printers
struct Node *GetNewNode(int key)
{
	struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode -> key = key;
	newnode -> left = NULL;
	newnode -> right = NULL;
	newnode -> height = 1;//new node is initially add at leaf
	return newnode;
} 
//Autility function to right rotate subtree rooted with y;
struct Node *rightrotate(struct Node *y)// Right Rotate
{
	struct Node *x = y -> left;
	struct Node *T2 = x -> right;
	//preform rotation
	x -> right = y;
	y -> left = T2;
	//update heights
	y -> height = max(height(y -> left), height(y -> right)) + 1;
	x -> height = max(height(x -> left), height(x -> right)) + 1;
	//return new root
	return x;
}
//A utility function to left rotate subtree rooted with x
struct Node *leftrotate(struct Node *x)
{
	struct Node *y = x -> right;
	struct Node *T2 = y -> left;
	//preform rotation
	y -> left = x;
	x -> right = T2;
	//update hrights
	x -> height = max(height(x -> left), height(x -> right)) + 1;
	y -> height = max(height(y -> left), height(y -> right)) + 1;
	//return new root
	return y;
}
//get balance factors of node N
int getBalance(struct Node *N)
{
	if (N == NULL) return 0;
	return height(N -> left) - height(N -> right);
}
/*Given a non-empty binary search tree, return the node with minimum key
value found in that tree.note that the entire tree does not need be searched.*/
struct Node *FindMin(struct Node *root)
{
	while (root -> left != NULL) root = root -> left;
	return root;
}
//Recursive function to insert key in subtree rooted with node and return new root of subtree
struct Node *Insert(struct Node *node, int key)
{
	/* 1.perform the normal BST insertion*/
	
	if (node == NULL) 
		return GetNewNode(key);
		
	else if (key < node -> key)
		node -> left = Insert(node -> left, key);
	else if (key > node -> key)
		node -> right = Insert(node -> right, key);
	else//equal keys are not allowed in BST	
		return node;
		
	/* 2.update height of this ancestor node */
	
	node -> height = 1 + max(height(node -> left), height(node -> right));
	
	/* 3. Get the balance factors of this ancestors node to check whether this node became unbalance */
	
	int balance = getBalance(node);
	
	//if this node becomes unbalance, then there 4 cases !
	
	//1.LEFT LEFT CASE
	if (balance > 1 && key < node -> left -> key)
		return rightrotate(node);
	//2.RIGHT RIGHT CASE
	if (balance < -1 && key > node -> right -> key)
		return leftrotate(node);
	//3.LEFT RIGHT CASE
	if (balance > 1 && key > node -> left -> key)
	{	
		node -> left = leftrotate(node -> left);
		return rightrotate(node);
	}
	//4.RIGHT LEFT CASE
	if (balance < -1 && key < node -> right -> key)
	{
		node -> right = rightrotate(node -> right);
		return leftrotate(node);
	}
	
	/* return the (unchanged) Node pointers */
	return node;
}
//Recursive function to delete a node with given from key subtree with given root,
//it returns root of the modified subtree
struct Node *deleteNode(struct Node *root, int key)
{
	//STEP 1 : PERFORM STANDARD BST DELETE
	if (root == NULL) 
		return root;
	//if the key to be deleted is smaller than the root's key,then it lies in left subtree
	else if (key < root -> key)
		root -> left = deleteNode(root -> left, key);
	//if the key to be deleted is greater than the root's key,then it lies in right subtree
	else if (key > root -> key)
		root -> right = deleteNode(root -> right, key);
	//if the key is same as root's key,then this is the node to be deleted.
	//delete the node will have 4 cases
	else
	{
		//case 1. node with no child
		if (root -> left == NULL && root -> right == NULL)
		{
			free(root);
			root = NULL;
		}
		//case 2. node with one child
		else if (root -> left == NULL)
		{
			struct Node *temp0 = root;
			root = root -> right;
			free(temp0);
		}
		else if (root -> right == NULL)
		{
			struct Node *temp1 = root;
			root = root -> left;
			free(temp1);
		}
		//case 3. node with two children
		else 
		{
			/*
			Find the minimum node at the right subtree of the node 
			that we want to delete and use the minimum node to repalce 
			that node we deleted to keep the BT is a BST !
			*/
			struct Node *temp2 = FindMin(root -> right);
			root -> key = temp2 -> key;
			/*
			 Although we removed the node and replaced with the minimum 
			 node, But don't forget, we also need to delete the minimum node
			 in his original location
			*/
			root -> right = deleteNode(root -> right, temp2 -> key);
		}
	}
	//STEP 2. UPDATE HEIGHT OF THE CURRENT NODE
	root -> height = 1 + max(height(root -> left), height(root -> right));
	//STEP 3. GET THE BALANCE FACTORS OF THIS NODE (to check whether this
	//node became unbalance) 
	int balance = getBalance(root);
	//if this node becomes unbalance, then there are 4 cases
	//LEFT LEFT CASE
	if (balance > 1 && getBalance(root -> left) >= 0)
		return rightrotate(root);
	//LEFT RIGHT CASE
	if (balance > 1 && getBalance(root -> right) < 0)
	{
		root -> left = leftrotate(root -> left);
		return rightrotate(root);
	}
	//RIGHT RIGHT CASE
	if (balance < -1 && getBalance(root -> right) <= 0)
		return leftrotate(root);
	//RIGHT LEFT CASE
	if (balance < -1 && getBalance(root -> right) > 0)
	{
		root -> right = rightrotate(root -> right);
		return leftrotate(root);
	}
	return root;
}
//A utility function to print preorder traversal of the tree
//the function also print height of every node
void preorder(struct Node *root)
{
	if (root != NULL)
	{
		printf("%d ", root -> key);
		preorder(root -> left);
		preorder(root -> right);	
	}
}
/*Drier program to test above function*/
int main()
{
	struct Node *root = NULL;
	/* Constructing tree given in the above figure*/
	root = Insert(root, 9);
	root = Insert(root, 5);
	root = Insert(root, 10);
	root = Insert(root, 0);
	root = Insert(root, 6);
	root = Insert(root, 11);
	root = Insert(root, -1);
	root = Insert(root, 1);
	root = Insert(root, 2);
	/* the Constructed AVL tree would be
			  9
		    /   \
		   1    10
		 /  \     \
	    0    5     11
	   /    / \
     -1	   2   6
	*/
	printf ("\nPreorder traversal of the constructed AVL TREE is : \n");
	preorder(root);
	printf ("\n");
	root = deleteNode(root, 10);
	/*the AVL TREE after delete of 10
	          1
		    /   \
		   0     9
		  /     / \
	    -1     5   11
	          / \
     	     2   6
    */
    printf ("\npreorder traversal after delete of 10 : \n");
    preorder(root);
    printf ("\n\n");
	return 0;
}

