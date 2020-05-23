/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_all
*/

#include "my.h"
#include "struct.h"

clicked *init_clicked_on(void)
{
    clicked *c = malloc(sizeof(*c));
    c->state = 0;
    c->type = 0;
    c->int_range = 0;
    c->range = sfRectangleShape_create();
    sfRectangleShape_setFillColor(c->range, sfTransparent);
    sfRectangleShape_setOutlineThickness(c->range, 2);
    sfRectangleShape_setOutlineColor(c->range, sfRed);
    c->tower = create_sprite("Ressources/game/map/Towers.png");
    sfSprite_scale(c->tower, (sfVector2f) {1.5, 1.5});
    c->rect_t1 = (sfIntRect) {0, 182, 52, 74};
    c->rect_t2 = (sfIntRect) {165, 266, 48, 70};
    c->rect_t3 = (sfIntRect) {0, 108, 52, 70};
    c->rect_t4 = (sfIntRect) {0, 266, 55, 75};
    return (c);
}