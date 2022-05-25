#include<stdio.h>

#define MAX_TERMS 101

typedef struct
{
    int col;
    int row;
    int value;
}term;

int main()
{
    term a[MAX_TERMS];
    int n,max_rows, max_cols;
    printf("Enter the number of non-zero values: ");
    scanf("%d",&a[0].value);
    printf("Enter the max columns: ");
    scanf("%d",&a[0].col);
    printf("Enter the max rows: ");
    scanf("%d",&a[0].row);


    printf("Enter the row, col, and value of non zero matrix: \n");
    printf("Maintain the ascending order \n");

    for(int i=1;i<=a[0].value;i++)
    {
        printf("Enter the row number of element %d : ",i);
        scanf("%d",&a[i].row);
        printf("Enter the col number of element %d : ",i);
        scanf("%d",&a[i].col);
        printf("Enter the value of element %d : ",i);
        scanf("%d",&a[i].value);
    }
        printf("The matrix is : \n");

        int x=1;
        for(int i=0;i<a[0].row;i++)
        {
            for(int j=0;j<a[0].col;j++)
            {
                if(a[x].row == i && a[x].col == j)
                {
                    printf("%d ",a[x].value);
                    x++;
                }
                else
                    printf("0 ");
            }
            printf("\n");
        }
}