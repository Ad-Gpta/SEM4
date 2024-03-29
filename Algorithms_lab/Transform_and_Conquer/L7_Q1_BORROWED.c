//AVL tree by iterative insertion
#include <stdio.h>
#include <stdlib.h>
int count = 0;
typedef struct node * np;
struct node
{
    int data;
    np lchild;
    np rchild;
};

np getnode(int item)
{
    np t = ((np)malloc(sizeof(struct node)));
    t->data= item;
    t->lchild=t->rchild = NULL;
    return t;
}

np Insert_BST(np t, int item)
{
    if (!t)
    {
        t = getnode(item);
        return t;
    }
    else
    {
        if (item<t->data)
            t->lchild = Insert_BST(t->lchild, item);
        else if (item>t->data)
            t->rchild = Insert_BST(t->rchild, item);
        else
            printf("Duplicates are not allowed\n");
        return t;
    }
}

np create_BST(np t,int data)
{
    int x;
    t=getnode(data);
    while(1)
    {
        printf("Enter data to insert (-1 to exit) : \t");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }
        t=Insert_BST(t,x);
    }
    return t;
}

int max(int a,int b)
{
    return a>b?a:b;
}

int height(np t)
{
    if(t)
    {
        return max(height(t->lchild),height(t->rchild))+1;
    }
}

int balfac(np t)
{
    return height(t->lchild)-height(t->rchild);
}

np leftrotate(np x)
{
    np y=x->rchild;
    np z=y->lchild;

    y->lchild=x;
    x->rchild=z;

    return y;
}

np rightrotate(np x)
{
    np y=x->lchild;
    np z=y->rchild;

    y->rchild=x;
    x->lchild=z;
    return y;
}

np Insert_AVL(np t,int item)
{
    count++;
    /*
    while(t)
    {
        if (item<t->data)
        {
            t = t->lchild;
            continue;
        }
        else if (item>t->data)
        {
            t = t->rchild;
            continue;
        }
        else if(item == t->data)
            return t;
    int bal=balfac(t);
    if (bal > 1 && item < t->lchild->data)
        t =  rightrotate(t);
 
    if (bal < -1 && item > t->rchild->data)
        t = leftrotate(t);

    if (bal > 1 && item > t->lchild->data)
    {
        t->lchild =  leftrotate(t->lchild);
        t = rightrotate(t);
    }
 
    if (bal < -1 && item < t->rchild->data)
    {
        t->rchild = rightrotate(t->rchild);
        t = leftrotate(t);
    }
    }
    if (!t)
    {
        t = getnode(item);
        return t;
    }
    */
    if (!t)
    {
        t = getnode(item);
        return t;
    }
    if (item<t->data)
            t->lchild = Insert_AVL(t->lchild, item);
        else if (item>t->data)
            t->rchild = Insert_AVL(t->rchild, item);
        else
            return t;
    
    int bal=balfac(t);

    if (bal > 1 && item < t->lchild->data)
        return rightrotate(t);
 
    if (bal < -1 && item > t->rchild->data)
        return leftrotate(t);

    if (bal > 1 && item > t->lchild->data)
    {
        t->lchild =  leftrotate(t->lchild);
        return rightrotate(t);
    }
 
    if (bal < -1 && item < t->rchild->data)
    {
        t->rchild = rightrotate(t->rchild);
        return leftrotate(t);
    }
 
    return t;
}

np create_AVL(np t,int data)
{
    int x;
    t=getnode(data);
    while(1)
    {
        printf("Enter data to insert (-1 to exit) : \t");
        scanf("%d",&x);
        if(x==-1)
        {
            break;
        }
        t=Insert_AVL(t,x);
    }
    return t;
}

void inorder(np t)
{
 if(t)
 {
 inorder(t->lchild);
 printf("\n %d , Balance factor: %d", t->data, balfac(t));
 inorder(t->rchild);
 }
}

void main()
{
    np root=NULL;
    int data;
    printf("Enter t Data : \t");
    scanf("%d",&data);
    root=create_AVL(root,data);
    printf("\nFinal avl tree: ");
    inorder(root);
    printf("\nOpcount: %d", count);
    printf("\n");
}