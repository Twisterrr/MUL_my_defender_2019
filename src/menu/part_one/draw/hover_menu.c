/*
** EPITECH PROJECT, 2020
** defender
** File description:
** hover
*/

#include "my.h"
#include "struct.h"

void hover_one(button *but, int one, int two, sfColor c)
{
    but->rect.left = but->rect.width + one;
    but->pos.y = two;
    sfText_setColor(but->txt, c);
}

void hover_two(button *but, int one, int two, sfColor c)
{
    but->rect.left = one;
    but->pos.y = two;
    sfText_setColor(but->txt, c);
}

void hover_menu(menu *menu, sfRenderWindow *w)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);
    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 300 && m.y <= 400)) {
        hover_one(menu->b_play, 370, 310, sfWhite);
    } else
        hover_two(menu->b_play, 370, 300, sfBlack);
    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 500 && m.y <= 600)) {
        hover_one(menu->b_quit, 370, 510, sfWhite);
    } else
        hover_two(menu->b_quit, 370, 500, sfBlack);
    if ((m.x >= 730 && m.x <= 1130) && (m.y >= 700 && m.y <= 800)) {
        hover_one(menu->b_opt, 370, 710, sfWhite);
    } else
        hover_two(menu->b_opt, 370, 700, sfBlack);
    if ((m.x >= 0 && m.x <= 240) && (m.y >= 940 && m.y <= 1020)) {
        sfText_setColor(menu->credit->txt, sfRed);
    } else
        sfText_setColor(menu->credit->txt, sfWhite);
}