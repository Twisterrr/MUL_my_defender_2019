/*
** EPITECH PROJECT, 2020
** defender
** File description:
** menu
*/

#include "my.h"
#include "struct.h"

void my_menu(all *all)
{
    sfRenderWindow_setFramerateLimit(all->w, all->frame_limit);
    sfRenderWindow_setMouseCursorVisible(all->w, sfFalse);
    while (sfRenderWindow_isOpen(all->w)) {
        draw_menu(all->menu, all->w, all->cur);
        event_menu(all->menu, all->w, all);
        sfRenderWindow_display(all->w);
    }
}