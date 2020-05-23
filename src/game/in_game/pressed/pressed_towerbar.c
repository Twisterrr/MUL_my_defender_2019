/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void pressed_towerbar(all *all, clicked *c)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(all->w);

    if ((m.x >= 665 && m.x <= 815) && (m.y >= 920 && m.y <= 1000)) {
        c->state = 1;
        c->type = BOMB_TOWER;
    }
    if ((m.x >= 820 && m.x <= 970) && (m.y >= 920 && m.y <= 1000)) {
        c->state = 1;
        c->type = SNIPER_TOWER;
    }
    if ((m.x >= 975 && m.x <= 1125) && (m.y >= 920 && m.y <= 1000)) {
        c->state = 1;
        c->type = COLD_TOWER;
    }
    if ((m.x >= 1030 && m.x <= 1170) && (m.y >= 920 && m.y <= 1000)) {
        c->state = 1;
        c->type = ARROW_TOWER;
    }
}