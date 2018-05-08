/**
 * dictionary.h
 *
 * Doug Lloyd
 * lloyd@cs50.harvard.edu
 *
 * Declares a dictionary's functionality.
 * Implemented as a hash table
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// size of our hash table
#define SIZE 80000

// type definition for each node of our hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
htnode;

// global hash table (by default initialized to 0, since global)
htnode *hashtable[SIZE];

// global count of words inserted
unsigned int dsize;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Hash function, adapted from djb2 http://www.cse.yorku.ca/~oz/hash.html
 */
unsigned int hash(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

/**
 * Recursively deletes each linked list in the hash table
 */
void vacate_list(htnode *head);

#endif // DICTIONARY_H