/*Write a program to implement 
Floyd’s algorithm for the All-Pairs- Shortest-Paths
problem for any given graph and analyse its time efficiency. Obtain the experimental results for order of growth and plot the result.*/

#include<stdio.h>

int n,i,j,k, count=0;

void disp(int A[][10]);
void Floyd(int A[][10]);
int min(int a, int b);

void main()
{
    printf("\nEnter size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter adjacency list (999 for infinity): \n");
    int A[10][10];
    for(i = 0; i < n; i++)
        for (j= 0; j < n; j++)
            scanf("%d",&A[i][j]);
    printf("\nEntered adjacency list: \n");
    disp(A);
    printf("\nImplementing Floyd's algo: ");
    Floyd(A);
    printf("\nFinal matrix:\n");
    disp(A);
    printf("\nOpcount: %d\n", count);
}

void disp(int A[][10])
{
    for(i = 0; i < n; i++)
    {
        for (j= 0; j < n; j++)
            printf(" %d ",A[i][j]);
        printf("\n");
    }
}
int min(int a, int b)
{
    if (a>b)
        return b;
    return a;
}
void Floyd(int A[][10])
{
    int new=0;
    for(k=0;k<n;k++)
    {
        printf("\nComputing D%d :",k);
        for(i = 0; i < n; i++) //row
            for (j= 0; j < n; j++) //col
            {
                count++;
                new = min(A[i][j] , A[k][j]+A[i][k]); //col[i]*row[j]; //row i and col j when looking at matrix
                //if(new<999) //if new is not 0
                A[i][j] = new;
            }
        printf("\nD%d : \n",k);
        disp(A);
    }
}