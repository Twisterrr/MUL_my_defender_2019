/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

li_monster *enemy_in_range(int r, sfVector2i pt, li_monster *li, int *a)
{
    *a = 0;
    li_monster *wave = li;
    while (wave != NULL) {
        monster *elem = wave->first;
        while (elem != NULL) {
            *a += 1;
            if ((elem->tab_pos.x < pt.x + r && elem->tab_pos.x > pt.x - r\
            ) && (elem->tab_pos.y < pt.y + r && elem->tab_pos.y > pt.y - r)\
            && elem->state == ALIVE)
                return (wave);
            elem = elem->next;
        }
        *a = 0;
        wave = wave->next_wave;
    }
    return (NULL);
}

void damage_all_2(monster *mn, monster *elem, li_monster *li, hud *hud)
{
    if (elem->life <= 0 && elem != mn) {
        sfSound_play(li->death);
        if (elem->type == GOBELIN)
            hud->coin->value += 15;
        if (elem->type == CROC)
            hud->coin->value += 35;
        if (elem->type == BOSS)
            hud->coin->value += 100;
        elem->state = DEAD;
    }
}

void damage_all(monster *mn, li_monster *liste, tower *t, hud *hud)
{
    li_monster *li = liste;
    monster *elem;
    int a = 1;
    while (li->prev_wave != NULL)
        li = li->prev_wave;
    while (li != NULL) {
        elem = li->first;
        while (elem != NULL) {
            if (elem->state == ALIVE && mn->tab_pos.x < elem->tab_pos.x + 4 && \
            mn->tab_pos.x > elem->tab_pos.x - 4 && mn->tab_pos.y < \
            elem->tab_pos.y + 4 && mn->tab_pos.y > elem->tab_pos.y - 4) {
                elem->life -= t->damage;
                damage_all_2(mn, elem, li, hud);
            }
            elem = elem->next;
        }
        a++;
        li = li->next_wave;
    }
}

void fire(int nb, tower *t, li_monster *li, hud *hud)
{
    monster *elem = li->first;
    for (int a = 1 ; a != nb ; a++)
        elem = elem->next;
    if (t->type == COLD_TOWER)
        elem->slowed = t->time_slowed;
    if (t->type == BOMB_TOWER)
        damage_all(elem, li, t, hud);
    elem->life -= t->damage;
    if (elem->life <= 0) {
        sfSound_play(li->death);
        if (elem->type == GOBELIN)
            hud->coin->value += 15;
        if (elem->type == CROC)
            hud->coin->value += 35;
        if (elem->type == BOSS)
            hud->coin->value += 100;
        elem->state = DEAD;
    }
    sfClock_restart(t->c_shoot);
}

void tower_attack(game *game)
{
    int a = 0;
    if (game->t_li->first != NULL) {
        tower *elem = game->t_li->first;
        while (elem != NULL) {
            if (sfTime_asSeconds(sfClock_getElapsedTime(elem->c_shoot)) \
            >= elem->firerate) {
                li_monster *li = enemy_in_range(elem->range, elem->tab_pos, \
                game->li, &a);
                if (a != 0)
                    fire(a, elem, li, game->hud);
                a = 0;
            }
            elem = elem->next;
        }
    }
}