/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

void my_putstr(char const *str)
{
    int r = 0;

    while (str[r] != '\0') {
        my_putchar(str[r]);
        r++;
    }
}