// section sort with dynamic memory allocation

#include<stdio.h>
#include<stdlib.h>

//allocating heap space
#define MALLOC(p,s) \
        if(!(p = malloc(s)))\
        { \
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE); \
        }

void swap(int *a, int *b)      // swapping inplace
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int *list,n,min;

    printf("Enter the number of integers: ");
    scanf("%d",&n);

    MALLOC(list, sizeof(int)*n); 

    printf("Enter %d integers: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&list[i]);

    for(int i=0;i<n-1;i++)    // finding the min in unsorted and adding to sorted list
    {
        min = i;
        for(int j=i+1;j<n;j++) // comparing with each element
        {
            if(list[j]<list[min])   // if found then replace min index   
                min = j;         
        }
        if(i != min)             // if min is not the current element
            swap(&list[i],&list[min]);    //swap it with current
    }

    printf("Sorted list: ");
    for(int i=0;i<n;i++)
        printf("%d ",list[i]);
    
    printf("\n");
    return 0;
}