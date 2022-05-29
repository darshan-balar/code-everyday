#include<stdio.h>
#define MAX_SIZE 100


void sort(int *elements, int n)
{
    for(int i=1;i<n;i++)
    {
        int key = elements[i];
        int j;
        for(j=i-1;j>=0 && key>=elements[j];j--)
            elements[j+1] = elements[j];   
        elements[j+1] = key;
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