// Prints a half pyramid of a specified height

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        // Prompt the user for a positive number
        height = get_int("Please enter a positive number: ");
    }
    while (height < 0 || height > 23);

// Print out that number of rows
    for (int i = 1; i <= height; i++)
    {
        // Print out spaces per row
        for (int j = (height - i); j > 0; j--)
        {
            printf(" ");
        }

        // Print out bricks per row
        for (int k = 1; k <= (i + 1); k++)
        {
            printf("#");
        }

        // Print a new line after each row
        printf("\n");
    }
}