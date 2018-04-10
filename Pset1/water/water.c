#include <stdio.h>
#include <cs50.h>

  int main(void) {
    printf("Minutes: "); // prMD - Code is a bit squished but the shit works.
    int min = get_int(); // prMD - Legible, understand variables, solid.
    int bottle = min * 12;
    printf("Bottles: %i\n", bottle);
  }