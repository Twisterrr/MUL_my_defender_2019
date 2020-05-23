/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** draw_button
*/

#include "my.h"
#include "struct.h"

void draw_pos_txt(pos_txt *pos_txt, sfRenderWindow *w)
{
    sfText_setPosition(pos_txt->txt, pos_txt->pos);
    sfRenderWindow_drawText(w, pos_txt->txt, NULL);
}