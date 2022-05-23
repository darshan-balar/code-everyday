#include<stdio.h>
#include<stdlib.h>


#define MALLOC(p,s) \
        if(!(p = malloc(s)))\
        { \
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE); \
        }


int count=0;

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void perm(char *string, int i, int n)
{
    if(i==n)
    {
        printf("%s\n",string);
        count++;
    }
    for(int j=i;j<n;j++)
    {
        swap(&string[i],&string[j]);
        perm(string, i+1, n);
        swap(&string[i], &string[j]);
    }
}

int main()
{
    int n,i=0;
    char *string,c;
    printf("Enter the number of chars: ");
    scanf("%d",&n);

    MALLOC(string, sizeof(char)*(n+1));

    printf("Enter the string: ");
    c=getchar();
    while((c=getchar())!='\n')
        string[i++] = c;
    string[i]='\0';

    perm(string,0,n);

    printf("total %d strings\n", count);

    return 0;

}