#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main()
{
    string name = get_string();
    if(!isspace(name[0]))
    {
        printf("%c",toupper(name[0]));
    }
    
    for(int i=0,j=strlen(name); i<j; i++)
    {
        if(isspace(name[i]) && !isspace(name[i+1]) && i!=(j-1))
        {
            printf("%c",toupper(name[i+1]));
        }
    }
    printf("\n");
}