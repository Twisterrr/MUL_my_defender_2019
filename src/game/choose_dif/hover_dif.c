/*
** EPITECH PROJECT, 2020
** defender
** File description:
** hover_next
*/

#include "my.h"
#include "struct.h"

void hover_diff(game *game, sfRenderWindow *w)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 205 && m.x <= 605) && (m.y >= 90 && m.y <= 190)) {
        hover_one(game->dif_w->easy, 370, 100, sfWhite);
    } else
        hover_two(game->dif_w->easy, 370, 90, sfColor_fromRGB(4, 189, 1));
    if ((m.x >= 705 && m.x <= 1105) && (m.y >= 90 && m.y <= 190)) {
        hover_one(game->dif_w->normal, 370, 100, sfWhite);
    } else
        hover_two(game->dif_w->normal, 370, 90, sfColor_fromRGB(255, 151, 0));
    if ((m.x >= 1205 && m.x <= 1605) && (m.y >= 90 && m.y <= 190)) {
        hover_one(game->dif_w->hard, 370, 100, sfWhite);
    } else
        hover_two(game->dif_w->hard, 370, 90, sfRed);
    if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000)) {
        hover_one(game->dif_w->back, 370, 910, sfWhite);
    } else
        hover_two(game->dif_w->back, 370, 900, sfBlack);
}