#include<stdio.h>
#include<stdlib.h>
#define  MALLOC(p,s)\
    if(!(p=malloc(s)))\
    {\
        fprintf(stderr, "Insufficient memory");\
        exit(EXIT_FAILURE);\
    }


typedef struct
{
    int key;
}element;

element *stack;
int Isfull(int *top, int *capacity)
{
    if((*top)+1 > (*capacity))
    {
        element *p = stack;
        if(!( p = realloc(p,sizeof(*stack)*(*capacity)*2)))
        {  
            fprintf(stderr, "Insufficient memory");
            return 1; 
        }
        stack = p;
        (*capacity) *= 2;
    }
    return 0;

}

void Display(int *top)
{
    if((*top) == -1)
    {   
        printf("\n\n\n\t\t\tNo elements\n\n");
        return;
    }

    printf("\n\n\t\t\tstack:");
    for(int i=0;i<(*top);i++)
        printf("%d->",stack[i].key);
    printf("%d\n",stack[*top].key);

}
void Pop(int *top)
{
    if((*top)==-1)
    {
        printf("\n\nStack is empty\n\n");
        return;
    }
    printf("\n\n\t\t\telement %d removed\n",stack[(*top)--].key);
}
void Push(int *top, int *capacity)
{
    if(Isfull(top,capacity))
        return;
    printf("Enter the element: ");
    scanf("%d",&(stack[++(*top)].key));

    printf("Element %d pushed\n",stack[(*top)].key);
    return;
}
int main()
{
    MALLOC(stack, sizeof(*stack));
    int capacity = 1;
    int top = -1;
    int option;

    printf("\t\t\t\t==================================\n");
    printf("\t\t\t\t        welcome to stack \n");
    printf("\t\t\t\t==================================\n");
    
    while(1)
    {
        printf("\nOperations: \n");
        printf("1.Push\n2.Pop\n3.Display\n4.exit\n");
        printf("Choose any one operation: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: Push(&top, &capacity);
                    break;
            case 2: Pop(&top);
                    break;
            case 3: Display(&top);
                    break;
            case 4: return 0;
            default : printf("Enter the correct option\n");
        }
    }
    return 0;
}