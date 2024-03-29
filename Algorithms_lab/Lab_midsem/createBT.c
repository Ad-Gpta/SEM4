#include<stdio.h>
#include<stdlib.h>
int count = 0;
typedef struct Node
{
    int val;
    struct Node* left;
    struct Node* right;
}node;

typedef struct Node* nptr;

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

void inorder(nptr t)
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
    int x;
    printf("\nEnter t node value: ");
    scanf("%d",&x);
    t = createBT(t, x);
    printf("\ninorder: "); inorder(t);
}