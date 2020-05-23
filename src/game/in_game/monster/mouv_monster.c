/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void check_pos(monster *elem)
{
    if (elem->new_pos.x + 49 < elem->pos.x) {
        elem->tab_pos.x += 1;
        elem->old_pos.x += 1;
        elem->new_pos.x = elem->pos.x ;
    }
    if (elem->new_pos.x - 49 > elem->pos.x) {
        elem->tab_pos.x -= 1;
        elem->old_pos.x -= 1;
        elem->new_pos.x = elem->pos.x;
    }
    if (elem->new_pos.y - 49 > elem->pos.y) {
        elem->tab_pos.y -= 1;
        elem->old_pos.y -= 1;
        elem->new_pos.y = elem->pos.y;
    }
    if (elem->new_pos.y + 49 < elem->pos.y) {
        elem->tab_pos.y += 1;
        elem->old_pos.y += 1;
        elem->new_pos.y = elem->pos.y;
    }
}

void go_up(monster *elem)
{
    check_pos(elem);
    if (elem->slowed != 0) {
        elem->slowed -= 1;
        elem->pos.y -= elem->speed / 1.5;
    } else
        elem->pos.y -= elem->speed;
    if (sfClock_getElapsedTime(elem->mouv).microseconds >= 100000) {
        sfClock_restart(elem->mouv);
        if (elem->type == GOBELIN) {
            elem->rect.top = 0;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 390)
                elem->rect.left = 0;
        }
        if (elem->type == CROC) {
            elem->rect.top = 210;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 230)
                elem->rect.left = 0;
        }
        go_up_two(elem);
    }
}

void go_down(monster *elem)
{
    check_pos(elem);
    if (elem->slowed != 0) {
        elem->slowed -= 1;
        elem->pos.y += elem->speed / 1.5;
    } else
        elem->pos.y += elem->speed;
    if (sfClock_getElapsedTime(elem->mouv).microseconds >= 100000) {
        sfClock_restart(elem->mouv);
        if (elem->type == GOBELIN) {
            elem->rect.top = 128;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 390)
                elem->rect.left = 0;
        }
        if (elem->type == CROC) {
            elem->rect.top = 0;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 190)
                elem->rect.left = 0;
        }
        go_down_two(elem);
    }
}

void go_left(monster *elem)
{
    check_pos(elem);
    if (elem->slowed != 0) {
        elem->slowed -= 1;
        elem->pos.x -= elem->speed / 1.5;
    } else
        elem->pos.x -= elem->speed;
    if (sfClock_getElapsedTime(elem->mouv).microseconds >= 100000) {
        sfClock_restart(elem->mouv);
        if (elem->type == GOBELIN) {
            elem->rect.top = 64;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 390)
                elem->rect.left = 0;
        }
        if (elem->type == CROC) {
            elem->rect.top = 70;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 230)
                elem->rect.left = 0;
        }
        go_left_two(elem);
    }
}

void go_right(monster *elem)
{
    check_pos(elem);
    if (elem->slowed != 0) {
        elem->slowed -= 1;
        elem->pos.x += elem->speed / 1.5;
    } else
        elem->pos.x += elem->speed;
    if (sfClock_getElapsedTime(elem->mouv).microseconds >= 100000) {
        sfClock_restart(elem->mouv);
        if (elem->type == GOBELIN) {
            elem->rect.top = 192;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 390)
                elem->rect.left = 0;
        }
        if (elem->type == CROC) {
            elem->rect.top = 140;
            elem->rect.left += elem->rect.width;
            if (elem->rect.left >= 350)
                elem->rect.left = 0;
        }
        go_right_two(elem);
    }
}