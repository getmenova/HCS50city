#include <stdbool.h>

#include "dictionary.h"


bool check(const char *word)
{
    // hash the word received
    unsigned int hcode = hash(word);

    // search through the hash table to find it
    htnode *trav = hashtable[hcode];
    while (trav != NULL)
    {
        // case insensitive comparison
        if (!strcasecmp(trav->word, word))
        {
            return true;
        }

        // advance the traversal pointer
        trav = trav->next;
    }

    // must not have found anything
    return false;
}

//#STOLENHASH #REFACTOREDHASH
unsigned int hash(const char *word)
{
    unsigned int hash = 5381;
    int c;
    while ((c = (tolower(*word++))))
        hash = ((hash << 5) + hash) + c;

    return hash % SIZE;
}

//loadmem
bool load(const char *dictionary)
{
    // initialize dictionary size to 0
    dsize = 0;

    // attempt to open our file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    // load word by word
    while (true)
    {
        // create space for a new hash table node
        htnode *newnode = malloc(sizeof(htnode));
        if (newnode == NULL)
        {
            return false;
        }

        // read the next string from the source dictionary into the new node
        fscanf(source, "%s", newnode->word);

        // if we've reached the end of the file, break out
        if (feof(source))
        {
            free(newnode);
            break;
        }

        // hash that string to obtain a hash value
        unsigned int hcode = hash(newnode->word);

        // insert into the hash table at that location, at the front of the chain
        newnode->next = hashtable[hcode];
        hashtable[hcode] = newnode;

        // increment our word counter
        dsize++;
    }

    // close the dictionary file, success!
    fclose(source);
    return true;
}

unsigned int size(void)
{
    return dsize;
}


bool unload(void)
{
    // iterate over every element of our hash table, freeing its list
    for (int i = 0; i < SIZE; i++)
        vacate_list(hashtable[i]);

    // barring a fail of the free() function, no possible way to return false
    return true;
}


void vacate_list(htnode *head)
{
    // if the list is empty, nothing else to do
    if (head == NULL)
    {
        return;
    }

    // free the next element in the chain, then free this one
    vacate_list(head->next);
    free(head);
}