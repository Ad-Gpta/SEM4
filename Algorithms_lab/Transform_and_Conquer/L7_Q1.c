//Construct BST, traverse using all 3 methods, and display balance factor for each node
#include<stdio.h>
#include<stdlib.h>
int count = 0;

typedef struct node
{
 int val;
 struct node* left;
 struct node* right;
}node;
typedef node* np;

np t = NULL;

np newnode(int n)
{
 np t = (np)malloc(sizeof(node));
 t->val = n;
 t->left = t->right = NULL;
 return t;
}

np Construct_BST(np t,int x)
{
 count++;
 if(t == NULL)
 {
 t = newnode(x);
 return t;
 }
 else if(t->val == x)
 {
 printf("\nDuplicate node entered\n");
 return t;
 }
 else if(t->val < x)
 t->right = Construct_BST(t->right, x);
 else
 t->left = Construct_BST(t->left, x);
 return t;
}

int max(int a, int b)
{
 if(a> b) return a;
 return b;
}

int height(np t)
{
 if(t == NULL) return 0;
 return 1+ max(height(t->left), height(t->right));
}
int Bal_F(np t)
{
 if(t== NULL) return 0;
 return (height(t->left)- height(t->right));
}

void inorder(np t)
{
 if(t)
 {
 inorder(t->left);
 printf("\n %d , Balance factor: %d", t->val, Bal_F(t));
 inorder(t->right);
 }
}
void preorder(np t)
{
 if(t)
 {
 printf(" %d ", t->val);
 preorder(t->left);
 preorder(t->right);
 }
}
void postorder(np t)
{
 if(t)
 {
 postorder(t->left);
 postorder(t->right);
 printf(" %d ", t->val);
 }
}

void main()
{
 int n,i,x;
 printf("\nEnter number of nodes: ");
 scanf("%d",&n);
 printf("\nEnter array elements: ");
 for(i=0;i<n;i++)
 {
 scanf("%d",&x);
 t = Construct_BST(t, x);
 }
 printf("\nOpcount: %d", count);
 //printf("\nBalance factor of t node: %d", Bal_F(t));
 printf("\nInorder: "); inorder(t);
 printf("\ninorder: "); inorder(t);
 printf("\nPostorder: "); postorder(t);
}