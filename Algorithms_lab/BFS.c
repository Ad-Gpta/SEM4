//Breadth first search by creating binary tree
#include<stdio.h>
#include<stdlib.h>

typedef node
{
    int val;
    node* left;
    node* right;
} node;

node* getnode()
{
    node * n= (node*)malloc(sizeof(node));
    n->val = 0;
    n->left = NULL;
    n->right = NULL;
    return n;
}
node* t = NULL;
node* insert(node* t, int n)
{
    if(t == NULL)
    {
        printf("\ninserting %d", n);
        t = getnode();
        t->val = n;
        return t;
    }
    else
    {
        printf("\ntraversing %d", t->val);
        if(t->val>n)
        {
            printf("\nleft");
            t->left = insert(t->left, n);
        }
        else if(t->val<n)
        {
            printf("\nright");
            t->right = insert(t->right, n);
        }
        else if(t->val == n)
        {
            printf("\nNode already present\n");
            return NULL;
        }
    }
    return t;
}

void inorder(node* t)
{
    while(t!=NULL)
    {
        inorder(t->left);
        printf(" %d ", t->val);
        inorder(t->right);
    }
}

void main()
{
    int i, n;
    node* r = t;
    for(i=0;i<5;i++)
    {
        printf("\nEnter val: ");
        scanf("%d", &n); 
        t = insert(t, n);
        t = r;
        //inorder(t);
    }
    printf("\ncompleted");
    //inorder(t);
    printf("%d %d %d", t->val, t->left->val, t->right->val);
}