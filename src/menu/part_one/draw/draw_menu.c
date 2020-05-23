/*
** EPITECH PROJECT, 2020
** defender
** File description:
** draw_menu
*/

#include "my.h"
#include "struct.h"

void draw_menu(menu *menu, sfRenderWindow *w, cursor *cur)
{
    sfRenderWindow_clear(w, sfBlack);
    sfRenderWindow_drawSprite(w, menu->fond, NULL);
    draw_pos_txt(menu->titre, w);
    draw_pos_txt(menu->credit, w);
    draw_button_menu(menu, w);
    draw_cursor(cur, w);
}