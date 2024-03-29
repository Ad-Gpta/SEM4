/*Write a program to find Minimum Cost Spanning Tree of a given undirected graph
using Kruskal's algorithm and analyse its time efficiency.*/
#include<stdio.h>
int i, j,k , n , count = 0,A[5][5],TE[5][5], E[5];
//A - original adjacancy matrix
//E - nodes that have been made tree nodes
//TE - tree edges matrix; keeps track of which edges are being added
int check(int k);
void mst(int M[][5], int A[][5]);
void kruskal(int A[][5]);
void disp(int A[][5]);

void disp(int A[][5])
{
    printf("\nAdjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf(" %d ", A[i][j]);
        printf("\n");
    }
}

int check(int k) //if this node is already a tree node
{
    if(E[k] == 1) return 1;
    return 0;
}
void mst(int M[][5], int A[][5]) //minimum spanning tree
{
    int cost = 0;
    printf("\nMin spanning tree: ");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(M[i][j]) //if node exists in tree matrix (is not 0)
    {
        printf("\n%c%c: %d",(97+i),(97+j),A[i][j]);
        cost += A[i][j];
    }
    printf("\ncost of mst: %d\nopcount: %d\n", cost, count);
}
void kruskal(int A[][5])
{
    int min_w = 99, min_v = 0, from = 0;
    for(k=0;k<n;k++) //iterating till every node is a tree node
    {
        min_w = 99;
        for(i=0;i<n;i++) //for every node i
        {
            if(check(i)) // if node is a tree node
            //i.e. for every tree node:
                for(j=0;j<n;j++) //checking for minimum cost frontier node for each tree node i
                {
                    count++;
                    if(E[j]== 1) continue;
                    if(min_w>A[i][j])
                    {
                        from = i;
                        min_v = j;
                        min_w = A[i][j];
                    }
                }
        }
        printf("\nNode %c included", (97+min_v));
        E[min_v] = 1; //making min cost frontier node (out of all) as tree node
        TE[from][min_v] = 1;
    }
    for(i=0;i<n;i++) //checking if any node not included
        if(E[i] == 0)
        printf("\nNode %c not included",97+i);
    mst(TE,A);
}
void main()
{
    //n = 5;
    printf("Enter number of nodes: "); scanf("%d",&n);
    printf("\nEnter adjacency matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d", &A[i][j]);
    //int A[5][5] = { 0,5, 7, 99, 2, 5, 0, 99, 6, 3, 7, 99, 0, 4, 4, 99, 6, 4, 0, 5, 2, 3, 4, 5, 0};
    //initializing matrices
    disp(A);
    for(i=0;i<n;i++)
    {
        E[i] = 0;
        for(j=0;j<n;j++)
            TE[i][j] = 0;
    }
    E[0] = 1; //first tree node (starting from here)
    kruskal(A);
}