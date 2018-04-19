//(Emiton) Great program. It was a good idea making the key upper case so that you would only need one case for it

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //(Emiton) If someone enters a blank space, will that count as an arg?
    if (argc != 2 || strlen(argv[1]) == 0) // Exactly 2 args
    {
        printf("Usage: ./vigenere k\n");
        return 1;
    }
    string k = argv[1]; // Is string key valid??
    int klength = strlen(k);
    for (int i = 0; i < klength; i++)
    {
        if (!isalpha(k[i]))  // Is string key within alphabetical range??
        {
            printf("invalid k\n");
            return 1;
        }
        //(Emiton) Great idea making sure the key is all uppercase, much more simple
        k[i] = toupper(k[i]); // ucase conversion
    }
    string plaintext = get_string("plaintext: "); //grab user input
    printf("ciphertext: ");
    int index = 0;
    for (int i = 0, n = strlen(plaintext); i < n; i++) //scramble mah eggs
    {
        if (isalpha(plaintext[i]))
        {
            int key = k[index] - 'A';
            if (isupper(plaintext[i])) //support for upper case
            {
                printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
            }

            else // if it's not upper it's lower....
            {
                printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
            }

            index = (index + 1) % klength; // kick/push k
        }
        else
        {
            printf("%c", plaintext[i]); //for all others
        }
    }
    printf("\n");
}


//passes check50 and style50 4.17.2018