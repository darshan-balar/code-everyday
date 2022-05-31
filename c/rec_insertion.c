#include<stdio.h>
#define MAX_SIZE 100

void sort(int *elements, int n)
{
    if(n==1)
        return;
    else
    {
        sort(elements, n-1);
        int i,key;
        key = elements[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(key > elements[i])
                break;
            else
                elements[i+1]=elements[i];
        }

        elements[i+1] = key;
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
    
    sort(elements,n);

    printf("Sorted elements: ");
    for(int i=0;i<n;i++)
        printf("%d ",elements[i]);
    printf("\n");

    return 0;
}