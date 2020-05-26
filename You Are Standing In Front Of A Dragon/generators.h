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