/*Write a program to create a heap for the list of integers using top-down heap construction algorithm and 
analyze its time efficiency.*/
#include<stdio.h>
int count= 0;
/*#include<stdlib.h>
typedef struct Node* np;
typedef struct Node
{
    int val;
    np l;
    np r;
}node;
np root = NULL;
np newnode(int x)
{
    np t = (np)malloc(sizeof(node));
    t->val = x;
    t->l = t->r = NULL;
}*/

int H[50], f=0, r=1;
void disp_H();
void Heapify(int Q[]);
//np newnode(int x);
void reset();
//void insert_heap(int curr);
//np Create_Heap(np t, int v);
//void inorder(np t);

void disp_H()
{
    int i;
    for(i=1; i<=r;i++)
        printf(" %d", H[i]);
}

 

void reset() //resets the queue to all NULL values
{
    for(int i=0;i<50;i++)
        H[i] = -99;
    f = 0;
    r = 1;
}
void Heapify(int Q[]) //top down approach
{
    int heap = 0,v= 0;
    int n = r; //number of elements;
    int i, k,j;
    for(i = 1; i<=n/2;i++)
    {
        count++;
        k = i;
        v = Q[k];
        heap = 0;
        while( heap== 0 & 2*k <=n)
        {
            j = 2*k;
            if(j<n) //2 children present
                if( Q[j] < Q[j+1] )
                    j = j+1;
            if( v>= Q[j])
                heap = 1;
            else
            {
                Q[k] = Q[j];
                k = j;
            }
        }
        Q[k] = v;
    }
    printf("\nCurrent heap: "); disp_H(Q);
}

/* void insert_heap(int curr)
{
     //curr is latest element entered
     int i, n = r, v;
     while(curr>1)
         {
             count++;
             v = H[curr/2];
             if(curr%2 !=0) //if curr is odd (if even, root has only left child; right child not entered yet)
                 curr = max_elem(curr-1, curr);
             if(v<H[curr]) //if parent is smaller than entered val, switch
             {
                 H[curr/2] = H[curr];
                 H[curr] = v;
                 curr = curr/2;
             }
         }
     printf("\nCurrent heap: "); disp_H(H);
     return;
}
*/
void main()
{
    int n,i,x;
    H[0] = 100;
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements: ");
    for(i=1;i<n;i++)
    {
        printf("\n");
        scanf("%d",&x);
        H[i] = x;
        r++;
        Heapify(H);
    }
    //Heapify(H);
    //printf("\nEntered Hay: ");
    //disp_H();
    printf("\nFinal heap: "); disp_H(H);
    printf("\nOpcount: %d", count);
}