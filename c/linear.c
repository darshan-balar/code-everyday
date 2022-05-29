#include<stdio.h>
#define MAX_SIZE 100

int linear_search(int *elements, int n , int key)
{
    for(int i=0;i<n;i++)
        if(elements[i]==key)
            return i+1;
    return -1;
}


int main()
{
    int elements[MAX_SIZE];
    int n,key;

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&elements[i]);

    printf("Enter the search elements: ");
    scanf("%d",&key);

    int position = linear_search(elements,n,key);
    
    if(position == -1)
        printf("element no found\n");
    else    
        printf("element found at position %d\n",position);
    
    return 0;

}