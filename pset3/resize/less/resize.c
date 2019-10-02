/*
Resizes a BMP file by a factor that is
a positive integr between 0 and 100
*/

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // resize factor. infile. outfile.
    int factor  = atoi(argv[1]);
    if ((factor < 0) || (factor > 100))
    {
        fprintf(stderr, "Please enter a positive number from 0 to 100.\n");
        return 1;
    }

    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // create outfile's BITMAPINFOHEADER & BITMAPFILEHEADER
    BITMAPFILEHEADER of;
    BITMAPINFOHEADER oi;

    // copy input header values
    of = bf;
    oi = bi;

    // update values
    oi.biWidth *= factor;
    oi.biHeight *= factor;

    // padding
    int in_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (oi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    oi.biSizeImage = ((sizeof(RGBTRIPLE) * oi.biWidth) + out_padding) * abs(oi.biHeight);

    of.bfSize = oi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile header
    fwrite(&of, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&oi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // create buffer to store pixels for a scanline
    RGBTRIPLE *scanline = malloc(sizeof(RGBTRIPLE) * oi.biWidth);

    if (scanline == NULL)
    {
        printf("Error -- out of memory.\n");
        return 1;
    }

    // iterate over infile's scanlines
    for (int i = 0; i < abs(bi.biHeight); i++)
    {
        // track no of pixels
        int pixel_count = 0;

        for (int j = 0; j < bi.biWidth; j++)
        {
            // temp store for one pixel
            RGBTRIPLE pixel;

            // read pixel from infile
            fread(&pixel, sizeof(RGBTRIPLE), 1, inptr);

            // add pixels to the buffer factor times
            for (int k = 0; k < factor; k++)
            {
                // add pixels
                *(scanline + pixel_count) = pixel;
                pixel_count++;
            }
        }

        // skip over padding. go to next row
        fseek(inptr, in_padding, SEEK_CUR);

        // add rows based on factor
        for (int l = 0; l < factor; l++)
        {
            fwrite(scanline, sizeof(RGBTRIPLE), oi.biWidth, outptr);

            // add padding for each row added
            for (int m = 0; m < out_padding; m++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // free memory for scanline
    free(scanline);

    // close files
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
