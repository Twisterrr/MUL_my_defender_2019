/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

sfVector2i find_spawn(char **map)
{
    for (int i = 0 ; map[i] != NULL ; i++) {
        for (int a = 0 ; map[i][a] != '\0' ; i++) {
            if (map[i][a] == 'X')
                return ((sfVector2i) {a, i});
        }
    }
    return ((sfVector2i) {0, 0});
}

int how_many(li_monster *li)
{
    li_monster *temp = li;
    monster *elem;
    int compt = 0;

    while (temp != NULL) {
        elem = temp->first;
        while (elem != NULL) {
            if (elem->state == STASIS || elem->state == ALIVE)
                compt++;
            elem = elem->next;
        }
        temp = temp->next_wave;
    }
    return (compt);
}

void draw_all_game(all *all)
{
    sfRenderWindow_clear(all->w, sfColor_fromRGB(55, 140, 15));
    draw_map(all->w, all->game->choose_one, all->game, all);
    draw_monster(all->game->li, all->w);
    sfSprite_setPosition(all->game->hud->timer, (sfVector2f) {0, 40});
    sfRenderWindow_drawSprite(all->w, all->game->hud->timer, NULL);
    draw_pos_txt(all->game->int_time_wave, all->w);
    draw_hud(all, all->w, all->game->hud);
    draw_tower(all->game, all->w);
    draw_cursor(all->cur, all->w);
    sfRenderWindow_display(all->w);
}

void set_the_game(all *all)
{
    all->game->dif = choose_difficulty(all);
    sfClock_restart(all->game->clock_wave);
    sfMusic_pause(all->menu->music);
    sfMusic_play(all->game->music);
    all->game->t_li = init_tower_list(all->game);
    all->game->li = create_wave(all->game->choose_one->wave[0], \
    NULL, find_spawn(all->game->choose_one->map), all->volume);
}

void my_game(all *all)
{
    set_the_game(all);

    while (sfRenderWindow_isOpen(all->w) && all->back == 0) {
        if (sfClock_getElapsedTime(all->game->move).microseconds > \
        75000 / all->game->dif)
            my_monster(all);
        tower_attack(all->game);
        draw_all_game(all);
        event_game(all->w, all);
        win_game(all, all->w);
        lose_game(all, all->w);
    }
    reset_game(all->game);
    all->back -= 1;
    sfClock_restart(all->menu->wait);
}