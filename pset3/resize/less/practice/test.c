// ------------------------------------
// create a program that creates a file
// and makes a copy of it. Command line
// usage: ./test <infile> <outfile>
// ------------------------------------

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    //--------------------------------//
    //~*~*~*VALIDATE USER INPUTS~*~*~*//
    //--------------------------------//

    // validate command line arguments
    if (argc != 3)
    {
        printf("error: Usage: ./test <infile> <outfile>");
        return 1;
    }
    printf("%s %s %s\n", argv[0], argv[1], argv[2]);

    // validate infile
    char* input_file_name = argv[1];
    FILE* input_file_pointer = fopen(input_file_name, "r");

    // if there is no file, or we can't open it
    if (input_file_pointer == NULL)
    {
        printf("Could not open %s\n", input_file_name);
        return 2;
    }

    //--------------------------------//
    //~*~*~*WRITE TO OUTPUT FILE~*~*~*//
    //--------------------------------//
    char* output_file_name = argv[2];
    FILE* output_file_pointer = fopen(output_file_name, "w");
    char(c);
    while(1)
    {
        // we need to break once the NULL terminator is
        // collected in our variable which is why we
        // have our break statement after assigning
        // our variable c
        // in other words we don't want to write the last
        // byte to our outfile
        c = fgetc(input_file_pointer);

        if (feof(input_file_pointer))
        {
            break;
        }

        fputc(c, output_file_pointer);
        printf("%c", c);
    }
    printf("\n");

    //------------------------------------//
    //~*~*~*CLOSE OUT FILE POINTERS~*~*~*//
    //-----------------------------------//

    fclose(input_file_pointer);
    fclose(output_file_pointer);

    return 0;
}
