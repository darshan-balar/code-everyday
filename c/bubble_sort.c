#include<stdio.h>
#define MAX_SIZE 100


void swap(int *a, int *b)      // swapping inplace
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *elements, int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>=i+1;j--)
        {
            if(elements[j]<elements[j-1])
                swap(&elements[j],&elements[j-1]);
        }
    }
}

int main()
{
    int elements[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter the %d elements to be sorted: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&elements[i]);
    
    sort(elements, n);

    printf("Sorted elements: ");
    for(int i=0;i<n;i++)
        printf("%d ",elements[i]);
    printf("\n");
    return 0;
}