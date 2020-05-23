/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_cursor
*/

#include "my.h"
#include "struct.h"

cursor *init_cursor(void)
{
    cursor *cur = malloc(sizeof(*cur));
    cur->cursor = create_sprite("Ressources/Images/Util/cursor.png");
    cur->idle = (sfIntRect) {332, 140, 65, 100};
    cur->press = (sfIntRect) {120, 150, 93, 85};
    cur->choose = 0;
    cur->clock = sfClock_create();
    return (cur);
}