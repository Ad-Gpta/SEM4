#include<stdio.h>
#include<stdlib.h>
int i,j,k;

typedef struct Node{
    int val;
    struct Node* left;
    struct Node* right;
} node;

node* getnode(int v)
{
    node* t = (node*)malloc(sizeof(node));
    t->val = v;
    t->left = NULL;
    t->right = NULL;
    return t;
}
node* root = NULL;
void inorder(node* t)
{
    if(t)
    {
        inorder(t->left);
        printf("-> %d", t->val);
        inorder(t->right);
    }
}
node* createBST(node* t,int v)
{
    if(t==NULL)
    {
        t = getnode(v);
        printf("\nInserting: %d", t->val);
        return t;
    }
    else if(t->val > v)
    {
        printf("\n -> %d ", t->val);
        t->left = createBST(t->left,v);
    }
    else if(t->val < v)
    {
         printf("\n-> %d ", t->val);
        t->right = createBST(t->right,v);
    }
    else if(t->val == v)
    {
        printf("\nNode already exists");
        return NULL;
    }
    return t;
}
void main()
{
    int A[5] = {3,4,5,2,1};
    node* r = root;
    for(i=0;i<5;i++)
        r = createBST(r, A[i]);
    printf("\ninorder: ");
    inorder(r);
}