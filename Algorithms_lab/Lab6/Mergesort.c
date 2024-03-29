#include<stdio.h>
int count = 0;
int i, j, k;
int* init_arr(int* A, int n);
void disp(int A[], int n);
void merge(int A[], int al, int B[], int bl, int C[], int cl);
void mergesort(int A[], int n);

int* init_arr(int* A, int n)
{
    printf("\nEnter array elements: ");
    for(i=0;i<n;i++)
        scanf("%d", &A[i]);
    return A;
}

void disp(int A[], int n)
{
    for(i=0;i<n;i++)
        printf(" %d", A[i]);
}

void merge(int A[], int al, int B[], int bl, int C[], int cl)
{ 
    printf("\nInside merge algo");
    int b, c;
    while(i<bl && j<cl)
    {
        b = B[i];
        c = C[i];
        if(b<=c)
        {
            A[k] = b;
            i++;
        }
        else
        {
            A[k] = c; j++;
        }
        k++;
    }
    if(j==cl) //entering remaining values of B
    {
        for(int p = i; p<bl; p++)
        {
            A[k] = B[p];
            k++;
        }
    }
    else{
        for(int p = j; p<cl; p++)
        {
            A[k] = C[p];
            k++;
        }
    }
    printf("\nSorted array: "); disp(A, al);
}
void mergesort(int A[], int n)
{
    printf("\nInside mergesort algo");
    if(n>1)
    {
        count++;
        int n, m = n/2;
        int B[m], C[m+1];
        for(i=0;i<m;i++)
        {
            B[i] = A[i];
        }
        for(i=m;i<n;i++)
        {
            C[i-m] = A[i];
        }
        mergesort(B,m);
        mergesort(C, m+1);
        merge(A,n,B,m,C,m+1);
    }
}
void main()
{
    int n;
    printf("\nEnter size of A: ");
    scanf("%d", &n);
    int A[n];
    int* a = &A[0];
    a = init_arr(a, n);
    printf("\nArray A: "); disp(A,n);
    mergesort(A,n);
    printf("\nOpcount: %d", count);
}