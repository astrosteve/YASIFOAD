#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "struct.h"
#include "generators.h"

int parser (char); // Not used yet, unsure if a parser routine is needed.

int main()
{
    srand (time(NULL)); /* Seeding the random number generator. Might want to implement a mersenne twister or similar in the future.*/
    initinv(); // Initialize inventory. This isn't strictly necessary, but I'm doing it to be safe.
    startinv(); // Hard coded starting inventory, using for testing. Temporary.
    genchar(); // Generate character
    mainmenu(); // Call main game menu.


    getch(); // Pauses
    return 0;

}

int fight(void)   /* Gonna beat on some monsters. */
{
    int choice, result; // Only needed for fight
    result = 1; // 3 or 4 means combat ended. Anything else continues.
    enemyinit(); // Select random enemy. from generators.h

    while (result < 3)   // 3 indicates enemy death, 4 indicates player death. Slowly changing it to work off pc.alive == true/false
    {                    // result == 5 means inventory or other action that necessitates reprinting of menu.
        printf("You are standing in front of a %s.\n", curnpc.name);
        printf("Your hitpoints are %i.\n\n", pc.hp);
        printf("Your options:\n");
        printf("1. Attack\n");
        printf("2. Check inventory\n");
        printf("99. Run Away!!\n");
        printf("Command? ");
        // Put an error check here at some point to look for out of range entries
        scanf("%d", &choice);
        clear();
        result = fighting(curnpc.level, choice); // Call fighting to parse the action. Is this really how I want to be doing this?
        // printf("Result is %d\n", result); // Debug statement
    }

    if (result == 3) // I should probably create a npcdead boolean to mimic pc.alive and stop using the result system.
    {
        printf ("You have successfully killed the %s!\n", curnpc.name);
        return result; // return result for processing.
    }
    if (pc.alive == false)
    {
        printf ("You have been killed by the %s!\n", curnpc.name);
        result = 4;
        return result; // return result for processing.
    }
return result;
};


int fighting(int lvl, int choice)   // This is the "fight engine" so to speak. Why is it separate from Fight? I don't remember. Because I'm an incompetent coder, probably.
{
    // One execution of this function is intended to be one turn for the player. All possible actions to take should be built into this function.
    int damage, playatk; // playatk is the player's attack roll.
    int loop; // For displaying inventory

    if (choice == 1)
    {
        printf ("You attack the %s!\n", curnpc.name);
        playatk = (pc.attack + roll(1,20)); // Roll d20 for attack
        if (playatk >= curnpc.defense)
        {
            damage = roll(1,8) + pc.damage; // Hardcoded PC weapon needs to be fixed.
            printf("You hit for %i points!\n", damage);
            curnpc.hp = curnpc.hp - damage;
            printf("%s has %i hp left!\n", curnpc.name, curnpc.hp);
            if (curnpc.hp > 0)   //If enemy is left alive, it may counter attack. This is going to get dicey if I ever add multiple NPCs per room.
            {
                enemyatk();
            }
            if (curnpc.hp <= 0)
            {
                choice = 3;
                printf("You have killed the %s!\n", curnpc.name);
                printf("You got %i gold!\n", curnpc.money); // Give some gold!
                pc.money = pc.money + curnpc.money;
                return choice;
            }

        }
        if ((playatk) <= curnpc.defense)
        {
            printf("Your attack misses!\n");
            enemyatk(); // NPC survived, so he gets to attack now.
            // Death check should go here once I figure out how death works.
        }

    }

    if (choice == 2) { // Display inventory
        loop = 0;

        while (loop <= (invslot)) { // Go through inven and display all non-0 slots.

            if (inven[loop].slot > 0) {
            printf("%i. %s - %s\n", loop, (stanit[inven[loop].slot].name), (stanit[inven[loop].slot].desc)); // Cross reference integer in inven with stanit
            }
            loop++;
        }
        printf("\n");
}

    if (choice == 99)
    {
        printf ("Argh, you're running away! You coward!\n");
    }
    return choice;
};

void enemyatk()   // One execution of this function is intended to be one turn for the npc. All possible actions to take should be built into this function.
{
    int atkfinal, choice; // atkfinal was originally known as diagnose and was a debug thing. It turned out to be so useful it's now a non-debug thing.
    atkfinal = (curnpc.attack + roll(20, 1)); // Roll d20, add attack bonus.
    curnpc.damage = 0; // Reset to 0 from previous run.

//   printf("D20 for enemy is %i", (diagnose - curnpc.attack)); // debug statement
    printf ("The %s attacks you with its %s. ", curnpc.name, (npcweap[curnpc.weapon].name)); // Cross references curnpc and npcweap
    if (atkfinal >= pc.defense)   // Successful hit
    {
        curnpc.damage = roll((npcweap[curnpc.weapon].quantity),(npcweap[curnpc.weapon].sides)) + curnpc.damage; // This makes my head hurt, but it determines curnpc's weapon dice roll by looking it up on npcweap. Figured it was easier this way than copying the weapon data into a new place.
        printf("It hits you for %i points!\n", curnpc.damage);
        pc.hp = pc.hp - curnpc.damage;
        printf("You have %i hp left!\n", pc.hp);
        if (pc.hp <= 0)
        {
            pc.alive = false;
            // Currently, the game doesn't recognize you're dead until you complete the current dungeon. Since I'm not sure how death will work, I'm
            // leaving it this way until I figure out what should happen if the player dies. Better for testing, anyway.
        }
    }
    if (atkfinal <= pc.defense)
    {
        printf("It misses you!\n"); // Should only ever show if enemy misses.
    }
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

void initinv(void) { // Used for clearing out inventory in event of death or other event that clears inventory.
    int loop;
    loop = 0; // Initialize for use

    while (loop <= invslot) {
        inven[loop].slot = 0; // Set everything to 0 to clear out player inventory.
        loop++;
    } // 25 is current inventory slots. Should match inven
};

void startinv(void) {

    inven[0].slot=1;
    inven[1].slot=2;
    inven[2].slot=3; // Giving one of each existing item.

};
