/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void option(all *all)
{
    while (all->back == 0 && sfRenderWindow_isOpen(all->w)) {
        draw_option(all->opt, all->w, all->cur);
        event_option(all->opt, all->w, all);
        sfRenderWindow_display(all->w);
    }
    sfClock_restart(all->menu->wait);
    all->back -= 1;
}