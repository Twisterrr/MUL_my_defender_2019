/*
** EPITECH PROJECT, 2020
** defender
** File description:
** hover_next
*/

#include "my.h"
#include "struct.h"

void more_hover_menu_next(sfVector2i m, menu *menu, sfRenderWindow *w)
{
    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 750 && m.y <= 850)) {
        hover_one(menu->next->back, 370, 760, sfWhite);
    } else
        hover_two(menu->next->back, 370, 750, sfBlack);
    if ((m.x >= 0 && m.x <= 240) && (m.y >= 940 && m.y <= 1020)) {
        sfText_setColor(menu->credit->txt, sfRed);
    } else
        sfText_setColor(menu->credit->txt, sfWhite);
}

void hover_menu_next(menu *menu, sfRenderWindow *w)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 295 && m.y <= 395)) {
        hover_one(menu->next->level1, 370, 305, sfWhite);
    } else
        hover_two(menu->next->level1, 370, 295, sfBlack);
    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 440 && m.y <= 540)) {
        hover_one(menu->next->level2, 370, 450, sfWhite);
    } else
        hover_two(menu->next->level2, 370, 440, sfBlack);
    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 600 && m.y <= 700)) {
        hover_one(menu->next->loaded, 370, 610, sfWhite);
    } else
        hover_two(menu->next->loaded, 370, 600, sfBlack);
    more_hover_menu_next(m, menu, w);
}