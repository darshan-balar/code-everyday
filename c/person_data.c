#include<stdio.h>
#include<string.h>


typedef struct
{
    int day;
    int month;
    int year;
}date;


typedef struct 
{
    char name[10];
    int age;
    int salary;
    date dob;
}human;


int main()
{
    human person1, person2;

    strcpy(person1.name, "darshan");
    person1.age = 24;
    person1.salary = 1000;
    person1.dob.day = 15;
    person1.dob.month = 07;
    person1.dob.year = 1998;


    person2 = person1;

    printf("%s\n",person2.name);
    printf("%d\n",person2.age);
    printf("%d\n",person2.salary);
    printf("dob: %d-%d-%d\n",person2.dob.day,person2.dob.month,person2.dob.year);


    return 0;
}
