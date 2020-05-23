/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_tower_two
*/

#include "my.h"
#include "struct.h"

void draw_tower_three(game *game, sfRenderWindow *w, sfVector2i m)
{
    if (game->c->type == ARROW_TOWER) {
        game->c->int_range = 4;
        draw_cursor_tower(game->c, game->c->rect_t4, \
            (sfVector2f) {(float) m.x - 45, (float) m.y - 60}, w);
    }
}