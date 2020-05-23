/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

#include "my.h"

int len_tab(char **tab)
{
    int i = 0;
    while (tab[i] != NULL)
        i++;
    return (i);
}