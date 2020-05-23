/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Lose function of the Defender.
*/

#include "my.h"
#include "struct.h"

void lose_game_two(all *all, sfRenderWindow *w, sfEvent e)
{
    while (sfRenderWindow_isOpen(w) && all->back == 0) {
        sfRenderWindow_drawSprite(w, all->game->win_lose->lose, NULL);
        if (sfTime_asSeconds(sfClock_getElapsedTime \
        (all->game->clock_h)) >= 10)
            draw_pos_txt(all->game->win_lose->ret, w);
        draw_cursor(all->cur, w);
        while (sfRenderWindow_pollEvent(w, &e)) {
                if (e.type == sfEvtClosed)
                    sfRenderWindow_close(w);
                if (sfKeyboard_isKeyPressed(sfKeyM))
                    all->back = 3;
        }
        sfRenderWindow_display(w);
    }
}

void lose_game(all *all, sfRenderWindow *w)
{
    sfEvent e;
    if (all->game->hud->life->value < 1) {
        sfMusic_pause(all->game->music);
        sfMusic_play(all->cre->music);
        sfClock_restart(all->game->win_lose->clock);
        lose_game_two(all, w, e);
        sfMusic_pause(all->cre->music);
        all->back -= 1;
    }
}