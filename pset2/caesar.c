// Encrypts plaintext messages using Caesar's cipher

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#include <block.h>

int main(int argc, string argv[])
{
    // check to see if user enters a key. If no key or too many args. rtn 1 & error msg
    if (argc < 2) // no key entered
    {
        printf("Key field cannot be blank. Please enter a key. \n");
        return 1;
    }
    else if (argc > 2) // too many arguments entered
    {
        printf("You may only enter one key. \n");
        return 1;
    }

    // convert the key to int
    int k = atoi(argv[argc - 1]);

    // get plaintext from the user
    string p = get_string("plaintext: ");

    // print ciphertext
    printf("ciphertext: ");

    // encrypt plaintext and return the ciphertext
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // alpha and uppercase
        if (isalpha(p[i]) && isupper(p[i]))
        {
            printf("%c", (p[i] - 65 + k) % 26 + 65);

        }
        // alpha and lowercase
        else if (isalpha(p[i]) && islower(p[i]))
        {
            printf("%c", (p[i] - 97 + k) % 26 + 97);
        }
        else
            // non-alpha chars
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
