/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_all
*/

#include "my.h"
#include "struct.h"

void init_tower_two(int type, tower *t)
{
    switch (type) {
        case BOMB_TOWER :
            init_bomb(t);
            break;
        case SNIPER_TOWER :
            init_sniper(t);
            break;
        case COLD_TOWER :
            init_cold(t);
            break;
        case ARROW_TOWER :
            init_arrow(t);
            break;
    }
}

tower *init_tower(sfVector2f pos, int type, sfVector2i tab_pos)
{
    tower *t = malloc(sizeof(*t));
    t->click_on = 0;
    t->c_shoot = sfClock_create();
    t->next = NULL;
    t->level = 1;
    t->type = type;
    t->sprite = create_sprite("Ressources/game/map/Towers.png");
    t->pos = pos;
    sfSprite_scale(t->sprite, (sfVector2f) {1.5, 1.5});
    t->tab_pos = tab_pos;
    init_tower_two(type, t);
    return (t);
}