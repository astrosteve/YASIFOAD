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

void initinv(void) { // Used for clearing out inventory in event of death or other event that clears inventory.
    int loop;
    loop = 0; // Initialize for use

    while (loop <= invslot) {
        inven[loop].slot = 0; // Set everything to 0 to clear out player inventory.
        loop++;
    } // 25 is current inventory slots. Should match inven
};

void startinv(void) {

    inven[0].slot=2;
    inven[1].slot=1;
    inven[2].slot=3; // Giving one of each existing item.

};
