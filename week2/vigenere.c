#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    bool keySuccessful = false;
    string key;
    
    do
    {
        if(argc != 2)
        {
            printf("You didn't submit a valid encryption key.\n");
            printf("Please check your input and re-run the programm.\n");
            return 1;
        }
        else
        {
            for(int i=0, j=strlen(argv[1]); i<j; i++)
            {
                if(!isalpha(argv[1][i]))
                {
                    printf("We require an alphapetical key as encryption key.\n");
                    return 1;
                }
            }
            
            key = argv[1];
            keySuccessful = true;
        }   
    }while(!keySuccessful);
    
    printf("plaintext: ");
    string plaintext = get_string();
    
    printf("ciphertext: ");
    int klen = strlen(key);
    int kfinal;
    for(int i=0, k = 0, j=strlen(plaintext); i<j; i++)
    {
        if(isalpha(plaintext[i]))
        {
            if(islower(key[k]))
            {
                kfinal = key[k] - 97;
            }
            else
            {
                kfinal = key[k] - 65;
            }
                
            if(islower(plaintext[i]))
            {
                printf("%c", ((((plaintext[i] - 97) + (kfinal)) % 26) + 97));
                k++;
                if(k == klen){k=0;}
            }
            else
            {
                printf("%c", ((((plaintext[i] - 65) + (kfinal)) % 26 ) + 65));
                k++;
                if(k == klen){k=0;}
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
           
    }
    printf("\n");
}