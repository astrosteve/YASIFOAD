// This file contains everything related to the main menu loop of the game.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

#define duntotal 3 // Total number of dungeons + 1 as array entry 0 is padding.

struct dungeon curdun[duntotal] =   // Hardcoded dungeons for now.
{
    {"null", "Should never be seen", 0, 0, 0},
    {"The Test Dungeon 1", "A smelly dungeon", 5, 65, 0},
    {"The Test Dungeon 2", "A slightly nicer dungeon", 8, 75, 6}
};


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

void dungeon()
{
    int loop, choice;
    loop = 1;

    // createdungeon(); // Creates dungeon. Dungeons currently hardcoded, this is for procedural generation.
    printf("Available Dungeons:\n");
    while (loop < duntotal)
    {
        printf("%i. %s\n", loop, curdun[loop].name);
        loop++;
    }
    printf("Which dungeon? ");
    scanf("%d", &choice);
    exploredungeon(choice);

};


void exploredungeon (int choice)
{
    struct room currentroom[curdun[choice].rooms];
    char roomdesc[14];
    int loop;

    loop = 0;

    while (loop < curdun[choice].rooms)   // Generate rooms to explore. Will be procedural at some point.
    {
        strcpy(roomdesc, "Test Room"); // Eventually, this'll be procedurally generated.
        strcpy(currentroom[loop].desc, roomdesc);
        currentroom[loop].enemy = 1; // 0 = no enemy, 1 = enemy
        loop++;
    }
    loop = 0;
    while (loop < curdun[choice].rooms)
    {
        clear();
        printf("You are in %s.\n", currentroom[loop].desc);
        printf("You are in room %i, you have %i more to explore.\n", (loop + 1), (curdun[choice].rooms - (loop+1)));
        if ((currentroom[loop].enemy) == 1)   // If enemy is present.
        {
            enemyinit(); // enemyinit randomly selects a creature from stanen and assigns to curnpc
            fight(); // Uses curnpc to have fight.
            if (pc.alive == false)
            {
                printf("You died, but we're overlooking it for now.\n");
                // Change this once you figure out how death works.
                pc.hp = pc.hptotal;
                pc.alive = true;
                getchar();
            }
        }

        loop++;
    }
    if (pc.alive == true)
    {
        printf("You survived the dungeon! Congrutalions!\n");
        pc.hp = pc.hptotal;
    }
};



/* Original code. Left in for reference.
void createdungeon() { // This will eventually be procedural, but that's a bit off.

    strcpy(curdun.name, "Test Dungeon 1");
    strcpy(curdun.RoomDesc, "A smelly dungeon");
    curdun.rooms = 5;
    curdun.npcc = 65;
    curdun.npcl = 0;

};
*/
