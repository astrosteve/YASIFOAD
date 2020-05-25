// This file is for general-purpose, reusable routines like random number generators, rolls, etc.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

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
	return min + (int) (rand() / (double) (RAND_MAX/2 + 1)* 2.0);
}

int roll (int quantity, int sides)   // Roll an arbitrarily sided die an arbitrary number of times.
{
    int result, count;
    count = 0;
    result = 0;

    do
    {
//      result = result + rand() % (sides) + 1; // Rand rolls 0-19. Original code, obsolete now. Left in for reference.
        result = result + range(1, sides);
        count++;
    }
    while (count != quantity); // count == quality means all dice have been rolled.
    // printf("Die roll result is %i \n", result);
    return result;
}