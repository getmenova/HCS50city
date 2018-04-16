#include<stdio.h>
#include<cs50.h>
int main(void){printf("Minutes: ");int min=get_int();int bottle=min*12;printf("Bottles: %i\n",bottle);}

//3 lines required to compile w/o errors
//can compact to single line and still pass style50
//won't pass check50 w/o compiling, therefore 3 lines is the smallest we can get it down to ;( )
//check to see if each lib included requires its own line!