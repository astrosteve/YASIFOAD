/* Game Structures. */

#include <stdbool.h>

void chargen(void);
void RoomGen(void);
void explore(void);
void npcgen(void);
void ItemGen(void);
int fight(void);
int range(int min, int max);
void enemyatk(void);
void clear(void);
struct playchar pc; // Player is of struct player
int roll (int quantity, int sides);
// All voids above are used in main.c
void mainmenu(void); // Main game loop.
void dungeon(void); // pick & adventure through dungeon
void createdungeon(void);
void enemyinit(void);
int exploredungeon(int choice);
void genchar(void);
// void generaterooms(int roomtotal); // Obsolete, integrated into exploredungeon
struct npc curnpc; // Current NPC in the room



struct playchar // PC data structure.
{
    char name[30];
    int race;
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
