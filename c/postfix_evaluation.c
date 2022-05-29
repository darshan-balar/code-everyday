#include<stdio.h>
#define MAX_SIZE 100

int main()
{

    char expression[MAX_SIZE];
    int stack[MAX_SIZE];
    int count=0;
    int result;

    printf("\n\n\t\t\tEnter the operands of postfix expression(e.g 2 36 5 8\n");

    expression[count++] = getchar();
    while(count < MAXSIZE-1 && expression[count]!='\n')
        expression[count++] = getchar();

    if(count < MAX_SIZE-1)
        expression[count]='\0';
    else
    {
        printf("range out of bound\n");
        return 0;
    }
    result = postfix_eval(expression);

    printf("the result of %s is : %d\n",expression, result);

    return 0;

    


}