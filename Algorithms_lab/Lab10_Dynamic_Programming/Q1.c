/*Write a program to compute the transitive closure of a given directed graph using
Warshall’s algorithm 
and analyse its time efficiency. Obtain the experimental results for order of growth and plot the result.*/
#include<stdio.h>
int n,i,j,k, count=0;
void disp(int A[][10]);
void Warshall(int A[][10]);
void main()
{
    printf("\nEnter size of matrix: ");
    scanf("%d",&n);
    printf("\nEnter adjacency list: \n");
    int A[10][10];
    for(i = 0; i < n; i++)
        for (j= 0; j < n; j++)
            scanf("%d",&A[i][j]);
    printf("\nEntered adjacency list: \n");
    disp(A);
    printf("\nImplementing Warshall's algo: ");
    Warshall(A);
    printf("\nFinal matrix: ");
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
void Warshall(int A[][10])
{
    int new=0;
    for(k=0;k<n;k++)
    {
        printf("\nComputing R%d :",k);
        for(i = 0; i < n; i++) //row
            for (j= 0; j < n; j++) //col
            {
                count++;
                new = A[i][j] + A[k][j]*A[i][k]; //col[i]*row[j]; //row i and col j when looking at matrix
                if(new>0) //if new is not 0
                    A[i][j] = 1;
            }
        printf("\nR%d : \n",k);
        disp(A);
    }
}