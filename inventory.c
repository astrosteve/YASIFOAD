// Inventory code

#include "struct.h"

struct items stanit[itemtotal] = // Standard Item Table. Starts at 0.
{  // Name, Description, Weight, Type, WeaponType, ArmorType
    {"null", "null", 0, 0, 0, 0},
    {"Graybay Tour Guide", "In case you ever happen to go to Graybay, here's all the coolest stuff there.", 5, 3, 0, 0},
    {"Pachinko Maintenance Manual", "Now you know how to fix a pachinko machine!", 5, 3, 0, 0},
    {"Sword of Cienfuegos", "Sword crafted by the mighty blacksmith Cienfuegos", 8, 1, 0, 0}
};

struct itemtype itemtypes[typetotal] = // Categories items can fall into.
{
    {"Weapon"}, {"Armor"}, {"Book"}
};

struct weapon npcweap[weapontotal] =   // STARTS AT 0. Null is 0, A Sword is 1, a Mace is 2.
{
    //  Name, type, quantity, sides, damage
    {"null", 0, 0, 0 , 0},
    {"sword", 1, 1, 10, 1},
    {"mace", 2, 1, 8, 2},
    {"club", 2, 1, 6, 2}

}; // Even though it says npcweap, it's going to be used for the player as well.

struct armor armortype[armortotal] = {

    // Name, Description, slot, ac
    {"breastplate", "a standard breastplate", chestslot, 6},
    {"leather helmet", "a boring leather helmet", headslot, 3},
    {"leather boots", "stiff leather boots", feetslot, 3}

};


void initinv(void) { // Used for clearing out inventory in event of death or other event that clears inventory.
    int loop;
    loop = 0; // Initialize for use

    while (loop <= invslot) {
        inven[loop].slot = 0; // Set everything to 0 to clear out player inventory.
        loop++;
    }
};

void cleararmor(void) { // Clear armor slots.

    pc.head = 0;
    pc.arms = 0;
    pc.chest = 0;
    pc.legs = 0;
    pc.feet = 0;
    pc.ringr = 0;
    pc.ringl = 0;
    pc.neck = 0;

};

void startinv(void) {

    inven[0].slot=2;
    inven[1].slot=1;
    inven[2].slot=3; // Giving one of each existing item.

};
