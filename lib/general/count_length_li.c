/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

#include "my.h"

int count_length_li(li_monster *li)
{
    li_monster *temp = li;
    int i = 0;
    while (temp != NULL) {
        i++;
        temp = temp->next_wave;
    }
    return (i);
}