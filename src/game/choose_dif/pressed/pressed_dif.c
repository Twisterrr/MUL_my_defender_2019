/*
** EPITECH PROJECT, 2020
** defender
** File description:
** pressed_back
*/

#include "my.h"
#include "struct.h"

void pressed_diff(sfRenderWindow *w, int *ret)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 205 && m.x <= 605) && (m.y >= 90 && m.y <= 190))
        *ret = 1;
    if ((m.x >= 705 && m.x <= 1105) && (m.y >= 90 && m.y <= 190))
        *ret = 2;
    if ((m.x >= 1205 && m.x <= 1605) && (m.y >= 90 && m.y <= 190))
        *ret = 3;
}