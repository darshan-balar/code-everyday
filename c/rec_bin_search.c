#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,s)\
    if(!(p=malloc(s)))\
    {\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }


int binary_search(int *list, int left, int right, int key)
{
    int middle;

    if(left>right)
        return -1;
    else
    {
        middle = (left + right)/2;
        if(list[middle] == key)
            return middle;
        else if(list[middle]<key)
            return binary_search(list, middle+1, right, key);
        else
           return  binary_search(list, left, middle-1, key);
    }
}
int main()
{
    int n, *sorted_list,key;

    printf("Enter the number of integers: ");
    scanf("%d",&n);

    MALLOC(sorted_list, sizeof(int)*n);

    printf("Enter %d integers: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&sorted_list[i]);
    
    printf("Enter the search element: ");
    scanf("%d",&key);

    int position = binary_search(sorted_list,0,n-1,key);

    if(position!=-1)
        printf("Element is at position %d\n",position+1);
    else    
        printf("Element not found\n");
    
    return 0;
}