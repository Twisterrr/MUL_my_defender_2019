/*
** EPITECH PROJECT, 2020
** defender
** File description:
** quit
*/

#include "my.h"
#include "struct.h"

void pressed_quit_two(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 807 && m.x <= 1095) && (m.y >= 686 && m.y <= 778)) {
            sfSound_play(menu->sound_button);
            sfText_setColor(menu->b_quit->txt, sfYellow);
            sfText_setPosition(menu->b_quit->txt, menu->b_quit->pos);
            sfRenderWindow_drawText(w, menu->b_quit->txt, NULL);
            sfRenderWindow_display(w);
            sfSleep(all->time);
            sfRenderWindow_close(w);
        }
    }
}

void pressed_quit(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 730 && m.x <= 1130) && (m.y >= 500 && m.y <= 600)) {
            sfSound_play(menu->sound_button);
            sfText_setColor(menu->b_quit->txt, sfYellow);
            sfText_setPosition(menu->b_quit->txt, menu->b_quit->pos);
            sfRenderWindow_drawText(w, menu->b_quit->txt, NULL);
            sfRenderWindow_display(w);
            sfSleep(all->time);
            sfRenderWindow_close(w);
        }
    }
}