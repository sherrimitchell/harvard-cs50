// Validates credit card number using Luhn's algorithm

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    long long cc_number;

    // Prompt user for a valid credit card number
    do
    {
        cc_number = get_long_long("Number: ");
    }
    while (cc_number < 0);

    long long even_sum;
    long long odd_sum;
    long long total_sum = 0;
    long long cc_test = cc_number;
    long long fd = cc_number;
    long long ftd = cc_number;
    long long digit_counter = cc_number;
    long long no_of_digits = 0;

    // use Luhn's algorithm to calculate the check digit
    while (cc_test > 0)
    {
        // get odd number
        odd_sum = cc_test % 10;

        // get next digit and multiply by 2
        cc_test /= 10;
        even_sum = cc_test % 10 * 2;

        // add sum of the product of the even numbers
        even_sum = even_sum / 10 + even_sum % 10;

        // add all of the even and odd digits together
        total_sum += odd_sum + even_sum;

        // decrement the credit card number
        cc_test /= 10;
    }

    // Check to see if card is valid
    bool valid_card = false;
    if (total_sum % 10 == 0)
    {
        valid_card = true;
    }
    else
    {
        printf("INVALID\n");
    }

    // get number of digits
    while (digit_counter > 0)
    {
        digit_counter /= 10;
        no_of_digits ++;
    }

    // get the first digit to verify card type
    while (fd > 9)
    {
        fd /= 10;
    }

    // get the first two digits to verify card type
    while (ftd > 99)
    {
        ftd /= 10;
    }

    // Tell the user whether the card is Amex, MCard, or Visa
    // compare card length and first 2 digits, return card name
    if (no_of_digits == 13 && fd == 4)
    {
        if (valid_card)
        {
            printf("VISA\n");
        }
    }
    else if ((no_of_digits == 15 && ftd == 34) || (no_of_digits == 15 && ftd == 37))
    {
        if (valid_card)
        {
            printf("AMEX\n");
        }
    }
    else if (no_of_digits == 16 && fd == 4)
    {
        if (valid_card)
        {
            printf("VISA\n");
        }
    }
    else if ((no_of_digits == 16 && ftd == 51) || (no_of_digits == 16 && ftd == 52) || (no_of_digits == 16 && ftd == 53)
             || (no_of_digits == 16 && ftd == 54) || (no_of_digits == 16 && ftd == 55))
    {
        if (valid_card)
        {
            printf("MASTERCARD\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}