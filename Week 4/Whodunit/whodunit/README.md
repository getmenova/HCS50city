# Questions

## What's `stdint.h`?

A library! More specificially, a collection of typedefs and macros that will allow us to declare custom parameter limits and constants.
It will allow us to standardize 'integers' across different platforms.

Types are defined in the following categories:

Integer types having certain exact widths

Integer types having at least certain specified widths

Fastest integer types having at least certain specified widths

Integer types wide enough to hold pointers to objects

Integer types having greatest width

Can be any of the below....in the next question!!


## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

Using these defs for fixed width integers. Locks each type into a number of bytes, because a long on one system may not be exactly equivalent to a long in another. Another important standardizing tool.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

How many BYTES is a...
`BYTE` = 1 byte //sanity check!! ;)
`DWORD` = 4 byte
`LONG` = 4 byte
`WORD` = 2 byte


               __....__
            .'    `    \ ~"~-^^^^^^^^``-.
           /` _      )  `\              `\
          /`  a)    /     |               `\
         :`        /      |                 \
    <`-._|`  .-.  (      /   .            `;\\
     `-. `--'_.'-.;\___/'   .      .       | \\
  _     /:--`     |        /     /        .'  \\
 ("\   /`/        |       '     '         /    :`;
 `\'\_/`/         .\     /`~`=-.:        /     ``
   `._.'          /`\    |      `\      /(
                 /  /\   |        `Y   /  \
                /  /  \  |         |  /`\  \
               /  |   |  |         |  |  |  |
              "---"  /___|        /___|  /__|
                     '"""         '"""  '"""


"How do you eat an elephant?

One BYTE at a time!"

How many BITS is a..

`BYTE` = 1bytes*8 = 8 bits
`DWORD` = 4bytes*8 = 32 bits
`LONG` = 4bytes*8 = 32 bits
`WORD` = 2bytes*8 = 16 bits

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first 2 bytes of any BMP file in MUST be: the first two identifiers of the file type extension, therefore, B, and M in ASCII.
Or, 0x42 0x4D in hex - the values which translate to B and M. Finally, these values would be represented as 66 and 77 in decimal.

## What's the difference between `bfSize` and `biSize`?

You are right! bfSize should store the size of the whole BMP file — the size of the BMP image + the size of the headers.

biSizeImage should store the size of the BMP image — the size of the RGBTRIPLEs + the total size of the padding.

## What does it mean if `biHeight` is negative?
Indicates direction in which the file is being read. In this case, this
Normally bit maps are read starting from the bottom left hand corner and work their way up. If the biHeight is negative, the image will start from the top left and continue down.


## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

All DIB definitions rely on biBitCount for defining the color resolution. #FullStop

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Human error? Typo in filename could throw this err.

## Why is the third argument to `fread` always `1` in our code?

TODO

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

TODO

## What does `fseek` do?

fseek() function is used to move the file position to a desired location within the file.
It takes the following form: fssek(file_ptr, offset, position) ; file_ptr is a pointer to the file concerned, offset is a number or variable of type long, and position is an integer number.

## What is `SEEK_CUR`?

= the whence argument to the fseek or fseeko function.
It specifies that the offset we input is relative to the current file position.
