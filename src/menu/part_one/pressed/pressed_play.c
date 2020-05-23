/*
** EPITECH PROJECT, 2020
** defender
** File description:
** play
*/

#include "my.h"
#include "struct.h"

void pressed_play(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 730 && m.x <= 1130) && (m.y >= 300 && m.y <= 400)) {
            sfSound_play(menu->sound_button);
            sfText_setColor(menu->b_play->txt, sfYellow);
            sfText_setPosition(menu->b_play->txt, menu->b_play->pos);
            sfRenderWindow_drawText(w, menu->b_play->txt, NULL);
            sfRenderWindow_display(w);
            sfSleep(all->time);
            my_menu_two(all);
        }
    }
}