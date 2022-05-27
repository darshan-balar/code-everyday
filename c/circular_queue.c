#include<stdio.h>
#define MAX_QUEUE_SIZE 5

typedef struct 
{
    int key;
}element;


void Display(element *queue, int *front, int *rear)
{
    if(*front ==  *rear)
    {
        printf("\n\n\t\t\tQueue is empty\n\n");
        return;
    }
    printf("\n\n\t\t\tfront-> ");
    for(int i=((*front)+1) % MAX_QUEUE_SIZE; i!=(*rear) ; i = (i+1)%MAX_QUEUE_SIZE)
        printf("%d | ",queue[i].key);
    printf("%d <- rear\n\n",queue[(*rear)].key);
}
void Delete(element *queue, int *front, int *rear)
{
    if(*front == *rear)
    {
        printf("\n\n\t\t\tQueue is empty\n\n");
        return;
    }
    printf("\n\n\t\t\tElement removed %d\n\n",queue[(*front = ((*front) + 1) % MAX_QUEUE_SIZE)].key);
}
void Insert(element *queue, int *front, int *rear)
{
    if(*front == ((*rear) + 1) % MAX_QUEUE_SIZE)
    {
        printf("\n\n\t\t\t Queue is full\n\n");
        return;
    }
    printf("\n\nEnter the element: ");
    scanf("%d",&queue[(*rear = ((*rear)+1) % MAX_QUEUE_SIZE)].key);
    printf("\n\n\t\t\telement entered %d\n\n",queue[(*rear)].key);
}
int main()
{
    int front=0, rear=0,option;
    element queue[MAX_QUEUE_SIZE];

     printf("\n\n\n\t\t\t\t==========================\n");
    printf("\t\t\t\t\twelcome to queue\n");
    printf("\t\t\t\t==========================\n\n");

    while(1)
    {
        printf("1. Insert \n2. Delete\n3. Display\n4. exit\n");
        printf("choose option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1: Insert(queue, &front, &rear);
                    break;
            case 2: Delete(queue, &front, &rear);
                    break;
            case 3: Display(queue, &front, &rear);
                    break;
            case 4: return 0;
            default: printf("Enter the correct option\n");
        }
    }

}