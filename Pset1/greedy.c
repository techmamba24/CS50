
 /* greedy.c
 * Aamel Unia
 * aameluni@buffalo.edu
 * Simple program which asks user how much change is owed and then calculates and prints out 
   the minimum number of coins with which the change owed can be paid be back.
 */

#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main (void){
    
float input;

  do{
   printf("Enter change owed: ");   
   input=GetFloat();
  }  
    while(input<=0);

int change = (int) round(input*100);
// printf("Int conversion rounded: %i \n", change);

int coins=0;

while (change!=0){
    
if (change/25!=0){
coins += change/25;
change = change%25;
}

else if(change/10!=0){
coins += change/10;
change = change%10;
}

else if(change/5!=0){
coins += change/5;
change = change%5;
}

else {
coins += change/1;
change = change%1;
}

}
printf("%i\n", coins);
    
}
