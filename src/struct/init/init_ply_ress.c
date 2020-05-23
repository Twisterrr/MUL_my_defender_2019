/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_money
*/

#include "my.h"
#include "struct.h"

ply_ress *init_ply_ress(sfIntRect rect, sfVector2f pos,
                                char *texture, int value)
{
    ply_ress *c = malloc(sizeof(*c));
    c->sprite = create_sprite(texture);
    c->rect = rect;
    c->pos = pos;
    if (value != 20)
        sfSprite_scale(c->sprite, (sfVector2f) {2, 2});
    else
        sfSprite_scale(c->sprite, (sfVector2f) {1.5, 1.5});
    c->value = value;
    c->clo = sfClock_create();
    return (c);
}