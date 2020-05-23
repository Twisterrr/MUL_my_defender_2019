/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void pressed_tower(all *all, game *game)
{
    if (game->click_tower == 1) {
        game->click_tower = 0;
        set_tower_unclicked(game->t_li);
    }
    sfVector2i m = sfMouse_getPositionRenderWindow(all->w);
    tower *elem = game->t_li->first;
    while (elem != NULL) {
        if (m.x / 49 == elem->tab_pos.x && m.y / 49 == elem->tab_pos.y) {
            game->click_tower = 1;
            elem->click_on = 1;
        }
        elem = elem->next;
    }
}