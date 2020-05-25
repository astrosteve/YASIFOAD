#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

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
