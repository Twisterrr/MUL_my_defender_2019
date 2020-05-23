/*
** EPITECH PROJECT, 2020
** defender
** File description:
** opt
*/

#include "my.h"
#include "struct.h"

void pressed_option(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 730 && m.x <= 1130) && (m.y >= 700 && m.y <= 800)) {
            sfSound_play(menu->sound_button);
            sfText_setColor(menu->b_opt->txt, sfYellow);
            sfText_setPosition(menu->b_opt->txt, menu->b_opt->pos);
            sfRenderWindow_drawText(w, menu->b_opt->txt, NULL);
            sfRenderWindow_display(w);
            sfSleep(all->time);
            option(all);
        }
    }
}