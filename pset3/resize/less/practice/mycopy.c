/* takes in a bmp file
 and copies it
 to a new file */

 #include <stdio.h>
 #include <stdlib.h> // abs()

 #include "bmp.h" // bmp structs

 int get_padding(int width, int pixel_size);

 int main(int argc, char* argv[])
 {
     //--------------------------------//
    //~*~*~*VALIDATE USER INPUTS~*~*~*//
    //---CREATE READ/WRITE POINTERS---//

    // user enters incorrect number of arguments
    if (argc != 3)
     {
         printf("Correct usage: <infile> <outfile>\n");
         return 1;
     }

     // NAME USER INPUT ARGUMENTS
     char* input_file_name = argv[1];
     char* output_file_name = argv[2];

     // create infile pointer and check if valid

     FILE* input_file_pointer = fopen(input_file_name, "r");
     if (input_file_pointer == NULL)
     {
         printf("File not found. Please enter a valid filename to copy\n", "r");
         return 2;
     }

     //create outfile pointer

     FILE* output_file_pointer = fopen(output_file_name, "w");
     if (output_file_pointer == NULL)
     {
         printf("File could not be created.\n");
         return 3;
     }

     //---------------------------//
    //~*~*~*REWRITE HEADERS~*~*~*//
    //--------------------------//

    // create a variable to hold our first struct for bmp.h

    BITMAPFILEHEADER bm_header;

    /*
    our input pointer is at the beginning of the file
    where this data lives. We have to pull in the correct
    number of bytes using sizeof(). We only have to pull
    it in 1 time.
    */

    // fread(destination, size of 1 element, # of element, source)

    fread(&bm_header, sizeof(BITMAPFILEHEADER), 1, input_file_pointer);

    /*
    we've taken data from the infile and put it in a variable
    which we can use to write to our new outfile
    */

    // fwrite(source, size of 1 element, # of elements, destination)

    fwrite(&bm_header, sizeof(BITMAPFILEHEADER), 1, output_file_pointer);

    /*
    next we'll repeat this process for the file info section
    (it's called the file info header but we already did the header
    and that makes things less clear)
    */

    BITMAPINFOHEADER bm_file_info;

    // pull info from input into our variable
    fread(&bm_file_info, sizeof(BITMAPINFOHEADER), 1, input_file_pointer);

    // push info from our variable to our output
    fwrite(&bm_file_info, sizeof(BITMAPINFOHEADER), 1, output_file_pointer);

    /*
    we want to skip over the padding, and then add it back in ourselves
    */

    /*
    in bmp.h the RGBTRIPLE struct represents a single pixel
    we need to know how many are in a single scanline
    and how many total rows exist in the image.
    we can find out the number of pixels for the width
    and height by accessing those values from the
    BITMAPINFOHEADER struct we read into.
    */

    /*
    we also have to add in padding, which is a byte of zeros
    represented as 0x00. we have a forumula for padding,
    and we can hide that in a function get_padding()
    */

    /*
    the height in some files is negative, which we have to solve
    for. We can just get the absolute value.
    */

    // get our values ready for looping
    int width = bm_file_info.biWidth;
    int height = abs(bm_file_info.biHeight);
    int padding = get_padding(width, sizeof(RGBTRIPLE));

     return 0;
 }