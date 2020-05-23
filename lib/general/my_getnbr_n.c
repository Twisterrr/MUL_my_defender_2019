/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** getnbr
*/

#include "my.h"

int my_getnbr_n(char const *src, int depart)
{
    int i = depart;
    int nbr = 0;
    int neg = 0;
    while (src[i] == '-' || src[i] == '+') {
        if (src[i] == '-')
            neg++;
        i++;
    }
    while (src[i] >= 48 && src[i] <= 57) {
        nbr = nbr * 10;
        nbr = nbr + (src[i] - 48);
        i++;
        if (nbr >= 2147483647 || nbr < 0)
            return (0);
    }
    if (neg % 2 != 0) {
        nbr = -nbr;
    }
    i++;
    return (nbr);
}