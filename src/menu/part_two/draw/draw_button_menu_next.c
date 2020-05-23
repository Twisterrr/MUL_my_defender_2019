/*
** EPITECH PROJECT, 2020
** defender
** File description:
** draw_buttton_next
*/

#include "my.h"
#include "struct.h"

void draw_button_menu_next(menu *menu, sfRenderWindow *w)
{
    hover_menu_next(menu, w);
    draw_button(menu->next->back, w);
    draw_button(menu->next->level1, w);
    draw_button(menu->next->level2, w);
    draw_button(menu->next->loaded, w);
}