/*
open the infile
read the header

update the outfile header
to be double the infile header

allocate enough memory to store
double the data (MMaaxx)

write it to the outfile
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    /*
    MAIN GOAL:
    INPUT FILE HAS THE TEXT 3Max
    OUTPUT FILE WILL HAVE 6MMaaxx
    NOTE: WE UPDATE OUR "HEADER"

    note: you can change the
    factor variable up to 3 and
    everything shoud work the same
    try it out!
    */

    int factor = 2;

    if(argc != 3)
    {
        return 1;
    }

    /*
    eff the error checking. let's get this thang started!
    command line usage: ./filename <infile> <outfile>
    in this case, the factor will be hard coded in
    to make it a little less complicated.

    infile will be data.txt file with the text 3Max

    When we open the outfile, we are actually creating it...
    unfortunately, we have to use fopen() so don't let
    that confuse you. Better if it was fcreate()!!!
    */

    // infile stream (infiling in the stream, that is what we are, lol)
    FILE *inptr = fopen(argv[1], "r");

    // outfile stream
    FILE *outptr = fopen(argv[2], "w");

    // create a variable to hold our header data
    // has to be array type in this case
    char inWidthChar[1];

    /*
    read in the first char from our infile stream
    remember this moves the FILE pointer forward
    by 1 char. so we're on the M after reading in
    the 3 within data.txt. it just happens on it's
    own. Let it do what it do!
    */

    fread(&inWidthChar, sizeof(char), 1, inptr);

    /*
    now width has the orginal width, which is 3
    so, let's create a different variable for
    the outfile header to keep it tidy
    */

    int inWidth = atoi(inWidthChar);

    int outWidth = inWidth * factor;

    // yeah...this is a trick for converting int
    // back to char
    char outWidthChar = outWidth + '0';

    // write it to the outfile
    fwrite(&outWidthChar, sizeof(char), 1, outptr);

    /*
    using malloc() we can store chunks of size char
    multiplied by whatever the outWidth is. We do
    not need to know beforehand. It can be any digit
    between 0 - 9, and this will work. make sure
    the number of letters in the name match the
    "header". Example: 9YZAGUIRRE OR 4John.
    */

    char *name = malloc(sizeof(char) * outWidth);

    /*
    to illustrate how our memory looks:
    [c0][c1][c2][c3][c4][c5]

    because they are each char data types
    if we were to take the variable called
    name and do something like:
    *(name + 3) = 'z'
    the drawing would look like this:
    [c0][c1][c2][z][c4][c5]
    we use that * right before name to say
    "hey the VALUE not the address"
    we are saying go to that memory location
    and store the value 'z' (dereferencing the pointer)

    For real, doe...

    watch how we use this in the loop
    to build the first half of our dynamic name
    data store
    */

    // temp char to hold each letter in the loop
    char letter;

    // keep note of this being out of the loop
    int pointer_tracker = 0;

    // loop through each letter of Max within the infile
    for (int i = 0; i < inWidth; i++)
    {
        fread(&letter, sizeof(char), 1, inptr);

        // now we need to use that letter variable
        // twice. this calls for another inner loop!
        // don't forget, we hard-coded our factor
        // to 2
        for (int j = 0; j < factor; j++)
        {
            *(name + pointer_tracker) = letter;
            pointer_tracker++;

            /*
            remember the drawing
            [c0][c1][c2][c3][c4][c4][c5][c6]
            we need this to keep going up/moving
            forward. so we can't use the inner counter
            variables i or j because they reset
            too often.

            first loop, we take in the 'M'
            then, the inner loop takes M and assigns it
            to [c0] and [c1]
            then letter becomes 'a'
            the inner loop assigns assigns 'a' to
            [c2] and [c3]. once all the letters complete,
            our name variable we used malloc() with has
            the data MMaaxx so we just have to fwrite
            to the outfile and we're home free!
            we'll do this outside of both loops!
            */
        }
    }

    /*
    so name is already a pointer type so we don't use
    the & (address) symbol. It's already an address to
    a value somewhere.

    we need to write the correct number of bytes. so keep
    that in mind.
    */
    fwrite(name, sizeof(char) * outWidth, 1, outptr);

    // with dynamic memory we have to manually "free" it
    // so it's available to the system again after runtime
    // wow! this is doing the most!
    free(name);

    // close the file streams and treat yoself!
    fclose(inptr);
    fclose(outptr);

    return 0;
}