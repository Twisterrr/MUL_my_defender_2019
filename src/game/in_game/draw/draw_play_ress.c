/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_play_ress
*/

#include "my.h"
#include "struct.h"

void draw_money(sfRenderWindow *w, ply_ress *coin, all *all)
{
    int a = 0;
    char *str = NULL;
    sfSprite_setPosition(coin->sprite, coin->pos);
    sfRenderWindow_drawSprite(all->w, coin->sprite, NULL);
    sfText_setPosition(all->game->hud->s_coin->txt, \
    all->game->hud->s_coin->pos);
    sfText_setString(all->game->hud->s_coin->txt, int_to_str(coin->value, str));
    sfRenderWindow_drawText(w, all->game->hud->s_coin->txt, NULL);
    if (sfClock_getElapsedTime(coin->clo).microseconds > 60000) {
            coin->rect.left += coin->rect.width;
            if (coin->rect.left >= 870 && coin->rect.top == 145) {
                coin->rect.left = 60;
                coin->rect.top = 55;
            } else if (coin->rect.left >= 870) {
                coin->rect.left = 60;
                coin->rect.top = 145;
            }
            sfSprite_setTextureRect(coin->sprite, coin->rect);
            sfClock_restart(coin->clo);
    }
}

void draw_life(sfRenderWindow *w, ply_ress *life, all *all)
{
    int a = 0;
    char *str = NULL;
    sfSprite_setPosition(life->sprite, life->pos);
    sfRenderWindow_drawSprite(all->w, life->sprite, NULL);
    sfText_setPosition(all->game->hud->s_life->txt, \
    all->game->hud->s_life->pos);
    sfText_setString(all->game->hud->s_life->txt, int_to_str(life->value, str));
    sfRenderWindow_drawText(w, all->game->hud->s_life->txt, NULL);
    if (sfClock_getElapsedTime(life->clo).microseconds > 80000) {
            life->rect.left += life->rect.width;
            if (life->rect.left >= 600)
                life->rect.left = 0;
            sfSprite_setTextureRect(life->sprite, life->rect);
            sfClock_restart(life->clo);
    }
}