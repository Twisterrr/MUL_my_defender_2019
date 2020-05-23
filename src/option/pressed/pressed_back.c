/*
** EPITECH PROJECT, 2020
** defender
** File description:
** pressed_back
*/

#include "my.h"
#include "struct.h"

void pressed_back(opt *opt, sfRenderWindow *w, all *all)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);
    if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000)) {
        sfSound_play(all->menu->sound_button);
        sfText_setColor(opt->back->txt, sfYellow);
        sfText_setPosition(opt->back->txt, opt->back->pos);
        sfRenderWindow_drawText(w, opt->back->txt, NULL);
        sfRenderWindow_display(w);
        sfSleep(all->time);
        all->back = 1;
    }
}