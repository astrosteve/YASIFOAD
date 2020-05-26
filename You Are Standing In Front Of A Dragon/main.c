#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"
#include "generators.h"

int main()
{
    srand (time(NULL)); /* Seeding the random number generator. Might want to implement a mersenne twister or similar in the future.*/
    initinv(); // Initialize inventory. This isn't strictly necessary, but I'm doing it to be safe.
    startinv(); // Hard coded starting inventory, using for testing. Temporary.
    genchar(); // Generate character
    mainmenu(); // Call main game menu.


    getchar(); // Pauses
    return 0;

}

void clear(){ // Written by nbro on stackoverflow. see https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c
    #if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif
}

int range(int min, int max) // Better random number generation for small numbers. eg, 0 and 1.
{
  return min + (int) (rand() / (double) (RAND_MAX + 1) * (max - min + 1));
}

int roll (int quantity, int sides)   // Roll an arbitrarily sided die an arbitrary number of times.
{
    int result, count;
    count = 0;
    result = 0; // Reset variables from last run.

    do
    {
//      result = result + rand() % (sides) + 1; // Rand rolls 0-19. Original code, obsolete now. Left in for reference.
        result = result + range(1, sides);
        count++;
    } while (count != quantity); // count == quality means all dice have been rolled.
    // printf("Die roll result is %i \n", result);
    return result;
}
