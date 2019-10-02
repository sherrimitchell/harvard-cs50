// Cracks passwords using C's DES based crypt function
// crypt(guess,salt)

#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

# define NUMBER_OF_LETTERS 52

int main(int argc, string argv[])
{
    string user_pw = argv[1];

    char salt[3];

    // no password or more than one password entered
    if (argc != 2)
    {
        printf("Usage: ./crack hash \n");
        return 1;
    }

    // salt
    for (int i = 0; i < 2; i++)
    {
        salt[i] = user_pw[i];

        salt[2] = '\0';
    }

    // generate lower and uppercase alphabet
    char letters[52] = {0};

    // lowercase letters
    for (int alpha = 0; alpha < 26; alpha++)
    {
        letters[alpha] = alpha + 'a';
    }

    // uppercase letters
    for (int alpha = 26; alpha < 52; alpha++)
    {
        letters[alpha] = alpha + 39;
    }

    // guess up to 5 characters
    char guess[6];

    // password guess 1 character
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        guess[0] = letters[i];
        guess[1] = '\0';

        // run crypt on guess and compare to user password
        if (strcmp(crypt(guess, salt), user_pw) == 0)
        {
            // if guess and pw match, print password and end
            printf("%s\n", guess);
            return 0;
        }
    }

    // password guess 2 characters
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_LETTERS; j++)
        {
            guess[0] = letters[i];
            guess[1] = letters[j];
            guess[2] = '\0';

            // run crypt on guess and compare to user password
            if (strcmp(crypt(guess, salt), user_pw) == 0)
            {
                // if guess and pw match, print password and end
                printf("%s\n", guess);
                return 0;
            }
        }
    }

    // password guess 3 characters
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_LETTERS; j++)
        {
            for (int k = 0; k < NUMBER_OF_LETTERS; k++)
            {
                guess[0] = letters[i];
                guess[1] = letters[j];
                guess[2] = letters[k];
                guess[3] = '\0';

                // run crypt on guess and compare to user password
                if (strcmp(crypt(guess, salt), user_pw) == 0)
                {
                    // if guess and pw match, print password and end
                    printf("%s\n", guess);
                    return 0;
                }
            }
        }
    }

    // password guess 4 characters
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_LETTERS; j++)
        {
            for (int k = 0; k < NUMBER_OF_LETTERS; k++)
            {
                for (int l = 0; l < NUMBER_OF_LETTERS; l++)
                {
                    guess[0] = letters[i];
                    guess[1] = letters[j];
                    guess[2] = letters[k];
                    guess[3] = letters[l];
                    guess[4] = '\0';

                    // run crypt on guess and compare to user password
                    if (strcmp(crypt(guess, salt), user_pw) == 0)
                    {
                        // if guess and pw match, print password and end
                        printf("%s\n", guess);
                        return 0;
                    }
                }
            }
        }
    }

    // password guess 5 characters
    for (int i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        for (int j = 0; j < NUMBER_OF_LETTERS; j++)
        {
            for (int k = 0; k < NUMBER_OF_LETTERS; k++)
            {
                for (int l = 0; l < NUMBER_OF_LETTERS; l++)
                {
                    for (int m = 0; m < NUMBER_OF_LETTERS; m++)
                    {
                        guess[0] = letters[i];
                        guess[1] = letters[j];
                        guess[2] = letters[k];
                        guess[3] = letters[l];
                        guess[4] = letters[m];
                        guess[5] = '\0';


                        // run crypt on guess and compare to user password
                        if (strcmp(crypt(guess, salt), user_pw) == 0)
                        {
                            // if guess and pw match, print password and end
                            printf("%s\n", guess);
                            return 0;
                        }
                    }
                }
            }
        }
    }

}
