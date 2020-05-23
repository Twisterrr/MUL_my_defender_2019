/*
** EPITECH PROJECT, 2020
** defender
** File description:
** event_menu_next
*/

#include "my.h"
#include "struct.h"

void event_menu_next(menu *menu, sfRenderWindow *w, all *all)
{
    sfEvent e;
    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (e.type == sfEvtMouseButtonPressed) {
            all->cur->choose = 10;
            pressed_lvl(menu, w, all);
            pressed_back_next(menu, w, all);
            pressed_credits(menu, w, all);
            pressed_help(menu, w, all->help, all);
        }
        if (sfKeyboard_isKeyPressed(sfKeyEscape) && \
        sfClock_getElapsedTime(menu->wait).microseconds >= 50000)
            all->back = 1;
    }
}