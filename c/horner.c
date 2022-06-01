// polynomial evaluation
#include<stdio.h>
#define MAX_SIZE 100

int horners(int *elements, int x, int n)
{
    int p = 0;
    for(int i=n-1;i>=0;i--)
        p = elements[i] + x*p;
    return p;
}

int main()
{
    int elements[MAX_SIZE];
    int n,x;

    printf("Enter the number of coefficients: ");
    scanf("%d",&n);
    printf("Enter the %d coefficients: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&elements[i]);

    printf("Enter the value of x: ");
    scanf("%d",&x);
    
    int p = horners(elements, x, n);

    printf("polynomial evaluation: %d\n",p);
    return 0;
}