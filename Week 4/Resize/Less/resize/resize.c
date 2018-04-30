/*Implement a program called resize that resizes (i.e., enlarges) 24-bit uncompressed BMPs by a factor of n.

Implement your program in a file called resize.c in a directory called resize.

Your program should accept exactly three command-line arguments, whereby

the first (n) must be a positive integer less than or equal to 100,

the second must be the name of a BMP to be resized, and

the third must be the name of the resized version to be written.

+ If your program is not executed with such, it should remind the user of correct usage, as with fprintf (to stderr), and main should return 1.

Your program, if it uses malloc, must not leak any memory.*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bmp.h"

int main(int argc, char *argv[])
{
    // check for 4 scores and 7 years ago
    if (argc != 4)
    {
        printf("Try again! Input in form resize (n) infile outfile\n");
        return 1;
    }

    //check for int
    for (int i = 0, len = strlen(argv[1]); i < len; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("INTS ONLY! \n");
            return 1;
        }
    }

    // space for resize (n)
    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // is it between 1 and 100 as specified in instructions?
    if (n <= 0 || n > 100)
    {
        printf("n, the resize factor, must satisfy 0 < n <= 100.\n");
        return 1;
    }

    // I/O OPEN
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Unable to make %s.\n", outfile);
        return 1;
    }

    // I/O READ
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(inptr);
        fclose(outptr);
        printf("Error: You can't do that.\n");
        return 1;
    }

    //WxX orig
    int widthO  = bi.biWidth;
    int heightO = abs(bi.biHeight);

    // padding hint from Zamyla
    int paddingO =  (4 - (widthO * sizeof(RGBTRIPLE)) % 4) % 4;

    //dims post R
    bi.biWidth *= n;
    bi.biHeight *= n;

    // padding post R
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // bmpinfo header refresh
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding) * abs(bi.biHeight);

    // bmpfileheader refresh
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER)
                + sizeof(BITMAPINFOHEADER);

    //I/O write
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // I/O write
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // scanline speeder
    for (int i = 0; i < heightO; i++)
    {
        // pixel palace
        RGBTRIPLE currRow[widthO];

        //I/O READ
        fread(&currRow, sizeof(RGBTRIPLE), widthO, inptr);

        //on to the next one
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < widthO; l++)
            {
                // but don't forget the last one!
                for (int m = 0; m < n; m++)
                {
                    fwrite(&currRow[l], sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // #ADDTHEPAD
            for (int l = 0; l < padding; l++)
            {
                fputc(0x00, outptr);
            }
        }

        // #IGNORETHEPAD
        fseek(inptr, paddingO, SEEK_CUR);
    }

    // CLOSE
    fclose(inptr);

    // CLOSE
    fclose(outptr);

    // LATER, PSET
    return 0;
}