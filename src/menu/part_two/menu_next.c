/*
** EPITECH PROJECT, 2020
** defender
** File description:
** menu
*/

#include "my.h"
#include "struct.h"

void my_menu_two(all *all)
{
    while (sfRenderWindow_isOpen(all->w) && all->back == 0) {
        draw_menu_next(all->menu, all->w, all->cur);
        event_menu_next(all->menu, all->w, all);
        sfRenderWindow_display(all->w);
    }
    all->back -= 1;
    sfClock_restart(all->menu->wait);
}