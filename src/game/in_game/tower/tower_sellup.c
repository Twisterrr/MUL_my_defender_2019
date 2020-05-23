/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void sell(tower *t, t_li *t_li, game *game)
{
    game->hud->coin->value += t->cost / 3;
    tower *before;
    tower *elem = t_li->first;
    before = elem;
    while (elem != t) {
        before = elem;
        elem = elem->next;
    }
    if (before == elem) {
        t_li->first = NULL;
        elem = clear_tower(elem);
    } else {
        before->next = elem->next;
        elem = clear_tower(elem);
    }
}

void tower_sellup(game *game, all *all)
{
    sfVector2f pos;
    sfVector2i m = sfMouse_getPositionRenderWindow(all->w);
    tower *t;
    if (game->click_tower == 1) {
        t = game->t_li->first;
        while (t->click_on != 1)
            t = t->next;
        pos = (sfVector2f) {(t->tab_pos.x * 49) - 15, \
                            (t->tab_pos.y * 49) - 60};
        if (m.x > pos.x - 50 && m.x < pos.x && \
        m.y < pos.y + 150 && m.y > pos.y)
            sell(t, game->t_li, game);
        else if (m.x > pos.x + 50 && m.x < pos.x + 175 && \
        m.y < pos.y + 150 && m.y > pos.y && \
        game->hud->coin->value >= t->cost && t->level != 3)
            up(t, game);
    }
}