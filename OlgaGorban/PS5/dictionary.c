/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

#define MAX_CHARS   27
#define NEWLINE     '\n'

// struct for trie node
typedef struct node
{
    bool wordEnd;
    struct node* children[MAX_CHARS];
}
node;

// additional prototypes
bool freeMemory(node* node);

// # of dictionary words loaded
unsigned int dictWords;

// trie root pointer
node* trieRoot; 

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int index = 0;
    int childIndex = 0;

    node* currentNode = trieRoot;

    while (word[index] != '\0')
    {
        // check for alphabetic letter
        if (isalpha(word[index]))
        {   
            // get index while ensuring case insensitivity
            childIndex = ((word[index] < 'a') ? word[index] + 32 : word[index]) - 'a';
        }
        // check for apostrophe
        else if (word[index] == '\'')
        {
            childIndex = MAX_CHARS - 1;
        }
        // if any other character, short circuit since invalid
        else
        {
            return false;
        }

        // if child index element is NULL, word is not present, i.e. misspelled
        if (currentNode->children[childIndex] == NULL)
        {
            return false;
        }
        else
        {
            // move on to next letter
            currentNode = currentNode->children[childIndex];
        }  

        index++;
    }

    return currentNode->wordEnd;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open the dictionary file
    FILE* dictFile = fopen(dictionary, "r");
    
    if (dictFile != NULL)
    {
        char word[LENGTH + 1];
        char currentChar;

        int index = 0;
        int childIndex = 0;
        dictWords = 0;
        
        // allocate memory for root
        trieRoot = (node*) malloc(sizeof(node));
        
        if (trieRoot == NULL)
        {
            printf("Error allocating memory for trieRoot.\n");
            fclose(dictFile);
            return false;
        }
        
        // read in one char at a time until EOF is reached
        for (int chr = fgetc(dictFile); chr != EOF; chr = fgetc(dictFile))
        {
            // have we reached the end of a word/line?
            if (chr == NEWLINE)
            {
                // capture last char and prepare to insert into trie
                word[index] = chr;
                node* currentNode = trieRoot;
                
                for (int i = 0; i <= index; i++)
                {
                    currentChar = word[i];

                    // check for alphabetic letter
                    if (isalpha(currentChar))
                    {
                        // get child node index
                        childIndex = currentChar - 'a';
                        
                        // if NULL, malloc a new node for this letter
                        if (currentNode->children[childIndex] == NULL)
                        {
                            currentNode->children[childIndex] = 
                                (node*) malloc(sizeof(node));

                            if (currentNode->children[childIndex] == NULL)
                            {
                                printf("Error allocating memory for node.\n");
                                fclose(dictFile);
                                return false;
                            }
                        }
                        
                        // "insert" letter
                        currentNode = currentNode->children[childIndex];
                    }
                    // check for apostrophe
                    else if (currentChar == '\'')
                    {
                        // if NULL, malloc a new node at the end for the '
                        if (currentNode->children[MAX_CHARS - 1] == NULL)
                        {
                            currentNode->children[MAX_CHARS - 1] = 
                                (node*) malloc(sizeof(node));

                            if (currentNode->children[MAX_CHARS - 1] == NULL)
                            {
                                printf("Error allocating memory for node.\n");
                                fclose(dictFile);
                                return false;
                            }
                        }
                        
                        // "insert" the apostrophe
                        currentNode = currentNode->children[MAX_CHARS - 1];
                    }
                    // check for end of the word
                    else if (currentChar == NEWLINE)
                    {
                        currentNode->wordEnd = true;
                    }
                }

                // increment/reset for next word
                dictWords++;
                index = 0;
            }
            else
            {
                // append the new char and keep going to finish the word
                word[index] = chr;
                index++;
            }
        }

        fclose(dictFile);
        return true;
    }
    else
    {
        printf("Error opening dictionary file %s.\n", dictionary);
        return false;
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictWords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    return freeMemory(trieRoot);
}

bool freeMemory(node* node)
{
    for (int i = 0; i < MAX_CHARS; i++)
    {
        // recursively call freeMemory() for each malloc'd child
        if (node->children[i] != NULL)
        {
            freeMemory(node->children[i]);
        }
    }
    
    // free the parent (this) node
    free(node);

    return true;
}
