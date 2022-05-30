#include<stdio.h>
#define MAX_SIZE 100


void sort(int *elements, int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;

        for(int j=i+1;j<n;j++)
        {
            if(elements[min]>elements[j])
                min = j;
        }

        if(i!=min)
        {
            int temp = elements[i];
            elements[i] = elements[min];
            elements[min] = temp;
        }
    }
}

int main()
{
    int n;
    int elements[MAX_SIZE];

    printf("Enter the number of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&elements[i]);
    
    sort(elements, n);

    printf("Sorted elements: ");
    for(int i=0;i<n;i++)
        printf("%d ",elements[i]);
    printf("\n");

    return 0;
}