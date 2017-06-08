/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n) {
    
   int beginning = 0;
   int middle = n/2;
   int end = n;
   
   while (beginning<=end){
       
      if (values[middle]==value) return true;
      if (values[middle]>value) {
          end = middle-1;
          middle = (beginning+end)/2;
      }
      else if(values[middle]<value){
         beginning=middle+1;
         middle= (beginning+end)/2;
      }
      
   }
   
   return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n) {
    
    for (int i=0; i<n-1; i++){
        
        for (int j=0; j<n-1; j++){
            
            if (values[j]>values[j+1]){
                int temp = values[j+1];
                values[j+1]=values[j];
                values[j]=temp;
            }
            
        }
        
    }
    
    
}