# Logical operators

from cs50 import get_char

# Prompt user for answer
c = get_char("answer: ")

# Check answer
if c == "Y" or c == "y":
    print("yes")
elif c == "N" or c == "n":
    print("no")
