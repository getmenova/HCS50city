#include <stdio.h>
#include <cs50.h>

  int main(void) {
    long long i, add, mult;
    int addsum, multresult, finalsum;

    do {
      printf("Enter your CC number:\n");
      i = GetLongLong();
    }
    while (i < 0);

    // sum every other digit starting w/ the the last
    for (xadd = i, addsum = 0; xadd > 0; xadd /= 100)
      addsum += xadd % 10;

    // 2x binary digits - start 1 before final
    // then sum the individual digits of these products
    for (x2 = i / 10, multresult = 0; x2 > 0; x2 /= 100) {
      if (2 * (x2 % 10) > 9) {
        multresult += (2 * (x2 % 10)) / 10;
        multresult += (2 * (x2 % 10)) % 10;
      } else
        multresult += 2 * (x2 % 10);
    }

    sum = addsum + multresult;

    // check to see if the CC number within range
    if (sum % 10 == 0) {
      if ((i >= 340000000000000 && i < 350000000000000) || (i >= 370000000000000 && i < 380000000000000))
        printf("AMERICAN EXPRESS\n");
      else if (i >= 5100000000000000 && i < 5600000000000000)
        printf("MASTERCARD\n");
      else if ((i >= 4000000000000 && i < 5000000000000) || (i >= 4000000000000000 && i < 5000000000000000))
        printf("VISA\n");
      else
        printf("NO MATCH\n");
    } else
      printf("NO MATCH\n");

    return 0;
  }

  /*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$,,,$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$"OOO"$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$!OOO!$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$,"OOO",$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$,"OOOOOOO",$$$$$$$$$$$$$
$$$$$$$$$$$$!"OOOOOOOOOOO"!$$$$$$$$$$$
$$$$$$$$$$,"OOOOOOOOOOOOOOO",$$$$$$$$$
$$$$$$$$,1OOOOOOOOOOOOOOOOOOO7,$$$$$$$
$$$$$$,!OOOOOOOOOOOOOOOOOOOOOO"$$$$$$$
$$$$$$!OOOOOOOOO/""""'\OOOOOOOO1$$$$$$
$$$$$$"OOOOOOOOOO"$$$$!OOOOOOOO"$$$$$$
$$$$$$"OOOOOOOOOOO!$$$",OOOOOOO!$$$$$$
$$$$$$$",OOOOOOOOOO",$$$"""""""$$$$$$$
$$$$$$$$"!OOOOOOOOOOO",$$$$$$$$$$$$$$$
$$$$$$$$$$",OOOOOOOOOOO",$$$$$$$$$$$$$
$$$$$$$$$$$$"OOOOOOOOOOOO",$$$$$$$$$$$
$$$$$$$$$$$$$"!OOOOOOOOOOOO"+$$$$$$$$$
$$$$$$$$$$$$$$$"==OOOOOOOOOOO,$$$$$$$$
$$$$$$$$,,,,,,$$$$",OOOOOOOOOO",$$$$$$
$$$$$$,"OOOOOO',$$$$",OOOOOOOOO!$$$$$$
$$$$$$1OOOOOOOO."~~~"OOOOOOOOOO!$$$$$$
$$$$$$!OOOOOOOOOOOOOOOOOOOOOOO1$$$$$$$
$$$$$$",OOOOOOOOOOOOOOOOOOOOO,"$$$$$$$
$$$$$$$",OOOOOOOOOOOOOOOOOOO!$$$$$$$$$
$$$$$$$$$1OOOOOOOOOOOOOOOO,1$$$$$$$$$$
$$$$$$$$$$"~~,OOOOOOOOOO,"$$$$$$$$$$$$
$$$$$$$$$$$$$$"""1OOO1"'$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$!OOO!$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$,OOO,$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$"""$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/