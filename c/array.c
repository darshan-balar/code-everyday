#include<stdio.h>
#define MAX_SIZE 100

int cal_sum(int *, int);
void printlist(int *, int);

int main(void)
{
    int input[MAX_SIZE], sum=0,n;

    printf("Enter the number of integers: ");
    scanf("%d",&n);

    printf("Enter %d integers: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&input[i]);

    printlist(input, n);
    sum = cal_sum(input, n);

    printf("Sum of given integers is : %d\n", sum);

    return 0;
}

int cal_sum(int *list, int n)
{
    int temp = 0;

    for(int i=0;i<n;i++)
        temp += list[i];

    return temp;
}

void printlist(int *list, int n)
{
    printf("address --- value\n");
    for(int i=0;i<n;i++)
        printf("%p --- %d \n", list+i , *(list+i));
    
    return;
}