// Encrypts user-supplied text using a Caesar cipher.


#include < stdio.h > #include < cs50.h > #include < string.h > #include < ctype.h >

  int main(int argc, string argc[]) {
    bool yes = false // set up on/off switch for runnning our LOOP
    int k = 0;
    int length = 0;
    string text = "";

    // prompt for input

    do {

      if (argc != 2) // argc = 2 when run with 1 cl arg
      {
        printf("Invalid Value!\n");
        return 1;
      } else //convert strng to int
      {
        int k = atoi(argv[1]); //walkthrough TIP! converts to int
        yes = true;
      }

    } while (!yes); // check T/F logic
    text = GetString();
    length = strlen(text); //strlen from LECTURE
    for (int i = 0; i < length; i++) {
      // Handle uppercase characters
      if (isalpha(text[i])) // are letters in alphabet??
      {
        if (islower(text[i])) // provides case sensitive support
        {
          printf("%c", ((((text[i] - 97 + key) % 26) + 97)));
        } else {
          printf("%c", ((((text[i] - 65 + key) % 26) + 65)));
        }
      }
      // all others
      else {
        printf("%c", text[i]);
      }
    }
    printf("\n");
  }