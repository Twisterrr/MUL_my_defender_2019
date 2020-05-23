/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

void goblin(monster *elem, sfVector2i tab_pos)
{
    elem->pos.x = (tab_pos.x * 49) - 30;
    elem->pos.y = (tab_pos.y * 49) - 30;
    elem->sprite = create_sprite("Ressources/game/Monster/gobelin.png");
    elem->rect = (sfIntRect) {0, 0, 64, 64};
    elem->speed = 5;
    elem->life = 250;
    elem->full_life = 250;
}

void croc(monster *elem, sfVector2i tab_pos)
{
    elem->pos.x = (tab_pos.x * 49) - 50;
    elem->pos.y = (tab_pos.y * 49) - 40;
    elem->sprite = create_sprite("Ressources/game/Monster/croc.png");
    elem->rect = (sfIntRect) {0, 0, 70, 70};
    elem->speed = 3;
    elem->life = 1000;
    elem->full_life = 1000;
}

void boss(monster *elem, sfVector2i tab_pos)
{
    elem->pos.x = (tab_pos.x * 49) - 50;
    elem->pos.y = (tab_pos.y * 49) - 50;
    elem->sprite = create_sprite("Ressources/game/Monster/boss.png");
    elem->rect = (sfIntRect) {0, 0, 112, 105};
    elem->speed = 1.5;
    elem->life = 5000;
    elem->full_life = 5000;
}

void value(monster *elem, int type, sfVector2i tab_pos)
{
    elem->mouv = sfClock_create();
    elem->type = type;
    elem->slowed = 0;
    elem->tab_pos = tab_pos;
    elem->old_pos.x = tab_pos.x - 1;
    elem->old_pos.y = tab_pos.y;
    elem->state = STASIS;
    elem->next = NULL;

    elem->showlife_black = sfRectangleShape_create();
    sfRectangleShape_setSize(elem->showlife_black, (sfVector2f) {50, 5});
    sfRectangleShape_setFillColor(elem->showlife_black, sfBlack);

    elem->showlife_green = sfRectangleShape_create();
    sfRectangleShape_setFillColor(elem->showlife_green, sfGreen);
}

monster *init_monster(int type, sfVector2i tab_pos)
{
    monster *elem = malloc(sizeof(*elem));
    value(elem, type, tab_pos);
    switch (type) {
        case GOBELIN :
            goblin(elem, tab_pos);
            break;
        case CROC :
            croc(elem, tab_pos);
            break;
        case BOSS :
            boss(elem, tab_pos);
            break;
    }
    elem->new_pos = elem->pos;
    return (elem);
}