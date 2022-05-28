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
element *queue;
int capacity = 3;
void queuefull(int *front, int *rear)
{
    element *newqueue;
    int i=0,j=0;

    MALLOC(newqueue, sizeof(*newqueue)*capacity*2);

    for(i=((*front)+1)%capacity,j=0; i!=(*rear); i = (i + 1)%capacity,j++)
        newqueue[j] = queue[i];
    newqueue[j]=queue[i];
    capacity = capacity*2;
    (*rear) = j;
    (*front) = capacity-1;
    free(queue);
    queue = newqueue;
}
void Display(int *front, int *rear)
{
        printf("front : %d rear %d\n", *front, *rear);

    if(*front ==  *rear)
    {
        printf("\n\n\t\t\tQueue is empty\n\n");
        return;
    }
    printf("\n\n\t\t\tfront-> ");
    for(int i=((*front)+1) % capacity; i!=(*rear) ; i = (i+1)%capacity)
        printf("%d | ",queue[i].key);
    printf("%d <- rear\n\n",queue[(*rear)].key);
}

void Delete(int *front, int *rear)
{
       if(*front == *rear)
    {
        printf("\n\n\t\t\tQueue is empty\n\n");
        return;
    }
    printf("\n\n\t\t\tElement removed %d\n\n",queue[(*front = ((*front) + 1) % capacity)].key);
}
void Insert(int *front, int *rear)
{
    if(*front == ((*rear) + 1) % capacity)
        queuefull(front, rear);
    printf("\n\nEnter the element: ");
    scanf("%d",&queue[(*rear = ((*rear)+1) % capacity)].key);
    printf("\n\n\t\t\telement entered %d\n\n",queue[(*rear)].key);
}
int main()
{
    int front = 0, rear = 0,option;

    printf("\n\n\n\t\t\t\t==========================\n");
    printf("\t\t\t\t\twelcome to queue\n");
    printf("\t\t\t\t==========================\n\n");

    MALLOC(queue, sizeof(*queue)*capacity);

    while(1)
    {
        printf("1. Insert \n2. Delete\n3. Display\n4. exit\n");
        printf("choose option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: Insert(&front, &rear);
                    break;
            case 2: Delete(&front, &rear);
                    break;
            case 3: Display(&front, &rear);
                    break;
            case 4: return 0;
            default: printf("Enter the correct option\n");
        }
    }

}