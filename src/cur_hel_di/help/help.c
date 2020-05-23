/*
** EPITECH PROJECT, 2020
** defender
** File description:
** help$
*/

#include "my.h"
#include "struct.h"

void draw_help(sfRenderWindow *w, help_s *help, cursor *cur)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000)) {
        hover_one(help->back, 370, 910, sfWhite);
    } else
        hover_two(help->back, 370, 900, sfBlack);
    sfRenderWindow_drawSprite(w, help->fond, NULL);
    draw_button(help->back, w);
    draw_pos_txt(help->escape, w);
    draw_pos_txt(help->space, w);
    draw_pos_txt(help->mouse, w);
    draw_pos_txt(help->improvment, w);
    draw_pos_txt(help->coin, w);
    draw_pos_txt(help->timer, w);
    draw_pos_txt(help->monster, w);
    draw_pos_txt(help->grass_h, w);
    draw_cursor(cur, w);
}

void event_help(sfRenderWindow *w, all *all, cursor *cur)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            all->back = 1;
        if (e.type == sfEvtMouseButtonPressed) {
            cur->choose = 10;
            sfVector2i m = sfMouse_getPositionRenderWindow(w);
            if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000))
                all->back = 1;
        }
    }
}

void help(sfRenderWindow *w, all *all, help_s *help)
{
    while (sfRenderWindow_isOpen(w) && all->back == 0) {
        sfRenderWindow_clear(w, sfBlack);
        draw_help(w, help, all->cur);
        event_help(w, all, all->cur);
        sfRenderWindow_display(w);
    }
    all->back -= 1;
    sfClock_restart(all->menu->wait);
}