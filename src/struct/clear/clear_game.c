/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** clear_game
*/

#include "my.h"
#include "struct.h"

game *clear_game(game *game)
{
    sfMusic_stop(game->music);
    sfMusic_destroy(game->music);
    return (NULL);
}