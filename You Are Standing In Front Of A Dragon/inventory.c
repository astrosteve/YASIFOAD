// Inventory code

#include "struct.h"

struct items stanit[itemtotal] = // Standard Item Table. Starts at 0.
{  // Name, Weight, Type, WeaponType
    {"null", "null", 0, 0, 0},
    {"Graybay Tour Guide", "In case you ever happen to go to Graybay, here's all the coolest stuff there.", 5, 3, 0},
    {"Pachinko Maintenance Manual", "Now you know how to fix a pachinko machine!", 5, 3, 0},
    {"Sword of Cienfuegos", "Sword crafted by the mighty blacksmith Cienfuegos", 8, 1, 0}
};

struct itemtype itemtypes[typetotal] = // Categories items can fall into.
{
    {"Weapon"}, {"Armor"}, {"Book"}
};

struct weapon npcweap[weapontotal] =   // STARTS AT 0. A Sword is 0, a Mace is 1.
{
    //  Name, type, quantity, sides, damage
    {"sword", 1, 1, 10, 1},
    {"mace", 2, 1, 8, 2},
    {"club", 2, 1, 6, 2}

}; // Even though it says npcweap, it's going to be used for the player as well.
