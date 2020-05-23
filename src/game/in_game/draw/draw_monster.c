/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

void draw_monster_life_two(li_monster *li, sfRenderWindow *w,
                                        monster *elem, float p)
{
    if (elem->state == ALIVE && MONSTER(elem->type)) {
        sfRectangleShape_setPosition(elem->showlife_black, elem->pos);
        sfRectangleShape_setPosition(elem->showlife_green, elem->pos);
        p = 100.0 * (float) elem->life / (float) elem->full_life;
        sfRectangleShape_setSize(elem->showlife_black, \
        (sfVector2f) {(float) elem->rect.width, 5});
        sfRectangleShape_setSize(elem->showlife_green, \
        (sfVector2f) {(float) elem->rect.width * (p / 100.0), 5});
        sfRenderWindow_drawRectangleShape(w, elem->showlife_black, \
                                                                NULL);
        sfRenderWindow_drawRectangleShape(w, elem->showlife_green, \
                                                                NULL);
    }
}

void draw_monster_life(li_monster *li, sfRenderWindow *w)
{
    monster *elem;
    li_monster *temp = li;
    int a = 1;
    int i = 1;
    float p = 0;

    while (temp != NULL) {
        elem = temp->first;
        while (elem != NULL) {
            draw_monster_life_two(li, w, elem, p);
            elem = elem->next;
            i++;
        }
        temp = temp->next_wave;
        a++;
        i = 1;
    }
}

void draw_monster(li_monster *li, sfRenderWindow *w)
{
    monster *elem;
    li_monster *temp = li;
    int a = 1;
    int i = 1;
    while (temp != NULL) {
        elem = temp->first;
        while (elem != NULL) {
            if (elem->state == ALIVE && MONSTER(elem->type)) {
                sfSprite_setTextureRect(elem->sprite, elem->rect);
                sfSprite_setPosition(elem->sprite, elem->pos);
                sfRenderWindow_drawSprite(w, elem->sprite, NULL);
            }
            elem = elem->next;
            i++;
        }
        temp = temp->next_wave;
        a++;
        i = 1;
    }
    draw_monster_life(li, w);
}