/* Generator functions, mainly weapons and armor */
/* Copyblahblahblah by some person */


#define enemytotal 3 /* Count for the total number of npcs defined in genenemies. */
/* This should never change during execution, so it's constant. */
/* I used #define so it could initlize the array, as opposed to const int */
#define weapontotal 3 // Total number of weapons in npcweap.
#define itemtotal 4 // Total number of entries in stanit.
#define typetotal 4 //Total number of entries in itemtypes

struct npc stanen[enemytotal] =   // Array that holds npc data. This is for "standard" (not procedurally generated) enemies.
{   // Name, ID, race, str, dex, con, intel, wis, cha, hp, level, attack, defense, damage, weapon, money
    {"Skeleton", 1, 1, 6, 13, 8, 6, 4, 3, 8, 1, 6, 12, 3, 0, 15},
    {"Goblin", 2, 1, 6, 13, 8, 6, 4, 3, 8, 1, 6, 12, 3, 1, 15},
    {"Kobold", 3, 1, 6, 12, 7, 7, 3, 5, 8, 2, 2, 10, 3, 2, 15}

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


struct itemtype itemtypes[typetotal] = // Categories items can fall into.
{
    {"Weapon"}, {"Armor"}, {"Book"}
};

struct items stanit[itemtotal] = // Standard Item Table. Starts at 0.
{  // Name, Weight, Type, WeaponType
    {"null", "null", 0, 0, 0},
    {"Graybay Tour Guide", "In case you ever happen to go to Graybay, here's all the coolest stuff there.", 5, 3, 0},
    {"Pachinko Maintenance Manual", "Now you know how to fix a pachinko machine!", 5, 3, 0},
    {"Sword of Cienfuegos", "Sword crafted by the mighty blacksmith Cienfuegos", 8, 1, 0}
};

struct weapon npcweap[weapontotal] =   // STARTS AT 0. A Sword is 0, a Mace is 1.
{
    //  Name, type, quantity, sides, damage
    {"sword", 1, 1, 10, 1},
    {"mace", 2, 1, 8, 2},
    {"club", 2, 1, 6, 2}

}; // Even though it says npcweap, it's going to be used for the player as well.

void genchar(void) {
    char ans[1]; // For answering questions
    int ansi; // answer integer
    ansi = 2; // default state for loop to start.

    printf("Welcome to the RPG game.\n");
    printf("What is your name, adventurer? ");
    scanf(" %[^\n]", pc.name); // This should probably have error checking of some sort.
    printf("Welcome, %s.\n", pc.name);
    // Generate stats.
    while (ansi == 2) {
    pc.str = roll(3,6); // Standard 3d6 roll.
    pc.dex = roll(3,6);
    pc.con = roll(3,6);
    pc.intel = roll(3,6);
    pc.wis = roll(3,6);
    pc.cha = roll(3,6);
    pc.hptotal = 50; // Players always start out with 50.
    pc.hp = pc.hptotal;

    printf("Your stats are: STR: %i, DEX: %i, CON: %i, INT: %i, WIS: %i, CHA: %i, HP: %i\n", pc.str, pc.dex, pc.con, pc.intel, pc.wis, pc.cha, pc.hptotal);
    printf("1. Keep stats\n");
    printf("2. Reroll\n");
    printf("Command? ");
    scanf(" %[^\n]", ans); // scanf has to have character string.
    ansi=atoi(ans); // atoi doesn't exist on Linux/Mac. Porting will require modification.

    };

};
