#include <stdio.h>
#include <cs50.h>

  int main(void) {

    int height = -1;

    while (height < 0 || height > 23) {
      printf("Enter height between 0 - 23:"); // prMD - Nice dumbass-proof prompt.
      height = get_int();
    } // prMD - Better use of comments this time.

    //iterate row times
    for (int row = 0; row < height; row++) {

      // print spaces

      for (int spaces = 0; spaces < (height - row - 1); spaces++) {
        printf(" ");
      }

      for (int hashes = 0; hashes < (row + 2); hashes++) { // prMD - Good variable names in your 'for' loops.
        printf("#");
      }

      printf("\n");
    }
  }

  // prMD - In 'while' and 'for' loops, curly brackets could be brought down to a new line for better legibility and also because C just likes that shit.
