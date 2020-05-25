// This is the main routine of the program. Program flow stuff goes here. Other stuff should go elsewhere.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"
#include "generators.h"
#include "utility.c"
#include "mainmenu.c"
#include "character.c"
#include "inventory.c"
#include "dungeon.c"
#include "combat.c"

int parser (char); // Not used yet, unsure if a parser routine is needed.

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