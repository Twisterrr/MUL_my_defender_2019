/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_all
*/

#include "my.h"
#include "struct.h"

void init_arrow(tower *t)
{
    t->cost = 200;
    t->damage = 45;
    t->firerate = 0.5;
    t->range = 4;
    t->rect = (sfIntRect) {0, 266, 55, 75};
}

void init_bomb(tower *t)
{
    t->cost = 440;
    t->damage = 35;
    t->firerate = 1.25;
    t->range = 6;
    t->rect = (sfIntRect) {0, 182, 52, 74};
}

void init_cold(tower *t)
{
    t->time_slowed = 15;
    t->cost = 300;
    t->damage = 25;
    t->firerate = 1;
    t->range = 5;
    t->rect = (sfIntRect) {0, 108, 52, 70};
}

void init_sniper(tower *t)
{
    t->cost = 400;
    t->damage = 500;
    t->firerate = 3;
    t->range = 10;
    t->rect = (sfIntRect) {165, 266, 48, 70};
}