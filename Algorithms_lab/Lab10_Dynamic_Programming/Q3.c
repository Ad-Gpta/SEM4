/*Write a program to implement 
0/1 Knapsack problem using bottom-up dynamic programming*/

#include<stdio.h>

int n,i,j,k, count=0,W, A[10][10];

void Knapsack_BU(int A[][10], int v[], int w[]);
int max(int a, int b);
void disp(int A[][10]);

void main()
{
    printf("\nEnter max weight: ");
    scanf("%d",&W);
    printf("\nEnter number of items: ");
    scanf("%d",&n);
    printf("\nEnter weights: \n");
    int w[n];
    for(i = 0; i < n; i++)
        scanf("%d",&w[i]);
    printf("\nEnter values: \n");
    int v[n];
    for(i = 0; i < n; i++)
        scanf("%d",&v[i]);
    printf("\nImplementing Knapsack_BU's algo: ");
    Knapsack_BU(A, v, w);
    printf("\nOpcount: %d\n", count);
}
void disp(int A[][10])
{
    for(i = 0; i < n+1; i++) //rows
    {
        for (j= 0; j < W+1; j++) //columns
            printf(" %d ",A[i][j]);
        printf("\n");
    }
}
int max(int a, int b)
{
    if (a<b)
        return b;
    return a;
}
void Knapsack_BU(int A[][10], int v[], int w[])
{
    //initializing matrix
    for(i = 0; i < n+1; i++) //rows 
        for (j= 0; j < W+1; j++) //columns
            A[i][j]=0;
    int k=0;
    //entering values in matrix
    for(i = 1; i < n+1; i++) //rows 
        for (j= 1; j < W+1; j++) //columns
        {
            count++;
            k = j- w[i-1]; //weight index starts from 0; so weight of element 4 = w[3]
            if(k >= 0)
                A[i][j] = max(A[i-1][j], v[i-1] + A[i-1][k]);
            else
                A[i][j] = A[i-1][j];
        }
    printf("\nFinal matrix : \n");
    disp(A);
    int final[n];
    for(i=0;i<n;i++)
        final[i] = 0; //initializing knapsack (containing items)
    //Finding elements in knapsack:
    j = W+1;
    i = n+1;
    while(i>0)
        {
            if(A[i][j] != A[i-1][j]) //if element != element above
            {
                final[i-1] = 1;
                j = j - w[i-1];
            }
            else
                j = j-1;
            i = i-1;
            if(j <= 0) break;
        }
    printf("\nFinal elements in knapsack: ");
    int sum_v = 0, sum_w = 0;
    for(i=0;i<n;i++)
    {
        if(final[i])
        {
            printf(" I%d,", i+1);
            sum_v += v[i];
            sum_w += w[i];
        }
    }
    printf("\nTotal weight: %d\nTotal value: %d\n", sum_w, sum_v);
}