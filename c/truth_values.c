#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p,s)\
    if(!(p=malloc(s)))\
    {\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }

void truthvalues(char *truth_values,int n,int i)
{
    if(i==n)
    {
        truth_values[i]='\0';
        printf("%s\n",truth_values);
        return;
    }
    else
    {
        truth_values[i]='T';
        truthvalues(truth_values, n, i+1);
        truth_values[i] = 'F';
        truthvalues(truth_values,n,i+1);
    }
}

int main()
{
    int n;
    char *truth_values;
    printf("Enter the number of boolean variables: ");
    scanf("%d",&n);

    MALLOC(truth_values, sizeof(char)*(n+1));

    printf("Truth table: \n");

    truthvalues(truth_values,n,0);

    return 0;
}