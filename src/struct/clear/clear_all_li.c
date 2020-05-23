/*
** EPITECH PROJECT, 2020
** defender
** File description:
** clear_all
*/

#include "my.h"
#include "struct.h"

tower *clear_tower(tower *t)
{
    t->next = NULL;
    sfClock_destroy(t->c_shoot);
    sfSprite_destroy(t->sprite);
    return (NULL);
}

t_li *clear_t_li(t_li *t)
{
    tower *elem;
    tower *elem_temp;
    if (t != NULL) {
        sfRectangleShape_destroy(t->range);
        sfText_destroy(t->price_up);
        sfText_destroy(t->price_sell);
        sfSprite_destroy(t->sprite_up);
        sfSprite_destroy(t->sprite_sell);
        elem = t->first;
        while (elem != NULL) {
            elem_temp = elem;
            elem = elem->next;
            elem_temp = clear_tower(elem_temp);
        }
    }
    return (NULL);
}

monster *clear_monster(monster *mo)
{
    sfRectangleShape_destroy(mo->showlife_black);
    sfRectangleShape_destroy(mo->showlife_green);
    sfClock_destroy(mo->mouv);
    sfSprite_destroy(mo->sprite);
    return (NULL);
}

li_monster *clear_li(li_monster *li)
{
    monster *elem = li->first;
    monster *temp;
    sfSoundBuffer_destroy(li->buffer);
    sfSound_destroy(li->death);
    sfClock_destroy(li->one);
    while (elem != NULL) {
        temp = elem;
        elem = elem->next;
        temp = clear_monster(temp);
    }
    return (NULL);
}

li_monster *clear_li_monster(li_monster *li)
{
    li_monster *li_mn = li;
    li_monster *temp;
    while (temp != NULL) {
        temp = li_mn;
        li_mn = li_mn->next_wave;
        temp = clear_li(temp);
    }
    return (NULL);
}