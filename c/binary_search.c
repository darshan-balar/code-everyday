#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,s) \
        if(!(p = malloc(s)))\
        { \
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE); \
        }

int main()
{
    int *list,n,left=0,right,key;

    printf("Enter the number of integers: ");
    scanf("%d",&n);
    right = n-1;

    MALLOC(list, sizeof(int)*n);

    printf("Enter %d numbers: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&list[i]);
    
    printf("Enter the key element to be searched: ");
    scanf("%d",&key);

    while(left <= right)
    {
        int middle = (left+right)/2;

        if(list[middle]==key)
        {
            printf("element found at position %d\n",middle+1);
            return 0;
        }
        else if(list[middle]<key)
            left = middle+1;
        else 
            right = middle-1;
    }

    printf("Element not found\n");
    return 0;
}