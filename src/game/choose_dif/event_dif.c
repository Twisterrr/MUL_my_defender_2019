/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void event_diff(all *all, int *ret)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(all->w, &e)) {
        if (e.type == sfEvtClosed) {
            sfRenderWindow_close(all->w);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape)) {
            all->back = 2;
        }
        if (e.type == sfEvtMouseButtonPressed) {
            all->cur->choose = 10;
            pressed_back_diff(all->w, all);
            pressed_diff(all->w, ret);
        }
    }
}