/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

bool no_tower(t_li *t, sfVector2i pos_tab, game *game)
{
    tower *elem = t->first;
    while (elem != NULL) {
        if (pos_tab.y == elem->tab_pos.y && pos_tab.x == elem->tab_pos.x)
            return (false);
        elem = elem->next;
    }
    return (true);
}

bool enough_money(game *game)
{
    int cost;
    if (game->c->type == BOMB_TOWER)
        cost = 250;
    else if (game->c->type == COLD_TOWER)
        cost = 150;
    if (game->c->type == SNIPER_TOWER)
        cost = 200;
    else if (game->c->type == ARROW_TOWER)
        cost = 100;
    if (game->hud->coin->value >= cost) {
        game->hud->coin->value -= cost;
        return (true);
    }
    return (false);
}

void push_tower(sfVector2f pos, int type, t_li *t_li, sfVector2i tab_pos)
{
    tower *elem = init_tower(pos, type, tab_pos);
    tower *temp = t_li->first;

    if (temp == NULL) {
        t_li->first = elem;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = elem;
    }
}

void put_tower(game *game, sfRenderWindow *w)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);
    sfVector2i pos_tab = {m.x / 49, m.y / 49};

    if (game->choose_one->map[pos_tab.y][pos_tab.x] == '1' && \
    no_tower(game->t_li, pos_tab, game)) {
        if (enough_money(game)) {
            game->c->state = 0;
            push_tower((sfVector2f) {pos_tab.x + 49, pos_tab.y * 49}, \
                                    game->c->type, game->t_li, pos_tab);
        }
    }
}