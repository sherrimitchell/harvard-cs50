// Calculates the minimum number of coins required to give a user change

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change_amount = 0;
    int cents = 0;
    int coins = 0;

    do
    {
        // Prompt user to enter amount of change owed
        change_amount = get_float("Change owed: ");
    }
    while (change_amount < 0);

    // calculate the amount of cents
    cents = round(change_amount * 100);

    // coin amounts
    int quarter = 25, dime = 10, nickel = 5, penny = 1;

    // check if cents includes any quarters
    if (cents % quarter > 0 || cents >= quarter)
    {
        coins += cents / quarter;
        cents = cents % quarter;
    }
    else
    {
        coins += 0;
    }

    // check if cents includes any dimes
    if (cents % dime > 0 || cents >= dime)
    {
        coins += cents / dime;
        cents = cents % dime;
    }
    else
    {
        coins += 0;
    }

    // check if cents includes any nickels
    if (cents % nickel > 0 || cents >= nickel)
    {
        coins += cents / nickel;
        cents = cents % nickel;
    }
    else
    {
        coins += 0;
    }

    // check if cents includes any pennies
    if (cents % penny > 0 || cents >= penny)
    {
        coins += cents / penny;
    }
    else
    {
        coins += 0;
    }

    // print number of coins
    printf("%i\n", coins);
}