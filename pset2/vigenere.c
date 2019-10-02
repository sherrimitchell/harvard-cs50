// Encrypts plaintext messages using Vigenere's cipher
// Ci=(Pi + Kj) mod 26

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // no key or too many keys
    if (argv[1] == 0)
    {
        printf("Key field cannot be blank. Please enter a key. \n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Multiple keys cannot be entered. \n");
        return 1;
    }

    // key
    string key = argv[1];
    int l = strlen(key);

    for (int m = 0; m < l; m++)
    {
        if (isalpha(key[m]) == false)
        {
            printf("You may only enter uppercase or lowercase letters for the key. \n");
            return 1;
        }
        key[m] = toupper(key[m]);
    }

    // get plaintext
    string p = get_string("plaintext: ");

    // print ciphertext
    printf("ciphertext: ");


    int index = 0;
    unsigned char k;

    for (int i = 0, n = strlen(p); i < n; i++)
    {
        // alpha chars
        if (isalpha(p[i]))
        {
            // k index wrap around
            int j = index % l;
            k = key[j] - 'A';

            // uppercase chars
            if (isupper(p[i]))
            {
                printf("%c", (p[i] - 'A' + k) % 26 + 'A');
            }
            // lowercase chars
            else if (islower(p[i]))
            {
                printf("%c", (p[i] - 'a' + k) % 26 + 'a');
            }
            index++;
        }
        // non-alpha chars
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
