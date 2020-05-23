/*
** EPITECH PROJECT, 2020
** defend
** File description:
** init_button
*/

#include "my.h"
#include "struct.h"

char **get_map(FILE *fil)
{
    char **ret = malloc(sizeof(char *) * (23));
    size_t size = 40;

    for (int i = 0 ; i != 22 ; i++) {
        ret[i] = NULL;
        getline(&ret[i], &size, fil);
    }
    ret[22] = NULL;
    return (ret);
}

char **get_wave(FILE *fil)
{
    char **ret = malloc(sizeof(char *) * (23));
    size_t size = 40;
    int i = 0;
    int a = 0;

    ret[a] = NULL;
    while (i != -1) {
        ret[a] = NULL;
        i = getline(&ret[a], &size, fil);
        a++;
    }
    ret[a - 1] = NULL;
    return (ret);
}

lvl *init_level(char *file)
{
    lvl *lvl = malloc(sizeof(*lvl));
    FILE *fil = fopen(file, "r");
    lvl->map = get_map(fil);
    lvl->wave = get_wave(fil);
    fclose(fil);
    return (lvl);
}