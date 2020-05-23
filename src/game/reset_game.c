/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void reset_game(game *game)
{
    game->t_li = clear_t_li(game->t_li);
    game->li = clear_li(game->li);
    game->hud->coin->value = 1000;
    game->hud->life->value = 20;
}