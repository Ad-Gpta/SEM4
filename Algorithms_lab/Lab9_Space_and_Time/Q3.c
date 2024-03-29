//Write a program to construct the closed hash table. Find the number of key comparisons in successful search and unsuccessful search.
#include<stdio.h>
//V - holds values of elements to hash
//H - hash table
//n - number of elements in V
//h - hash value of element
int V[20], h,i,j,n,flag=0, count=0;
void Hash();
void disp();
int H[10]; //array of hash elements
void Hash() //Hashing all elements
{
    for(i=0;i<10;i++) //initializing hash table
        H[i] = 0;
    for(i=0;i<n;i++) //for every element in V
    {
        flag = 0; //initializing flag variable
        h = V[i] % 10;
        if(H[h] == 0) //if that value bucket is free
        {
            H[h] = V[i];
            flag = 1;
            continue;
        }
        while(flag==0) //traverse till end of linked list
        {
            if(H[h]==0)
            {
                H[h] = V[i];
                flag = 1;
            }
            else
                h = (h+1)%10; //incrementing circular list
        }
       }
}
void disp()
{
       printf("\nDisplaying hash table: ");
       for(i=0;i<10;i++) //for every number in hash table
               printf("\nHash value: %d; values: %d",i, H[i]);
}
int search(int v)
{
    h = v%10;
    flag = 0;
    while(flag==0)
    {
        count++;
        if(H[i] == v)
            return 1; //successfull search
        i = (i+1)%10; //incrementing circular list
        if(count == 10) break; //searched entire list
    }
    return 0; //unsuccessful search
}
void main()
{
       //hash function = mod 10
       printf("\nEnter number of elements: ");
       scanf("%d",&n);
       printf("\nEnter array of elements to hash (2 digit numbers only): ");
       for(i=0;i<n;i++)
               scanf("%d", &V[i]);  
       Hash();
       disp();
       for(i=0; i<2;i++)
       {
        count = 0;
       printf("\nEnter number to search: ");
       scanf("%d",&n);
       int k = search(n);
       if(k==1)
        printf("\nSuccessful search");
        else
        printf("\nUnsuccessful search");
       printf("\nOpcount: %d", count);
       }
}