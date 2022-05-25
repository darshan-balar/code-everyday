#include<stdio.h>

#define MAX_SIZE 1

typedef struct
{
    int key;
}element;

int Isempty(int *top)
{
    if((*top)+1 <= MAX_SIZE-1)
        return 1;
    return 0;
}

void Display(element *stack, int *top)
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
void Pop(element *stack, int *top)
{
    if((*top)==-1)
    {
        printf("\n\nStack is empty\n\n");
        return;
    }
    printf("\n\n\t\t\telement %d removed\n",stack[(*top)--].key);
}
void Push(element *stack, int *top)
{
    if(Isempty(top))
    {
        printf("\n\nEnter the element to be pushed: ");
        scanf("%d",&(stack[++(*top)].key));
        printf("\n\nElement %d pushed\n\n",stack[(*top)].key);
        return;
    }
    printf("\n\n\t\t\tStack is full\n");
}


int main()
{
    element stack[MAX_SIZE];
    int option,c;
    int top=-1;

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
            case 1: Push(stack, &top);
                    break;
            case 2: Pop(stack, &top);
                    break;
            case 3: Display(stack, &top);
                    break;
            case 4: return 0;
            default : printf("Enter the correct option\n");
        }
    }
    return 0;
}