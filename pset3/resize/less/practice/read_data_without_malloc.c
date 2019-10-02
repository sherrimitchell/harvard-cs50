/*
Static data. No malloc()
Create an array of chars
that can hold the name
"3Max" and read from a file
usage: ./read_data_without_malloc <infile>
*/

#include <stdio.h>
#include <stdlib.h> // atoi

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("um, need you to enter an infile\n");
    }

    // create an infile pointer
    FILE *infile_pointer = fopen(argv[1], "r");

    if (infile_pointer == NULL)
    {
        printf("ruh roh. not good. something's not right\n");
    }

    // create a static array variable to hold 3 chars
    char static_data[3];

    // the first byte is going to be our "header info"
    // which tells us the width or number of chars
    // in our file

    char header;

    fread(&header, sizeof(char), 3, infile_pointer);

    // read the file's 3 chars into our variable
    fread(static_data, sizeof(char), 3, infile_pointer);

    // print to the screen
    printf("static data? we can do better. %s\n", static_data);
    printf("our header can only hold %c chars\n", header);

    // close the pointer. cause we were raised right
    fclose(infile_pointer);

    return 0;
}