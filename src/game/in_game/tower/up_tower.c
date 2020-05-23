/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void up_bomb(tower *t)
{
    if (t->level == 1) {
        t->firerate -= 0.10;
        t->damage += 10;
        t->range += 1;
    } else {
        t->firerate -= 0.15;
        t->damage += 20;
        t->range += 2;
    }
    t->level += 1;
}

void up_arrow(tower *t)
{
    if (t->level == 1) {
        t->firerate -= 0.2;
        t->damage += 15;
        t->range += 1;
    } else {
        t->firerate -= 0.2;
        t->damage += 30;
        t->range += 1;
    }
    t->level += 1;
}

void up_cold(tower *t)
{
    if (t->level == 1) {
        t->firerate -= 0.10;
        t->damage += 15;
        t->range += 2;
        t->time_slowed += 15;
    } else {
        t->firerate -= 0.10;
        t->damage += 15;
        t->range += 2;
        t->time_slowed += 30;
    }
    t->level += 1;
}

void up_sniper(tower *t)
{
    if (t->level == 1) {
        t->firerate -= 0.5;
        t->damage += 150;
        t->range += 3;
    } else {
        t->firerate -= 0.5;
        t->damage += 300;
        t->range += 5;
    }
    t->level += 1;
}

void up(tower *t, game *game)
{
    game->hud->coin->value -= t->cost;
    t->rect.left += t->rect.width;
    t->cost += t->cost;
    switch (t->type) {
        case BOMB_TOWER :
            up_bomb(t);
            break;
        case COLD_TOWER :
            up_cold(t);
            break;
        case SNIPER_TOWER :
            up_sniper(t);
            break;
        case ARROW_TOWER :
            up_arrow(t);
            break;
    }
}