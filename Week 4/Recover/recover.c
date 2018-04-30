//open mem card file
// repeat till end
//read 512
//does a new jpeg start?
// already found one?
// close any remaining files



#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTEFF 0xff //first BYTE of a JPEG file
#define BYTED8 0xd8 // second BYTE of a JPEG file
#define BLOCK 512 // define BLOCK size - typing 512 is lame and allows us to change the constant here if we want to scan a diff size
#define NAMELEN 8 // filename shall have 3 chars + dot + jpg + nullchar = 8 spots allocatied in buffer
#define STARTERLEN 3 // jpg filename startinrr length
//last byte 0xe0, 0xe1, 0xe2 and so on.

//jpegs start at 000

typedef uint8_t byte;
byte starters[] = {BYTEFF, BYTED8, BYTEFF}; // typedef and define - searching for jpeg starter byte


bool jpg_start(byte *buffer); // function

int main(int argc, string argv[])
{

    if (argc != 2)  // check 2 args only
    {
        fprintf(stderr, "Enter %s <card>\n", argv[0]);
        return 1;
    }


    FILE *inptr = fopen(argv[1], "r");  // open the file
    if (inptr == NULL)
    {
        fprintf(stderr, "The way is shut! Cannot open file = %s.\n", argv[1]);
        return 2;
    }


    byte *buffer = malloc(sizeof(byte) * BLOCK); // box for jpeg data
    if (buffer == NULL)
    {
        fprintf(stderr, "You broke something in memory.\n");
        fclose(inptr);
        return 3;
    }


    FILE *outptr = NULL; // pointer for pegs
    int file_num = 0;


    char *name = malloc(sizeof(char) * NAMELEN); //    // set aside a buffer to hold our name string
    if (name == NULL)
    {
        fprintf(stderr, "You broke something in memory.\n");
        fclose(inptr);
        return 4;
    }


    while (fread(buffer, 1, sizeof(byte) * BLOCK, inptr) == BLOCK) // continue reading blocks from the card until we reach the end
    {

        if (jpg_start(buffer)) // matchbytes
        {

            if (outptr != NULL) // if a file already is being written to, close it
            {
                fclose(outptr);
            }


            sprintf(name, "%03i.jpg", file_num++);  // open a new file with the correct file number - from walkthrough w/ Zamyla e.g  000.jpg
            outptr = fopen(name, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "The way is shut! Cannot open file =  %s.\n", name);
                fclose(inptr);
                return 5;
            }
        }


        if (outptr != NULL)
        {
            fwrite(buffer, 1, sizeof(byte) * BLOCK, outptr);  // continue writing to the file (if one is open), or ignore the block
        } // frwrite params as follows - fwrite (data, size, number, outputr) where data  = pointer to the struct that contains the read bytes, size, number, and outputr
    }


    free(buffer); //deallocate memory
    free(name); // deallocate memory
    fclose(outptr); // flush those buffers
    fclose(inptr);  // all done, clean up all open files and allocated memory - sweeping to prevent mem leak - check!


    return 0; // LATER, PSET!
}


bool jpg_start(byte *buffer) // function to detect the beginning of a jpg, based on its initial four bytes
{

    if (!memcmp(buffer, starters, sizeof(byte) * STARTERLEN)) // according to walkthrough the first three bytes should be 0xff, 0xd8, 0xff
    {

        return ((buffer[STARTERLEN] ^ 0x10) >= 0xf0) ? true : false; // bitwise crack from stackoverflow, checks byte number 4
    }


    return false; // no match if program runs to this line
}