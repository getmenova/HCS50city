#include <stdio.h>
#include <cs50.h>

  int main(void) {

    int height = -1;

    while (height < 0 || height > 23) {
      printf("Enter height between 0 - 23:");
      height = get_int();
    }

    //iterate row times
    for (int row = 0; row < height; row++) {

      // print spaces

      for (int spaces = 0; spaces < (height - row - 1); spaces++) {
        printf(" ");
      }

      for (int hashes = 0; hashes < (row + 2); hashes++) {
        printf("#");
      }

      printf("\n");
    }
  }