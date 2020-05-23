/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

int choose_difficulty(all *all)
{
    int ret = -1;
    while (sfRenderWindow_isOpen(all->w) && all->back == 0) {
        draw_diff(all->game, all->w, all->cur);
        event_diff(all, &ret);
        sfRenderWindow_display(all->w);
        if (ret != -1) {
            return (ret);
        }
    }
    all->back -= 1;
    return (ret);
}