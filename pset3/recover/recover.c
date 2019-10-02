/**********************************************************
 * recover.c
 *
 * recovers JPEGs from a forensic image
 * recovers images from a memory card
 * stores each result in the current working directory
 * as a separate image file
 *********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    /* open a jpeg file */
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    /* store filename */
    char *infile = argv[1];

    /* open input file */
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s for reading\n", infile);
        return 2;
    }

    /* create a new image file */
    FILE *img = NULL;

    /* start of image file */
    BYTE soi[4] = {0xff, 0xd8, 0xff, 0xe0};

    /* create buffer to store bytes for a jpeg*/
    BYTE buff[512];

    /* jpeg counter */
    int jpc = 0;

    /* while we have data */
    while (fread(buff, 512, 1, inptr) == 1)
    {
        /* if we find a jpeg header */
        if (memcmp(buff, soi, 4) == 0)
        {
            /* create a jpeg filename */
            char jpegFilename[8];

            /* create a new img filename */
            sprintf(jpegFilename, "%03i.jpg", jpc);

            /* increment the file counter */
            jpc++;

            /* if jpg matches previous file, close it */
            if (img)
            {
                fclose(img);
            }

            /* open new img file */
            img = fopen(jpegFilename, "w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", jpegFilename);
                return 3;
            }
        }

        /* write jpeg file to output file */
        if (img)
        {
            fwrite(buff, sizeof(buff), 1, img);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(img);

    // success
    return 0;
}
