#include<stdio.h>
#include<stdlib.h>

#define  MALLOC(p,s) \
    if(!(p = malloc(s))) \
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
    *pf = 5.5;

    printf("integer value: %d\n",*pi);
    printf("float value: %f\n",*pf);

    return 0;


}