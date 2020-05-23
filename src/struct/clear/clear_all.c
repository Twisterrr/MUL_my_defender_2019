/*
** EPITECH PROJECT, 2020
** defender
** File description:
** clear_all
*/

#include "my.h"
#include "struct.h"

game *clear_game(game *game)
{
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    return (NULL);
}

all *clear_all(all *all)
{
    sfRenderWindow_destroy(all->w);
    all->menu = clear_menu(all->menu);
    all->game = clear_game(all->game);
    sfMusic_stop(all->cre->music);
    sfMusic_destroy(all->cre->music);
    all = NULL;
    return (NULL);
}