/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void set_tower_unclicked(t_li *t)
{
    tower *elem = t->first;
    while (elem != NULL) {
        elem->click_on = 0;
        elem = elem->next;
    }
}

void event_game_three(sfRenderWindow *w, all *all)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (all->game->c->state != 1 && all->game->click_tower != 1)
            draw_pause(w, all);
        else if (all->game->c->state == 1 || all->game->click_tower == 1) {
            all->game->c->state = 0;
            all->game->click_tower = 0;
            set_tower_unclicked(all->game->t_li);
        }
        sfClock_restart(all->game->wait);
    }
}

void event_game_two(sfRenderWindow *w, all *all, sfEvent e)
{
    if (sfClock_getElapsedTime(all->game->clock_h).microseconds >= 10000) {
        if (sfKeyboard_isKeyPressed(sfKeySpace)) {
                all->game->send_wave = 1;
                sfClock_restart(all->game->clock_h);
        }
    }
    if (e.type == sfEvtMouseButtonPressed) {
        all->cur->choose = 10;
        if (all->game->c->state == 0) {
            tower_sellup(all->game, all);
            pressed_towerbar(all, all->game->c);
            pressed_tower(all, all->game);
        }
        else if (all->game->c->state == 1 && all->game->click_tower != 1)
            put_tower(all->game, w);
    }
    event_game_three(w, all);
}

void event_game(sfRenderWindow *w, all *all)
{
    sfEvent e;
    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (sfClock_getElapsedTime(all->game->clock_h).microseconds >= 10000) {
            if (sfKeyboard_isKeyPressed(sfKeyH)) {
                if (all->game->h == 0)
                    all->game->h = 1;
                else
                    all->game->h = 0;
                sfClock_restart(all->game->clock_h);
            }
        }
        event_game_two(w, all, e);
    }
}