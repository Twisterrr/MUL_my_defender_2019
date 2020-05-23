/*
** EPITECH PROJECT, 2020
** defender
** File description:
** draw_buttton
*/

#include "my.h"
#include "struct.h"

void draw_button_menu(menu *menu, sfRenderWindow *w)
{
    hover_menu(menu, w);
    draw_button(menu->b_play, w);
    draw_button(menu->b_opt, w);
    draw_button(menu->b_quit, w);
}