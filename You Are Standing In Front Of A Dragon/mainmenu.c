// GAME 42! THE GAME OF YOUR LIFE IN A DUNGEON!

// This file contains everything related to the main menu loop of the game.
// Dungeon-related stuff has been moved to a separate file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mainmenu()
{
    int choice;

    clear();

    do   // Main game loop
    {
        printf("Main Menu:\n");
        printf("1. Explore a Dungeon\n");
        printf("2. Do something not implemented in the game yet.\n");
        printf("3. Exit the game like a scared baby\n\n");
        printf("Choice? ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            dungeon();

        }

        if (choice == 2)
        {
            printf("You cheeky bastard! You know this doesn't exist yet!\n I will have to now self destruct!\n");
            return;
        }

    }
    while (choice != 3);
};