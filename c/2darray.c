#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,s)\
    if(!(p=malloc(s)))\
    {\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

int main()
{
    int **twoDarray,m,n;

    printf("m,n: ");
    scanf("%d%d",&m,&n);

    MALLOC(twoDarray, sizeof(*twoDarray)*m);

    for(int i=0;i<m;i++)
        MALLOC((*(twoDarray+i)) , sizeof(**twoDarray)*n);
    
    printf("Enter the values of %d,%d: \n",m,n);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d", (*(twoDarray+i) + j));
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ", (*(*(twoDarray+i) + j)));
        printf("\n");
    }
    return 0;

}