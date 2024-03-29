#include<stdio.h>
#include<stdlib.h>
int count = 0;
typedef node
{
    int val;
    node* left;
    node* right;
}node;

node* newNode()
{
    node* t = (node*)malloc(sizeof(node));
    t->val = 0;
    t->right = NULL;
    t->left = NULL;
    return t;
}

node* t = NULL;

node* insert(node* t,int x)
{
    count++;
    if(count>20)
    {
        printf("\nchecking");
        printf("\nt: %d", t->val);
        printf("\nt->right: %d", t->right->val);
        printf("\nt->left: %d", t->left->val);
        exit(0);
    }
    if(t==NULL)
    {
        t = newNode();
        t->val = x;
        printf("->%d ",t->val);
        return t; //returning node instead of null that was originally there
    }
    else if(t->val == x)
    {
        printf("\nDuplicate node");
        return NULL;
    }
    else if(t->val > x)
    {
        printf("->%d ",t->val);
        printf(" left ");
        t->left=insert(t->left, x); //t->left might be null value; might be passing null value
        //after it gets returned t value, does not go to else if block, but the end of the function
    }
    else if(t->val < x)
    {
        printf("->%d ",t->val);
        printf(" right ");
        t->right=insert(t->right, x); //might be passing null value
    }
    return t; //end of the function, goes back to main and returns t where there was null before
}

void inorder(node* t)
{
    if(t)
    {
        inorder(t->left);
        printf(" %d", t->val);
        inorder(t->right);
    }
}
void main()
{
    int n, i,x;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("\nEnter values of Binary tree: ");
    for(i=0;i<n;i++)
    {
        printf("\nEnter value: ");
        scanf("%d",&x);
        t = insert(t, x);
    }
    printf("\ninorder: ");
    inorder(t);
}