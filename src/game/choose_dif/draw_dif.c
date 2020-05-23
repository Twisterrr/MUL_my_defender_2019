/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void draw_diff(game *game, sfRenderWindow *w, cursor *cur)
{
    hover_diff(game, w);
    sfRenderWindow_clear(w, sfColor_fromRGB(102, 100, 96));
    sfRenderWindow_drawSprite(w, game->dif_w->diff, NULL);
    draw_button(game->dif_w->easy, w);
    draw_button(game->dif_w->normal, w);
    draw_button(game->dif_w->hard, w);
    draw_button(game->dif_w->back, w);
    draw_pos_txt(game->dif_w->txt, w);
    sfRenderWindow_drawSprite(w, game->dif_w->fond, NULL);
    draw_cursor(cur, w);
}