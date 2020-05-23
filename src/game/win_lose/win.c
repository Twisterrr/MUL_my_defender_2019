/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Win function of the Defender.
*/

#include "my.h"
#include "struct.h"

void win_game_three(all *all, sfRenderWindow *w)
{
    sfEvent e;
    draw_cursor(all->cur, w);
    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (sfKeyboard_isKeyPressed(sfKeyM))
            all->back = 3;
        }
}

void win_game_two(all *all, sfRenderWindow *w)
{
    sfMusic_pause(all->game->music);
    sfMusic_play(all->cre->music);
    sfClock_restart(all->game->win_lose->clock);
}

void win_game(all *all, sfRenderWindow *w)
{
    int nb_wave = count_length_li(all->game->li);
    if (nb_wave == len_tab(all->game->choose_one->wave) \
    && how_many(all->game->li) == 0) {
        win_game_two(all, w);
        while (sfRenderWindow_isOpen(w) && all->back == 0) {
            sfRenderWindow_drawSprite(w, all->game->win_lose->win, NULL);
            if (sfTime_asSeconds(sfClock_getElapsedTime \
            (all->game->clock_h)) >= 10)
                draw_pos_txt(all->game->win_lose->men, w);
            win_game_three(all, w);
            sfRenderWindow_display(w);
        }
        sfMusic_pause(all->cre->music);
        all->back -= 1;
    }
}