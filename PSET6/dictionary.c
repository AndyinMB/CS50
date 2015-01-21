/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "dictionary.h"

typedef struct node
{
	bool is_word;
	struct node* children[27];
} 
node;

node* root = NULL;

int nwords = 0;



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    node* current = root;
    //int i = 0;
    
    for (int i = 0; i < strlen(word); i++)
    
    //while(word[i] != '\0')
    {
        int letter = tolower(word[i]);
        
        //if (!isalpha(letter) || !current->children[letter-'a'])
        if (!current->children[letter-'a'])
        {
            return false;
        }    
        
        if (current->children[letter-'a'])
        {
            current = current->children[letter-'a'];
            //i++;
        }
    }    
    if (current->is_word == true)
    {
        return true;
    }
    return false;
}          

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
   
    //open dictionary and check
    FILE* dict = fopen(dictionary, "r");
    if(dict == false)
    {
        return false;
    }    
    
    //initialize nodes
    root = calloc(27,sizeof(node));
    node* current = NULL;
    
    int c = 0;
    //c is not EOF until after this check so nwords is always one too many
    while(c != EOF)
    {
        current = root;
        
        for(c = fgetc(dict); c != '\n' && c!= EOF; c = fgetc(dict))
        {
        //test for apostrophe??    
            if (current->children[c-'a']) 
            {
                current = current->children[c-'a'];
            }
            else
            {
                current->children[c-'a'] = calloc(1,sizeof(node));
                current = current->children[c-'a'];
                
            } 
            
        }
        current->is_word = true;
        nwords++;
    }    

    fclose(dict);
    return true;    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return nwords;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */

void freeNode(node* current)
{
    for (int i = 0; i < 27; i++)
    {
        if(current->children[i] != NULL)
        {
            freeNode(current->children[i]);
        }
    }
    free(current);
}    

bool unload(void)
{
    freeNode(root);  
    return true;
}

