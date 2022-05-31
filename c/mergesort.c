#include<stdio.h>
#define MAX_SIZE 100

void Merge(int *elements, int p, int q, int r)
{
    int left_length = q-p+1;
    int right_length = r-q;
    int left[left_length];
    int right[right_length];

    for(int i=0;i<left_length;i++)
        left[i] = elements[p+i];
    for(int i=0;i<right_length;i++)
        right[i] = elements[q+1+i];
    
    int i=0,j=0,k=p;

    while(i<left_length && j < right_length)
        if(left[i]<=right[j])
            elements[k++]=left[i++];
        else
            elements[k++] = right[j++];
    
    while(i<left_length)
        elements[k++]=left[i++];
    while(j<right_length)
        elements[k++]=right[j++];

}

void sort(int *elements, int p, int r)
{
    if(p>=r)
        return;
    
    int q = (p+r)/2;
    sort(elements, p, q);
    sort(elements, q+1, r);
    Merge(elements, p,q,r);
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
    
    sort(elements, 0, n-1);

    printf("Sorted elements: ");
    for(int i=0;i<n;i++)
        printf("%d ",elements[i]);
    printf("\n");

    return 0;
}