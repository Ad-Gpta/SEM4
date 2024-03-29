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
    n->left = n->right = NULL;
    return n;
}
node* t = NULL;
void insert(node* t, int n)
{
    if(t == NULL)
    {
        t = getnode();
        t->val = n;
        return;
    }
    else{
        while(t!=NULL)
        {
            //t = r;
            if(r->val>n)
            {
                if(r->left == NULL)
                {
                    r->left = getnode();
                    r->left->val = n;
                    return;
                }
                r = r->left;
            }
            else if(r->val<n)
            {
                if(r->right == NULL)
                {
                    r->right = getnode();
                    r->right->val = n;
                    return;
                }
                r = r->right;
            }
            else if(r->val == n)
            {
                printf("\nNode already present\n");
                return;
            }
        }
        printf("\n%d Value successfully entered\n",n);
        printf("\nReturning");
    }
}

void inorder(node* t)
{
    while(t)
    {
        inorder(t->left);
        printf(" %d ", t->val);
        inorder(t->right);
    }
}

void main()
{
    int i, n;
    for(i=0;i<5;i++)
    {
        printf("\nEnter val: ");
        scanf("%d", &n);
        insert_find(t, n);
    }
    inorder(t);
}
\