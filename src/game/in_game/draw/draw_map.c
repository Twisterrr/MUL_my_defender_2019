/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void switch_fonction_4(all *all, sfVector2f pos, int i, int a)
{
    game *game = all->game;
    switch (game->choose_one->map[i][a]) {
        case 'n':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            draw_simple_tile(game->tile->stone, all->w, game, pos);
            break;
        case 'c':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            break;
        case '3':
            draw_simple_tile(game->tile->path_x, all->w, game, pos);
            break;
        case '5':
            draw_simple_tile(game->tile->path_y, all->w, game, pos);
            break;
    }
    switch_fonction_5(all, pos, i, a);
}

void switch_fonction_3(all *all, sfVector2f pos, int i, int a)
{
    game *game = all->game;
    switch (game->choose_one->map[i][a]) {
        case 't':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            draw_simple_tile(game->tile->tree_1, all->w, game, pos);
            break;
        case 'e':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            draw_simple_tile(game->tile->tree_2, all->w, game, pos);
            break;
        case 'E':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            draw_simple_tile(game->tile->tree_3, all->w, game, pos);
            break;
        case 'h':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            draw_simple_tile(game->tile->hut, all->w, game, pos);
            break;
    }
    switch_fonction_4(all, pos, i, a);
}

void switch_fonction_2(all *all, sfVector2f pos, int i, int a)
{
    game *game = all->game;
    switch (game->choose_one->map[i][a]) {
        case '4':
            draw_simple_tile(game->tile->path_y, all->w, game, pos);
            break;
        case 'L':
            draw_simple_tile(game->tile->top_left, all->w, game, pos);
            break;
        case 'R':
            draw_simple_tile(game->tile->top_right, all->w, game, pos);
            break;
        case 'l':
            draw_simple_tile(game->tile->bot_left, all->w, game, pos);
            break;
        case 'r':
            draw_simple_tile(game->tile->bot_right, all->w, game, pos);
            break;
    }
    switch_fonction_3(all, pos, i, a);
}

void switch_fonction(all *all, sfVector2f pos, int i, int a)
{
    game *game = all->game;
    switch (game->choose_one->map[i][a]) {
        case '0':
            draw_simple_tile(game->tile->grass, all->w, game, pos);
            break;
        case '1':
            if (game->h == 1)
                draw_simple_tile(game->tile->cross, all->w, game, pos);
            if (game->h == 0)
                draw_simple_tile(game->tile->grass, all->w, game, pos);
            break;
        case '2':
            draw_simple_tile(game->tile->path_x, all->w, game, pos);
            break;
        case 'X':
            draw_simple_tile(game->tile->path_x, all->w, game, pos);
            break;
    }
    switch_fonction_2(all, pos, i, a);
}

void draw_map(sfRenderWindow *w, lvl *lvl, game *game, all *all)
{
    sfVector2f pos = {0, 0};
    for (int i = 0; lvl->map[i] != NULL; i++) {
        for (int a = 0; lvl->map[i][a] != '\n'; a++) {
            switch_fonction(all, pos, i, a);
            pos.x += 49;
        }
        pos.x = 0;
        pos.y += 49;
    }
    pos = (sfVector2f) {0, 0};
    for (int i = 0; lvl->map[i] != NULL; i++) {
        for (int a = 0; lvl->map[i][a] != '\n'; a++) {
            if (lvl->map[i][a] == 'c')
                draw_simple_tile(game->tile->castle, w, game, \
                (sfVector2f) {pos.x - 15, pos.y - 35});
            pos.x += 49;
        }
        pos.x = 0;
        pos.y += 49;
    }
}