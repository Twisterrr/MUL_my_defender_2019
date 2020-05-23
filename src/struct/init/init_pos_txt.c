/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

pos_txt *init_pos_txt(sfVector2f pos, sfText *text)
{
    pos_txt *pos_txt = malloc(sizeof(*pos_txt));
    pos_txt->pos = pos;
    pos_txt->txt = text;
    return (pos_txt);
}