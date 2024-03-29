//find number of nodes in Binary tree
#include<stdio.h>
#include<stdlib.h>
int count = 0;
typedef node
{
    int val;
    node* left;
    node* right;
}node;

typedef node* nptr;

nptr newNode(int n)
{
    nptr t = (nptr)malloc(sizeof(node));
    t->val = n;
    t->right = NULL;
    t->left = NULL;
    return t;
}

nptr t = NULL;

nptr createBT(nptr t, int x)
{
    int n;
    if(x!= -1)
    {
        t = newNode(x);
        printf("\nEnter lchild of %d: ", x);
        scanf("%d", &n);
        t->left = createBT(t->left, n); //once this gets null moves on to: 
        printf("\nEnter rchild of %d: ", x);
        scanf("%d", &n);
        t->right = createBT(t->right, n);  //once this gets null moves on to: 
        return t;
    }
    return NULL; //when entered -1
}

int count_node(nptr t)
{
    if(t==NULL) return 0;
    count++;
    return 1 + count_node(t->left) +count_node(t->right);
}

void main()
{
    int x;
    printf("\nEnter t node value: ");
    scanf("%d",&x);
    t = createBT(t, x);
    int n = count_node(t);
    printf("\nno of nodes: %d,\nopcount: %d",n,count);
}