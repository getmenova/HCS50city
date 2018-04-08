#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int i, n;
int main(int argc, string argv[])
{
    if (argc!=2)
        {
            printf("Enter program name and KEY #!\n");
            return 1;
        }

    int k = atoi(argv[1]);

    string s = get_string("input:  "); // from codealong example

     printf("ciphertext: ");
    for(i=0, n=strlen(s);n>i;i++)
        {
        if (isalpha (s[i])) // is this letter in Alphabet set?
            {
            if (isupper(s[i])) // uppercasee
            {
            printf("%c", ((s[i]-'A'+k)%26)+'A');
            }
            if  (islower(s[i])) //lowercase
            {
            printf("%c", ((s[i]-'a'+k)%26)+'a');
            }
            }
        else
            {
             printf("%c", s[i]);
            }
        }
        printf("\n");

}