/*
** EPITECH PROJECT, 2020
** defender
** File description:
** back_next
*/

#include "my.h"
#include "struct.h"

void pressed_back_next(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 730 && m.x <= 1130) && (m.y >= 750 && m.y <= 850)) {
            sfSound_play(menu->sound_button);
            all->back = 1;
        }
    }
}