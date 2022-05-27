#include<stdio.h>
#define MAX_QUEUE 100

typedef struct
{
    int key;
}element;

void Display(element *queue, int *front, int *rear)
{
    int i;
    if((*rear)!=-1)
    {
        printf("\n\n\t\t\tfront -> ");
        for(i = *front;i<(*rear);i++)
            printf("%d | ",queue[i].key);
        printf("%d <- rear\n\n",queue[i].key);
        return;
    }
    printf("\n\n\t\t\t\tQueue is empty\n\n");
}
void Delete(element *queue, int *front, int *rear)
{
    if(*front == -1 || (*front > *rear))
    {
        *front = *rear = -1;
        printf("\n\n\t\t\t\tQueue is empty\n");
        return;
    }

    printf("\n\n\t\t\t\tElement removed %d\n",queue[(*front)++].key);
    if(*front > *rear)
        *front = *rear = -1;
    return;

}
void Insert(element *queue, int *front, int *rear)
{
    if(*rear<MAX_QUEUE-1)
    {
        if(*front > *rear)       //when queue is empty
            *front = *rear = -1;
        if(*front == -1)        // first element insertion
            (*front)++;
        printf("Enter the element to entered: ");
        scanf("%d",&(queue[++(*rear)].key));
        printf("\n\n\t\t\t\tElement Entered %d\n\n",queue[(*rear)].key);
        return;
    }
    printf("Queue is full\n\n");
    return;
}
int main()
{
    element queue[MAX_QUEUE];
    printf("\n\n\n\t\t\t\t==========================\n");
    printf("\t\t\t\t\twelcome to queue\n");
    printf("\t\t\t\t==========================\n\n");

    int option,front=-1,rear=-1;

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