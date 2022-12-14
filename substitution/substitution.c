#include <stdio.h>
#include <cs50.h>

int get_length_of_string(string key);
int check_letters_only(string key);

int main(int argc, string argv[])
{
    if (argc == 1) // if there is no command line argument
    {
        printf("Usage: ./substitution KEY \n");
        return 1;
    }

        if (argc != 2) // if there is more than one command line argument
    {
        printf("Input only one key. \n");
        return 1;
    }

    string key = argv[1];  //checking for 26 characters in the key
    int length = get_length_of_string(key);
    if (length != 26)
    {
        printf ("Key must contain 26 characters. \n");
        return 1;
    }

    int letters_only = check_letters_only(key); //checking if key has letters only
    if (letters_only != 0)
    {
        printf ("Key must only contain letters. \n");
        return 1;
    }

    for (int n = 0; n < 26; n++) //checking if key has repeated letters
    {
        for(int k = 1; n-k >= 0; k++)
        {
            if (key[n] == key[n-k])
            {
            printf("Key must not have repeated letters. \n");
            return 1;
            }
        }
    }

string new_key_uppercase = key;

    for (int p = 0; p < 26; p++) // making lowercase letters uppercase
    {
        if (key[p] >= 97 && key[p] <= 122)
        {
            new_key_uppercase[p] = key[p] - 32;
        }
    }
    printf ("Key Given: %s \n", new_key_uppercase);

    string plaintext = get_string("Plaintext: "); // get plaintext from user

    for (int c = 0; plaintext[c] != '\0'; c++) //encryption of plaintext using the key
    {
        if (plaintext[c] >= 65 && plaintext[c] <= 90) //for uppercase letters in plaintext
        {
            plaintext[c] = new_key_uppercase[ -65 + plaintext[c] ];
        }
        if (plaintext[c] >= 97 && plaintext[c] <= 122) // for lowercase letters in plaintext
        {
            plaintext[c] = (new_key_uppercase[ -65 + (plaintext[c] - 32 )]) + 32;
        }
    }

    printf("Ciphertext: %s \n", plaintext);
}

int get_length_of_string(string key) // function that finds the length of characters in the key
{
    int length = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        length++;
    }
    return length;
}

int check_letters_only(string key) //function that checks if key has letters only
{
    int letters_only = 0;
    for (int x = 0; key[x] != '\0'; x++)
    {
        if ((key[x] > 0 && key[x] < 65) || (key[x] > 90 && key[x] < 97) || (key[x] > 122))
        {
            letters_only++;
        }
    }
    return letters_only;
}