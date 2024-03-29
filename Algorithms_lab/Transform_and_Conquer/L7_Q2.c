//Write a program to create the AVL tree by iterative insertion.
//NOT WORKING YET
#include<stdio.h>
#include<stdlib.h>
int count = 0;

typedef struct Node
{
   int val;
   node* left;
   node* right;
}node;

typedef node* np;
np t = NULL;

np newnode(int n);
np RR(np t);
np LL(np t);
np RL(np t);
np LR(np t);
int count_nodes(np t);
void insert(np t, int x);
int max(int a, int b);
int height(np t);
int Bal_F(np t);
np Construct_BST(np t,int x);
void inorder(np t);

np newnode(int n)
{
   np t = (np)malloc(sizeof(node));
   t->val = n;
   t->left = t->right = NULL;
   return t;
}
np RR(np t) //performing rr operation
{
   np p = t;
   np q = t->right;
   p->right = q->left;
   q->left = p;
   return q;
}
np LL(np t) //performing ll operation
{
   np p = t;
   np q = t->left;
   p->left = q->right;
   q->right = p;
   return q;
}
np RL(np t)
{
   np p = t;
   np q = t->right;
   np r = q->left;
   q->left = r->right;
   r->right = q;
   p->right = r;
   t = RR(p);
   return p;
}
np LR(np t) //performing ll operation
{
   np p = t;
   np q = t->left;
   np r = q->right;
   q->right = r->left;
   r->left = q;
   p->left = r;
   t = LL(t);
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
int count_nodes(np t)
{
   if(t== NULL) return 0;
   return 1 + count_nodes(t->left) + count_nodes(t->right);
}
void insert(np t, int x)
{
   int ch = 0,i;
   while(ch==0)
   {
               if(t== NULL)
               {
                           t = newnode(x);
                           ch = 1;
                           break;
               }
               else if(t->val == x)
               {
                           printf("\nDuplicate node entered\n");
                           return;
               }
               else if(t->val < x)
                           t= t->right;
               else
                           t = t->left;
   }
   int n = count_nodes(t);
   for(i=0;i<n;i++)
   {
   }
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
void main()
{
   int n,i,x;
   /*printf("\nEnter number of nodes: ");
   scanf("%d",&n);
   printf("\nEnter array elements: ");*/
   n = 7;
   int A[7] = {4,6,2,3,1,5,7};
   for(i=0;i<n;i++)
   {
               //scanf("%d",&x);
               x = A[i];
               t = Construct_BST(t, x);
   }
   printf("\nEntered tree: Inorder: "); inorder(t);
   //printf("\nBalance factor of t node: %d", Bal_F(t));
   printf("\nRR: ");
   //t = RR(t);
   //printf("\nInorder: "); inorder(t);
   printf("\nRL: ");
   //t = RL(t);
   //printf("\nInorder: "); inorder(t);
   printf("\nLL: ");
   //t = LL(t);
   //printf("\nInorder: "); inorder(t);
   printf("\nLR: ");
   //t = LR(t);
   //printf("\nInorder: "); inorder(t);
}