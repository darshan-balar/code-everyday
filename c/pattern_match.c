#include<stdio.h>
#include<string.h>
#define MAX_CHARS 100



int match(char *string, char *pattern)
{
    int endpoint = strlen(pattern)-1;
    int string_length = strlen(string);
    int lastp = endpoint;
    int start = 0,j;

    for(int i=0; endpoint < string_length; endpoint++,start++)
    {
        if(string[endpoint] == pattern[lastp])
            for(j=0,i=start;j<lastp && string[i]==pattern[j];j++,i++);
        
        if(j==lastp)
            return start+1;
    }
    return 0;
}

int main()
{
    char string[MAX_CHARS],pattern[MAX_CHARS];
    printf("Enter the string: ");
    scanf("%s",string);

    printf("Enter the pattern: ");
    scanf("%s",pattern);

    int position = match(string,pattern);

    if(position)
    {
        printf("Matching string starts at position %d\n",position);
        return 0;
    }
    printf("Not found\n");
    return 0;

}