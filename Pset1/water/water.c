#include<stdio.h>
#include<cs50.h>
int main(void)
{
    printf("Minutes: ");
    int min = get_int();
    int bottle = min * 12;
    printf("Bottles: %i\n", bottle);

}
//forced to stylize 5x number of lines and add whitespace to satisfy style50
//doesn't matter in C (reads by char) but waste not want not.

//passes style50 and check50 4.17.2018