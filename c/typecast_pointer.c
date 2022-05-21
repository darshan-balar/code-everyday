#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) \
        if(!(p=malloc(s)))\
        { \
            fprintf(stderr, "Insufficient memory");\
            exit(EXIT_FAILURE);\
        }\

int main()
{
    int *pi;
    float *pf;

    MALLOC(pi, sizeof(int));
    MALLOC(pf, sizeof(float));

    *pi = 5;

    printf("%d\n",*pi);

    pf = (float *) pi;

    *pf = 6.9;

    printf("%f\n",*pf);
    return 0;
}