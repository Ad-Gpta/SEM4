#include<stdio.h>
#include<stdlib.h>
int count = 0, op_complete = 0;
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
    printf("\nStarting insert;\n x val: %d\n", x);
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
        op_complete = 1;
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
        t->left=insert(t->left, x); //t->left might me null value; might be passing null value
        //after it gets returned t value, does not go tp else if block, but the end of the function
    }
    else if(t->val < x)
    {
        printf("->%d ",t->val);
        printf(" right ");
        t->right=insert(t->right, x); //might be passing null value
    }
    printf("\nDone with if block\n");
    return t; //end of the function, goes back to main and returns t where there was null before
}


void main()
{
    t = insert(t, 4);
    printf("\nt val: %d\n",t->val);
    t = insert(t, 5);
    printf("\nt val: %d\n",t->val);
    t = insert(t, 3);
    printf("\nt val: %d\n",t->val);
    t = insert(t, 1);
    printf("\nt val: %d\n",t->val);
    t = insert(t, 2);
    printf("done with insert");
    printf("\nt val: %d\n",t->val);
    printf("\nt->left val: %d\n",t->left->val);
    printf("\nt->right val: %d\n",t->right->val);
    printf("%d <- %d -> %d", t->left->val,t->val, t->right->val);
}