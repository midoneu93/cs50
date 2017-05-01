#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    bool keySuccessful = false;
    int key;
    
    do
    {
        if(argc != 2)
        {
            printf("You didn't submit a valid encryption key.\n");
            printf("Please check your input and re-run the programm.\n");
            printf("We require an integer as encryption key.\n");
            return 1;
        }
        else
        {
            key = atoi(argv[1]);
            keySuccessful = true;
        }   
    }while(!keySuccessful);
    
    printf("plaintext: ");
    string plaintext = get_string();
    
    printf("ciphertext: ");
    for(int i=0,j=strlen(plaintext); i<j; i++)
    {
        if(isalpha(plaintext[i]))
        {
            if(islower(plaintext[i]))
            {
                printf("%c", ((((plaintext[i] - 97)+key)%26)+97));
            }
            else
            {
                printf("%c", ((((plaintext[i] - 65)+key)%26)+65));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
           
    }
    printf("\n");
}