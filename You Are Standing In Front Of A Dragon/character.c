// This file is for anything character-related. Generation.. leveling-up.. that kind of stuff.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

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

