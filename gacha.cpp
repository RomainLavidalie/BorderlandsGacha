#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

#include "gacha.h"

// Fonction de randomisation avec bornes
int random_int(int min, int max)
{
    return min + rand() % (max + 1 - min);
};

// Malloc pour init un tableau correctement
char** createCharTable(int w, int h)
{
    char** tab = NULL;
    tab = (char**)malloc(h * sizeof(char*));
    if (tab == NULL) {
        fprintf(stderr, "Probleme allocation dynamique dans nouvelle_image erreur -> %d", errno);
        exit(0);
    }
    for (int i = 0; i < h; i++) tab[i] = (char*)malloc(w * sizeof(char));
    return tab;
}

// fonction du gacha
void gacha()
{
    // setup random_int
    srand(time(NULL));

    // values
    int currentLevel = 0;
    int level;
    int i = 1;

    char weaponManufacturer[9][16] = { "Atlas", "CoV", "Dahl", "Hyperion", "Jakobs", "Maliwan", "Tediore", "Torgue", "Vladof" };
    char weaponType[6][16] = { "Handgun", "Shotgun", "Assault Rifle", "SMG", "Sniper", "Heavy Weapon" };
    char weaponRarity[4][16] = { "Common", "Uncommon", "Rare", "Very Rare" };

    // résultats
    int manufacturerPick;
    int typePick;
    int rarityPick;

    // query du level du joueur
    printf("Current level : ");
    scanf("%d", &currentLevel);

    // pull + affichage des pulls
    for (i = 0; i < 9; i++)
    {
        manufacturerPick = random_int(0, 8);
        typePick = random_int(0, 5);
        rarityPick = random_int(0, 3);
        level = random_int(currentLevel - 5, currentLevel + 5);

        printf("Level %d %s %s %s\n", level, weaponRarity[rarityPick], weaponManufacturer[manufacturerPick], weaponType[typePick]);
    };
    printf("Press ENTER key to close\n");
    int pause = scanf("%d", &pause);
};
