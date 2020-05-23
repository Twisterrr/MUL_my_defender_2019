/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** utils_mouv_monsters
*/

#include "my.h"
#include "struct.h"

void go_up_two(monster *elem)
{
    if (elem->type == BOSS) {
        elem->rect.top = 315;
        elem->rect.left += elem->rect.width;
        if (elem->rect.left >= 300)
            elem->rect.left = 0;
    }
}

void go_down_two(monster *elem)
{
    if (elem->type == BOSS) {
        elem->rect.top = 0;
        elem->rect.left += elem->rect.width;
        if (elem->rect.left >= 300)
            elem->rect.left = 0;
    }
}

void go_left_two(monster *elem)
{
    if (elem->type == BOSS) {
        elem->rect.top = 105;
        elem->rect.left += elem->rect.width;
        if (elem->rect.left >= 300)
            elem->rect.left = 0;
    }
}

void go_right_two(monster *elem)
{
    if (elem->type == BOSS) {
        elem->rect.top = 210;
        elem->rect.left += elem->rect.width;
        if (elem->rect.left >= 300)
            elem->rect.left = 0;
    }
}