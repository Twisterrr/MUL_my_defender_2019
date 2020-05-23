/*
** EPITECH PROJECT, 2020
** defender
** File description:
** pressed_back
*/

#include "my.h"
#include "struct.h"

void pressed_back_diff(sfRenderWindow *w, all *all)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000))
        all->back = 2;
}