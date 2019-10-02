// Prints out a double half-pyramid of a specified height

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        // Prompt the user to enter a height for the pyramids
        height = get_int("Please enter a positive number between 0 and 23 for the height of the pyramids: ");
    }
    while (height < 0 || height > 23);

    // Print the number of rows for the given height
    for (int i = 1; i <= height; i++)
    {
        //print spaces for left pyramid
        for (int j = (height - i); j > 0; j--)
        {
            printf(" ");
        }

        // print bricks for the left pyramid
        for (int k = 0; k <= (i - 1); k++)
        {
            printf("#");
        }

        // print 2 spaces between the 2 pyramids
        printf("  ");

        // print bricks for the right pyramid
        for (int r = 0; r <= (i - 1); r++)
        {
            printf("#");
        }

        // insert a newline
        printf("\n");
    }
}