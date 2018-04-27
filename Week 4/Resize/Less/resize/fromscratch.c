#include "bmp.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 4) //input 4
    {
        printf("Please input in the following form: 'resize input output'\n");
        return 1;
    }


    for (int i = 0, len = strlen(argv[1]); i < len; i++) // filter input for ints only
    {
        if (!isdigit(argv[1][i])) //

            printf("Please enter an integer in the form of (n)\n"); //
            return 1;
        }
    }