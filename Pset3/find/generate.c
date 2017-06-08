/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // If atleast one command line argument is not provided, print the output and reutrn 1 and if more than 2 command line arguments are provided, do the same as well.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Taking the first command line arguemnt provided, converting it to an int and storing it in a variable called n.
    int n = atoi(argv[1]);

    /*If a second command line argument is provided, use that number to seed the random number generation via the srand48 method.
     * Use the atoi method to convert the input to an int and then type cast that to a long it so that it can be inputted into the srand48 function.
     *If the second command line arugment is not provided, call the srand48 method on NULL (meaning don't use a specific number as a seed).
    */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    /* Print out n random numbers, where n was the first command line argument provided. Generate
     *the random numbers by using the drand48 method, and multypling what the method returns by 65536 and then converting the result to an int.
     */
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}