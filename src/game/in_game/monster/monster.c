/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

int is_path(char a)
{
    if (a == 'x' || a == 'X' || a == 'r' || \
    a == 'R' || a == 'l' || a == 'L' || a == 'y')
        return (1);
    return (0);
}

void speed_monster(all *all, monster *elem, lvl *lvl)
{
    int x = elem->tab_pos.x;
    int y = elem->tab_pos.y;

    if (lvl->map[y][x] == 'c') {
        all->game->hud->life->value -= elem->type * all->game->dif;
        elem->state = DEAD;
    }
    if (lvl->map[y][x] == 'X' || lvl->map[y][x] == '2' || \
    lvl->map[y][x] == 'L' || lvl->map[y][x] == 'l')
        go_right(elem);
    if (lvl->map[y][x] == '3' || lvl->map[y][x] == 'R' || \
    lvl->map[y][x] == 'r')
        go_left(elem);
    if (lvl->map[y][x] == '4' || lvl->map[y][x] == 'g' || \
    lvl->map[y][x] == 'd' || lvl->map[y][x] == 'Y')
        go_up(elem);
    if (lvl->map[y][x] == '5' || lvl->map[y][x] == 'G' || \
    lvl->map[y][x] == 'D')
        go_down(elem);
}

void new_wave(all *all)
{
    sfTime time = sfClock_getElapsedTime(all->game->clock_wave);
    char *str = NULL;
    int nb_wave = count_length_li(all->game->li);

    if (!(nb_wave >= len_tab(all->game->choose_one->wave)))
        sfText_setString(all->game->int_time_wave->txt, (int_to_str\
        (((40 - all->game->dif * 4) - (int) sfTime_asSeconds(time)), str)));
    else
        sfText_setString(all->game->int_time_wave->txt, "0");

    if (sfTime_asSeconds(time) >= 40 - all->game->dif * 4 \
                            || all->game->send_wave == 1) {
        if (!(nb_wave >= len_tab(all->game->choose_one->wave)))
            all->game->li = create_wave(all->game->choose_one->wave[nb_wave], \
            all->game->li, find_spawn(all->game->choose_one->map), all->volume);
        sfClock_restart(all->game->clock_wave);
        all->game->send_wave = 0;
    }
}

void my_monster(all *all)
{
    li_monster *li = all->game->li;
    monster *elem;
    new_wave(all);

    while (li != NULL) {
        elem = li->first;
        while (elem != NULL) {
            if (sfClock_getElapsedTime(li->one).microseconds >= 500000 && \
            elem->state == STASIS) {
                elem->state = ALIVE;
                sfClock_restart(li->one);
            }
            if (elem->state == ALIVE)
                speed_monster(all, elem, all->game->choose_one);
            elem = elem->next;
        }
        li = li->next_wave;
    }
    sfClock_restart(all->game->move);
}