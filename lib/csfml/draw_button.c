/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** draw_button
*/

#include "my.h"
#include "struct.h"

void draw_button(button *button, sfRenderWindow *w)
{
    sfSprite_setPosition(button->sprite, button->pos);
    sfText_setPosition(button->txt, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    sfRenderWindow_drawSprite(w, button->sprite, NULL);
    sfRenderWindow_drawText(w, button->txt, NULL);
}