// how much change , minimum number of coins
//How to eat an elephant? One chunk at a time - refactored using modulo <-- prMD - the hell does this mean??..
#include <stdio.h>
#include <cs50.h>
#include <math.h>

  int main(void)
  {
    float dollars;
    do {
      dollars = get_float("Change: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100); // prMD - Variable names a bit confusing while reading it over but not horrible.

    int coins = 0;
//quarters
    coins += cents / 25; // prMD - Interesting using the % remainder. I had done it differently.

    cents = cents % 25;
//dimes
    coins += cents / 10;
    cents = cents % 10;
//nickels
    coins += cents / 5;
    cents = cents % 5;
//penniesf
    coins += cents;

    printf("%i\n", coins);} // prMD - This curly brace ending here is a little cringy but it's okay.

    //check50 cs50/2018/x/cash

    // prMD - Same thing as in mario, curly braces and loops can be dropped down to a new line for better legibility but nothing is too bad.
    // prMD - Overall, well done buddy-o. You help carry on the Mike's good name.