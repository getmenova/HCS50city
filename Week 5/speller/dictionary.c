#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// The root node of the trie
node* root;

// word counter for dictionary
unsigned int words;

// allows for recursion
void clear(node* ptr);

//checks to see if word exists in dictionary
bool check(const char* word)
{
    int length = strlen(word);

    // Pointer to current node
    node* ptr = root;

    for (int i=0; i < length; i++)
    {
        char c = tolower(word[i]);

        // prevent ineglible char
        if (c == '\'')
        {
            // 123 - 97 = 26 (apostrophes go at nodes[26])
            c = 123;
        }

        // node to node
        struct node* nextNode = ptr->nodes[c-97];

        if (nextNode == NULL)
        {
            return false;
        }
        else
        {
            ptr = nextNode;
        }
    }

    // does word exist in dict as a standalone?
    if (ptr->word == true)
    {
        return true;
    }

    return false;
}

//manually load dictionary into mem
bool load(const char* dictionary)
{
    // Open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // space for 1st root
    root = calloc(1, sizeof(node));

    // pointer for current node
    node* ptr = root;

    // char by char readthrough
    for (char c = tolower(fgetc(dict)); c != EOF; c = fgetc(dict))
    {
        // check for EOW
        if (c == '\n')
        {
            // is word >1 l long?
            if (ptr != root)
            {
                words++;

                ptr->word = true;

                // send your pointers home
                ptr = root;
            }
        }

        else
        {
            // careful for apossssstrocatastrophes
            if (c == '\'')
            {
                // 123 - 97 = 26 (apostrophes go at nodes[26])
                c = 123;
            }

            // Try to get the address of the next node in the trie
            struct node* nextNode = ptr->nodes[c-97];
            if (nextNode == NULL)
            {
                // Allocate space if it is not yet there
                ptr->nodes[c-97] = calloc(1, sizeof(node));

                ptr = ptr->nodes[c-97];
            }
            else
            {
                ptr = nextNode;
            }

        }
    }

    fclose(dict);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

/**
 * Recursive function that frees a trie from memory
 */
void clear(node* ptr)
{
    for (int i = 0; i < 27; i++)
    {
        if (ptr->nodes[i] != NULL)
        {
            clear(ptr->nodes[i]);
        }
    }

    free(ptr);
}

//shut the door behind you @WaterFire, release mem
bool unload(void)
{
    clear(root);
    return true;
}