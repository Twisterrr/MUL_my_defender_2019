/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

int is_num(char a)
{
    if (a >= 48 && a <= 57)
        return (1);
    return (0);
}

void how_many_digit(int nb, int *a)
{
    if (nb < 10)
        *a = *a + 1;
    else if (nb >= 10) {
        how_many_digit(nb / 10, a);
        *a = *a + 1;
    }
}

void push_in_list(li_monster *li, int type, sfVector2i tab_pos)
{
    monster *elem = init_monster(type, tab_pos);
    monster *temp = li->first;
    if (li->first == NULL && li->last == NULL) {
        li->first = elem;
        li->last = elem;
    } else {
        li->last->next = elem;
        li->last = elem;
    }
    li->length += 1;
}

void create_wave_two(li_monster *all_wave, li_monster *temp, li_monster *li)
{
    if (all_wave != NULL) {
        temp = all_wave;
        while (temp->next_wave != NULL)
            temp = temp->next_wave;
        li->prev_wave = temp;
        temp->next_wave = li;
    }
}

li_monster *create_wave(char *my_wave, li_monster *all_wave, \
                                    sfVector2i spawn, int volume)
{
    li_monster *li = init_wave(volume);
    li_monster *temp = NULL;
    int type, new_type;
    int a = 0, p = 0, i = 0;
    create_wave_two(all_wave, temp, li);
    while (my_wave[i] != '\n' && i < my_strlen(my_wave)) {
        create_wave_three(my_wave, &new_type, &type, &i);
        for (a = my_getnbr_n(my_wave, i) ; a != 0 ; a--)
            push_in_list(li, type, spawn);
        how_many_digit(my_getnbr_n(my_wave, i), &p);
        i += p;
        if (my_wave[i] == '|' || my_wave[i] == ':')
            i += 2;
        p = 0;
    }
    if (all_wave != NULL)
        return (all_wave);
    else
        return (li);
}