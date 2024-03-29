/*Write a program to construct the Open hash table. Find the number of key
comparisons in successful search and unsuccessful search. This should be done by
varying the load factor of the hash table. You may consider varying the number of
keys for a fixed value of hash table size say m=10 and n=50, 100, and 200. This
should be repeated for at least four different hash table sizes say m= 20, m=50.*/
#include<stdio.h>
#include<stdlib.h>
//V - holds values of elements to hash
//H - hash table
//n - number of elements in V
//h - hash value of element
int V[20], h,i,j,n, count=0;
void Hash();
void disp();
typedef struct values //linked list for values
{
       int val;
       struct values* next;
}list;
list* newnode(int v)
{
       list* t = (list*)malloc(sizeof(list));
       t->val = v;
       t->next = NULL;
       return t;
}
list* H[10]; //ragged array of hash elements
void Hash() //Hashing all elements
{
       list* t = NULL; //current node
       for(i=0;i<n;i++) //for every element in V
       {
               h = V[i] % 10;
               t = H[h]; //t is first node of hash value in hash table
               printf("\nHash value: %d : ",h);
               if(H[h] == NULL)
               {
                       printf("\nentering first val\n");
                       H[h] = newnode(V[i]);
                       continue;
               }
               while(t->next != NULL) //traverse till end of linked list
               {
                       printf("-> %d",t->val);
                       t = t->next;  
               }
               t->next= newnode(V[i]);
       }
}
void disp()
{
       printf("\nDisplaying hash table: ");
       for(i=0;i<10;i++) //for every number in hash table
       {
               list* t = H[i];
               printf("\nHash value: %d; values: ", i);
               while(t!= NULL)
               {
                       printf(" %d,", t->val);
                       t = t->next;
               }
       }
       printf("\n");
}
int search(int v)
{
    h = v%10;
    list* t = H[h];
    printf("%d", t->val);
    while(t)
    {
        count++;
        if(t->val == v)
            return 1; //successfull search
        t = t->next;
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