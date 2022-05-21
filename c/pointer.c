#include<stdio.h>

int main()
{
    int i, *p;

    p = &i;
    *p = 10;

    printf("i = %d\n",i);
    printf("address of i = %p\n", p);

    return 0;
}