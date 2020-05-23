/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_all
*/

#include "my.h"
#include "struct.h"

all *init_all(int loaded, char *file)
{
    all *all = malloc(sizeof(*all));
    all->frame_limit = 64;
    all->time.microseconds = 99900;
    all->menu = init_menu(loaded, file);
    all->cur = init_cursor();
    all->my_p = init_pause();
    all->back = 0;
    all->opt = init_option();
    all->cre = init_credits();
    all->game = init_game();
    all->help = init_help();
    all->w = create_window("King's Mercy", 1080, 1920, 7);
    all->volume = 100;
    return (all);
}