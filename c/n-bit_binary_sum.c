#include<stdio.h>
#define MAX_SIZE 100

void Sum(int *A, int *B, int *C, int n)
{
    C[MAX_SIZE-1] = 0;
    for(int i=n-1;i>=0;i--)
    {
        if(C[MAX_SIZE-1] == 0)
        {
            if(A[i]==1 && B[i]==1)
            {
                C[i] = 0;
                C[MAX_SIZE-1] = 1;
            }
            else if(A[i]==0 && B[i]==1)
                C[i] = 1;
            else if(A[i]==1 && B[i]==0)
                C[i] = 1;
            else
                C[i] = 0;
        }
        else
        {
            if(A[i]==1 && B[i]==1)
            {
                C[i] = 1;
            }
            else if(A[i]==0 && B[i]==1)
                C[i] = 0;
            else if(A[i]==1 && B[i]==0)
                C[i] = 0;
            else
            {
                C[i] = 1;  
                C[MAX_SIZE-1] = 0;
            } 
        }
    }
}

int main()
{
    int n, A[MAX_SIZE], B[MAX_SIZE], C[MAX_SIZE];

    printf("Number of bits: ");
    scanf("%d",&n);

    printf("Enter the first number in space seperated binary format(e.g 1 0 1 0)\nA : ");
    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);
    printf("Enter the Second number in space seperated binary format(e.g 1 0 1 0)\nB : ");
    for(int i=0;i<n;i++)
        scanf("%d",&B[i]);

    Sum(A,B,C,n);

    printf("C : %d ",C[MAX_SIZE-1]);
    for(int i=0;i<n;i++)
        printf("%d ",C[i]);
    
    printf("\n");
    return 0;
}