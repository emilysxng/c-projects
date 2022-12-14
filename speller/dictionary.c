// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Declare variables
unsigned int word_count;
unsigned int hash_value;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    hash_value = hash(word);
    node *cursor = table[hash_value];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0) //if they match
        {
            return true;
        }
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) //takes word, returns integer
{
    unsigned long total = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        total += tolower(word[i]);
    }
    return total % N; 
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");

    //if there is no dictionary
    if (file == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    //words from dictionary will be written here
    char word[LENGTH + 1];

    //read strings one at a time until end of the dictionary is reached (EOF)
    while (fscanf(file, "%s", word) != EOF)
    {
        //creating node
        node *n = malloc(sizeof(node));

        // if no memory to make new node for new word
        if (n == NULL)
        {
            return false;
        }

        strcpy(n -> word, word);

        //get hash value to index into the table
        hash_value = hash(word);

        //placing node
        n -> next = table[hash_value];
        table[hash_value] = n;

        word_count++;
    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    if (word_count > 0)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor -> next;
            free(temp);
        }

        if(cursor == NULL && i == N-1)
        {
            return true;
        }
    }
    return false;
}
