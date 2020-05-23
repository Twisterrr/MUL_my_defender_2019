/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** Pause menu of the Defender.
*/

#include "my.h"
#include "struct.h"

void pressed_resume(sfRenderWindow *w, all *all)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 840 && m.x <= 1060) && (m.y >= 348 && m.y <= 391))
        all->back = 1;
}

void pressed_menu(sfRenderWindow *w, all *all)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 803 && m.x <= 1094) && (m.y >= 543 && m.y <= 639))
        all->back = 3;
}

void event_pause(sfRenderWindow *w, all *all)
{
    sfEvent e;
    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (sfKeyboard_isKeyPressed(sfKeySpace))
            all->back = 1;
        if (e.type == sfEvtMouseButtonPressed) {
            all->cur->choose = 10;
            pressed_resume(w, all);
            pressed_menu(w, all);
            pressed_quit_two(all->menu, w, all);
            sfMusic_pause(all->game->music);
            sfMusic_play(all->game->music);
        }
    }
}

void draw_pause_two(sfRenderWindow *w, all *all)
{
    draw_pos_txt(all->my_p->title, w);
    draw_pos_txt(all->my_p->resume, w);
    draw_pos_txt(all->my_p->quit, w);
    draw_pos_txt(all->my_p->menu, w);
    draw_cursor(all->cur, w);
    event_pause(w, all);
    sfRenderWindow_display(w);
}

void draw_pause(sfRenderWindow *w, all *all)
{
    if (sfClock_getElapsedTime(all->game->wait).microseconds >= 100000) {
        while (sfRenderWindow_isOpen(w) && all->back == 0) {
            draw_map(w, all->game->choose_one, all->game, all);
            draw_monster(all->game->li, w);
            draw_hud(all, w, all->game->hud);
            draw_tower(all->game, w);
            draw_pos_txt(all->game->int_time_wave, w);
            sfRenderWindow_drawSprite(w, all->game->hud->timer, NULL);
            sfSprite_setPosition(all->my_p->fond, (sfVector2f) {450, 0});
            sfRenderWindow_drawSprite(w, all->my_p->fond, NULL);
            draw_pause_two(w, all);
        }
        all->back -= 1;
    }
}