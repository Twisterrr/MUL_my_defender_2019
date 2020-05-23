/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

void create_wave_three(char *my_wave, int *new_type, int *type, int *i)
{
    if (is_num(my_wave[*i]) == 1)
            *new_type = 0;
    if (*new_type == 0 && is_num(my_wave[*i]) == 1) {
        *new_type = 1;
        *type = my_wave[*i] - '0';
        *i += 3;
    }
}