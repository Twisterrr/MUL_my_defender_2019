/*
** EPITECH PROJECT, 2020
** defend
** File description:
** init_button
*/

#include "my.h"
#include "struct.h"

button *init_button(sfVector2f pos, sfIntRect rect, sfColor color, char *txt)
{
    button *button = malloc(sizeof(*button));
    button->font = sfFont_createFromFile("Ressources/Font/Medieval.ttf");
    button->txt = create_txt(75, button->font, color, txt);
    button->pos = pos;
    button->rect = rect;
    button->sprite = create_sprite("Ressources/Images/Util/button.png");
    return (button);
}