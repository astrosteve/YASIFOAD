// This file contains everything related to the dungeons themselves. Actions within the dungeons may or may not be broken up into different files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    while (loop < curdun[choice].rooms)   // Generate rooms to explore.
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

void enemyinit()   // Creating an enemy for the current room.
{
    int idnum;

    idnum = 0; // reset counter

    idnum = range(0,(enemytotal-1)); // Select a random number between 0 and (enemytotal - 1) since stanen starts at 0
    strcpy(curnpc.name, stanen[idnum].name); // Copy over the name from the standard enemies table. Just for the record, it took me 20 minutes to make this stupid line work.
    curnpc.id = stanen[idnum].id; // Copy over ID and so on and so on for rest of block.
    curnpc.race = stanen[idnum].race;
    curnpc.str = stanen[idnum].str;
    curnpc.dex = stanen[idnum].dex;
    curnpc.con = stanen[idnum].con;
    curnpc.intel = stanen[idnum].intel;
    curnpc.wis = stanen[idnum].wis;
    curnpc.cha = stanen[idnum].cha;
    curnpc.hp = stanen[idnum].hp;
    curnpc.level = stanen[idnum].level;
    curnpc.attack = stanen[idnum].attack;
    curnpc.defense = stanen[idnum].defense;
    curnpc.damage = stanen[idnum].damage;
    curnpc.weapon = stanen[idnum].weapon;
    curnpc.money = stanen[idnum].money;
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
