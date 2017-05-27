//C program to insert a node in AVL TREE
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
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 30);
	root = Insert(root, 50);
	root = Insert(root, 40);
	root = Insert(root, 25);
	/* the Constructed AVL tree would be
			 30
		   /    \
		  20    40
		 /  \     \
		10  25    50
	*/
	printf ("Preorder traversal of the constructed AVL TREE is : \n");
	preorder(root);
	printf ("\n");
	return 0;
}

