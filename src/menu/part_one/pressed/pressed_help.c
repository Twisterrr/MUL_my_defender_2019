/*
** EPITECH PROJECT, 2020
** defender
** File description:
** help$
*/

#include "my.h"
#include "struct.h"

void pressed_help(menu *menu, sfRenderWindow *w, help_s *helpe, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
    sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 1775 && m.x <= 1900) && (m.y >= 0 && m.y <= 150)) {
            sfSound_play(menu->sound_button);
            help(w, all, helpe);
        }
    }
}