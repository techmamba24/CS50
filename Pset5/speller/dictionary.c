/**
 * dictionary.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

typedef struct node {
    char word[LENGTH+1];
    struct node* next;
}
node;

#define SIZE 729
unsigned int wordcounter=0;
node *dict [SIZE];

/**
 * A hashing function to determine which position in the array the word should be inserted into.
 */

int hash (const char *word){
    
int hash = 0;
if(word[0]==39||word[1]==39) hash = 0;
else {
hash = strlen(word)<2 ?  (word[0]-96) : (word[0]-96)*(word[1]-96);
}

return hash;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word) {
    
int n = strlen(word);
char *copy = malloc(sizeof(int)*n);

for (int i=0; i<n; i++){
 
if(isupper(word[i])) copy[i] = tolower(word[i]);
    else  {
     copy[i]=word[i];
    }
        
} 

int index = hash(copy);

free(copy);

if(dict[index]==NULL) return false;

node *trav = dict[index];

while (trav!=NULL){
    if (strcasecmp(trav->word, word)==0) return true;
    trav = trav->next;
}
    
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary) {
    
    for (int i=0; i<SIZE; i++){
        dict[i]=NULL;
    }
    
    FILE *file = fopen(dictionary,"r");
    if (file==NULL){
        printf("Could not open %s\n", dictionary);
        return false;
    }
    
    char word[LENGTH+1];
    
    while(fscanf(file,"%s",word)!=EOF){
        
        node *newnode = malloc(sizeof(node));
        if (newnode==NULL){
            unload();
            return false;
        }
        
        strcpy(newnode->word, word);
        
        int index = hash(word);
        
        if(dict[index]==NULL){
        dict[index]=newnode;
        newnode->next=NULL;
        }
        
        else{
        newnode->next = dict[index];
        dict[index] = newnode; 
        }
        
        wordcounter++;
    }
    
    fclose(file);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void) {
    
    return wordcounter;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void) {
    
    for (int i=0; i<SIZE; i++){
        node *trav = dict[i];
        while (trav!=NULL){
            node *temp = trav;
            trav = trav->next;
            free(temp);
        }
    }

    return true;
}
