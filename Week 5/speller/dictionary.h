#include <stdbool.h>
#ifndef DICTIONARY_H
#define DICTIONARY_H
typedef struct node
{
    struct node* nodes[27];
    bool word;
}node;

#include <stdbool.h>

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

bool check(const char* word);

bool load(const char* dictionary);

unsigned int size(void);

bool unload(void);

#endif // DICTIONARY_H
