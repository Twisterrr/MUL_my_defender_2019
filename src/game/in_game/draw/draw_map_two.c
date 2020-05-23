/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** draw_map_two
*/

#include "my.h"
#include "struct.h"

void draw_simple_tile(sfIntRect rect, sfRenderWindow *w, game *game,
                                                    sfVector2f pos)
{
    sfSprite_setTextureRect(game->tile->sprite, rect);
    sfSprite_setPosition(game->tile->sprite, pos);
    sfRenderWindow_drawSprite(w, game->tile->sprite, NULL);
}

void switch_fonction_5(all *all, sfVector2f pos, int i, int a)
{
    game *game = all->game;
    switch (game->choose_one->map[i][a]) {
        case 'G':
            draw_simple_tile(game->tile->top_left, all->w, game, pos);
            break;
        case 'D':
            draw_simple_tile(game->tile->top_right, all->w, game, pos);
            break;
        case 'g':
            draw_simple_tile(game->tile->bot_left, all->w, game, pos);
            break;
        case 'd':
            draw_simple_tile(game->tile->bot_right, all->w, game, pos);
            break;
        case 's':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            draw_simple_tile(game->tile->sand, all->w, game, pos);
            break;
    }
}