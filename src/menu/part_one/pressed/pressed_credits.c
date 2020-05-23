/*
** EPITECH PROJECT, 2020
** defender
** File description:
** credits
*/

#include "my.h"
#include "struct.h"

void pressed_credits(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 0 && m.x <= 240) && (m.y >= 940 && m.y <= 1020)) {
            sfSound_play(menu->sound_button);
            sfText_setColor(menu->credit->txt, sfYellow);
            draw_pos_txt(menu->credit, w);
            sfRenderWindow_display(w);
            sfSleep(all->time);
            credits(w, all->cre, menu, all);
        }
    }
}