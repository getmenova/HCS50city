// Output a user's initials
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)//passes check50 and style50 4.17.2018
{
    char initials[4];
    string s = get_string("Name: ");//passes check50 and style50 4.17.2018
    int length = 0;
    for (int i = 0, n = strlen(s); i < n; i++)//passes check50 and style50 4.17.2018
    {
        if (isupper(s[i]))
        {
            initials[length] = s[i];//passes check50 and style50 4.17.2018
            length++;
        }
    }
    initials[length] = '\0';
    printf("%s\n", initials);
}

//passes check50 and style50 4.17.2018