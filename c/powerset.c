#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,s) \
        if(!(p = malloc(s)))\
        { \
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE); \
        }

void swap(char *a, char *b)      // swapping inplace
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void powerset(char *set,int n,int i,int j)
{
    if(i>n-1)
        return;
    else
    {
        for(int x=0;x<i;x++)
            printf("%c ",set[x]);
        printf("\n");
        
        for(j=i;j<n;j++)
            powerset(set, n, i+1,j);
        
    }


}

int main()
{
    int n,i;
    char *set;

    printf("Enter the number of elements in a set: ");
    scanf("%d",&n);

    MALLOC(set, sizeof(char)*(n+1));

    printf("Enter %d elements of a set: ",n);
        scanf("%s",set);
        
    powerset(set,n,0,0);

    return 0;
}