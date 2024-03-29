/*Write a program to sort the list of integers using heap sort with bottom up max heap
construction and analyze its time efficiency.*/
#include<stdio.h>

int H[50], f=0, r=0, count = 0;

void disp_arr();
void Heap_BU(int Q[]);
void reset();

void disp_arr()
{
    int i;
    for(i=0; i<r;i++)
        printf(" %d", H[i]);
}

void reset() //resets the queue to all NULL values
{
    for(int i=0;i<50;i++)
        H[i] = -99;
    f = 0;
    r = 0;
}
void Heap_sort(int Q[]) //bottom up approach
{
    int heap = 0,v= 0;
    int n = r; //number of elements;
    int i, k,j;
    for(i = n/2; i>-1;i--)
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
        printf("\nCurrent array: "); disp_arr(Q);
    }
    printf("\nArray after bottom up: "); disp_arr(Q);
}

void main()
{
    int n,i,x;
    reset();
    printf("\nEnter number of elements: ");
    scanf("%d",&n);
    printf("\nEnter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        H[i] = x;
        r++;
    }
    printf("\nEntered array: ");
    disp_arr();
    printf("\nConstructing heap: ");
    Heap_sort(H);
    printf("\nOpcount: %d", count);
}