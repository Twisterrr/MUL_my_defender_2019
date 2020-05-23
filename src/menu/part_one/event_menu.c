/*
** EPITECH PROJECT, 2020
** defender
** File description:
** event_menu
*/

#include "my.h"
#include "struct.h"

void event_menu(menu *menu, sfRenderWindow *w, all *all)
{
    sfEvent e;
    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (e.type == sfEvtMouseButtonPressed) {
            all->cur->choose = 10;
            pressed_quit(menu, w, all);
            pressed_credits(menu, w, all);
            pressed_option(menu, w, all);
            pressed_help(menu, w, all->help, all);
            pressed_play(menu, w, all);
        }
    }
}