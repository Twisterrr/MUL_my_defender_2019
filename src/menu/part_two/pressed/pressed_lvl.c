/*
** EPITECH PROJECT, 2020
** defender
** File description:
** event_menu_next
*/

#include "my.h"
#include "struct.h"

void pressed_lvl(menu *menu, sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(menu->wait).microseconds >= 10000) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if ((m.x >= 730 && m.x <= 1130) && (m.y >= 295 && m.y <= 395)) {
            sfSound_play(menu->sound_button);
            all->game->choose_one = all->game->level1;
            my_game(all);
        } else if ((m.x >= 730 && m.x <= 1130) && (m.y >= 440 && m.y <= 540)) {
            sfSound_play(menu->sound_button);
            all->game->choose_one = all->game->level2;
            my_game(all);
        } else if ((m.x >= 730 && m.x <= 1130) && (m.y >= 600 && m.y <= 700)) {
            sfSound_play(menu->sound_button);
            all->game->choose_one = all->game->level3;
            my_game(all);
        }
    }
}