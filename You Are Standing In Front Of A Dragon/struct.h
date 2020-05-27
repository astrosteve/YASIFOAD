/* Game Structures. */

#ifndef STRUCT_H
#define STRUCT_H
#endif

#include <stdbool.h>

#define invslot 25 // Total inventory slots.
#define weapontotal 3 // Total number of weapons in npcweap.
#define itemtotal 4 // Total number of entries in stanit.
#define typetotal 4 //Total number of entries in itemtypes
#define armortotal 3 // Number of items in armor table.


void chargen(void);
void RoomGen(void);
void explore(void);
void npcgen(void);
void ItemGen(void);
int fight(void);
int range(int min, int max);
void enemyatk(void);
void clear(void);
void initinv(void);
void startinv(void);
struct playchar pc; // Player is of struct player
int roll (int quantity, int sides);
int fighting (int lvl, int choice); // Fighting routine. Returning 1 means enemy is dead. Anything else = alive.
// struct weapon curweap; // I honestly can't even remember what this was supposed to be for.
// All voids above are used in main.c

void mainmenu(void); // Main game loop.
void dungeon(void); // pick & adventure through dungeon
void createdungeon(void);
void enemyinit(void);
void exploredungeon(int choice);
void genchar(void);
// void generaterooms(int roomtotal); // Obsolete, integrated into exploredungeon
void cleararmor(void);
struct npc curnpc; // Current NPC in the room

struct inventory { // Trying to do this as an array of integers failed for some reason, so doing it a way I k

    int slot; // Integer for slot number.

};

struct inventory inven[invslot]; // Player inventory slots. Can carry up to invslot things. Limit is arbitrary, can be changed.


struct playchar // PC data structure.
{
    char name[30];
    int race;
    int cclass; // Not sure how classes will work. cclass because class is reserved already.
    int str;
    int dex;
    int con;
    int intel;
    int wis;
    int cha;
    int hp;
    int hptotal;
    int level;
    int attack;
    int defense;
    int damage;
    int money;
    int head; // Head equipment slot. Integer corresponds to spot in Armor array
    int arms; // Armor slot
    int chest; // Armor slot
    int legs; // Armor slot
    int feet; // Armor slot
    int ringr; // Right hand ring
    int ringl; // Left hand ring
    int neck; // Armor slot, for necklaces, amulets, etc.
    int gender; // M/F/Other
    bool alive;
};

struct npc
{
    char name[30];
    int id; // ID for creature. No longer needed as everything is an array now.
    int race;
    int str;
    int dex;
    int con;
    int intel;
    int wis;
    int cha;
    int hp;
    int level;
    int attack; // Attack value. die + attack for determining attack.
    int defense; // Defense stat. Effectively is Armor Class.
    int damage; // attack damage.
    int weapon; // Enemies' weapon. Number should correspond to npcweap array.
    int money;
};
// Two structures for now in case I want to change something about PCs but not NPCs or vice versa.

struct weapon
{
    char name[30]; // Weapon name.
    int type; // Type of weapon. 1h sword, 2h sword, mace, staff, etc. Not implemented yet.
    int quantity; // Number part of die. ie, 5d10 or 2d10 or whatever.
    int sides; // quantity & sides represent die roll. 1d6. quantity is 1, sides is 6
    int damage; // Piercing, stabbing, etc. Not implemented yet.
};

struct weapon npcweap[weapontotal];

struct itemtype
{
    char desc[45];
    // struct in case I ever need to add more information.
};



struct items {

    char name[30]; // Item name
    char desc[160]; // Short description of item.
    int weight; // Weight of item
    int type; // Item type. Weapon, book, armor, etc.
    int weaptype; // Integer referring
    // I feel like there needs to be more here but cannot think of anything else.
};

struct items stanit[typetotal];

struct dungeon   // This entire thing will be changed once I seriously implement dungeons.
{
    char name[25]; /* Name. Not yet implemented. */
    char RoomDesc[60]; /* Currently not used, but should eventually contain a short room description, preferably procedurally generated.*/
    int rooms; /* number of rooms in dungeon */
    int npcc; /* Percent chance of an NPC spawning in a room. */
    int npcl; /* Hard limit of NPCs in dungeon. Once you get to this number, no more NPCs generate randomly. 0 means no limit */
};

struct room {

    char desc[25]; // short description, procedurally generated eventually.
    int enemy; // ID number of enemy from stanen
    int item1; // Two item slots for room. Items currently not implemented.
    int item2; // Want to explore the idea of unlimited items per room, but unsure how to do that.
};

struct armor {

    char name[30]; // Name of armor
    char desc[160]; // Longer description of armor.
    int slot; // Slot armor is worn on. References armorslot table
    int ac; // Armor Class

};

struct armor armortype[armortotal];

// Slot definitions.
// Can use slot name instead of having to remember numbers. Also make it easier to change slot number if needed for some reason.

#define headslot 1
#define chestslot 2
#define legslot 3
#define feetslot 4
#define ringrslot 5
#define ringlslot 6
#define neckslot 7


