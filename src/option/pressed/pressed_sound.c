/*
** EPITECH PROJECT, 2020
** defender
** File description:
** pressed_back
*/

#include "my.h"
#include "struct.h"

void set_vol(all *all)
{
    sfSound_setVolume(all->menu->sound_button, all->volume);
    sfMusic_setVolume(all->cre->music, all->volume);
    sfMusic_setVolume(all->menu->music, all->volume);
    sfMusic_setVolume(all->game->music, all->volume);
}

void pressed_sound(opt *opt, sfRenderWindow *w, all *all)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);
    char *str = malloc(sizeof(char) * (10));
    if ((m.x >= 855 && m.x <= 1255) && (m.y >= 555 && m.y <= 655)) {
        if (all->volume != 100)
            all->volume += 10;
        sfText_setString(opt->int_sound->txt, \
        int_to_str(all->volume, str));
        sfSound_play(all->menu->sound_button);
        set_vol(all);
    }
    if ((m.x >= 1355 && m.x <= 1755) && (m.y >= 555 && m.y <= 655)) {
        if (all->volume != 0)
            all->volume -= 10;
        sfText_setString(opt->int_sound->txt, \
        int_to_str(all->volume, str));
        sfSound_play(all->menu->sound_button);
        set_vol(all);
    }
    free (str);
}