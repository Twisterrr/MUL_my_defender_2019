/*
** EPITECH PROJECT, 2020
** defender
** File description:
** credits
*/

#include "my.h"
#include "struct.h"

void draw_credits_2(credits_s *c, sfRenderWindow *w)
{
    int red, green, blue;
    sfVector2i m = sfMouse_getPositionRenderWindow(w);

    if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000)) {
        hover_one(c->back, 370, 910, sfWhite);
    } else
        hover_two(c->back, 370, 900, sfBlack);
    draw_button(c->back, w);
    if (sfClock_getElapsedTime(c->mov_txt).microseconds > 100000) {
        sfClock_restart(c->mov_txt);
        red = rand();
        green = rand();
        blue = rand();
        sfText_setColor(c->defile->txt, sfColor_fromRGB(red, green, blue));
        c->defile->pos.y -= 2;
    }
}

void draw_credits(sfRenderWindow *w, credits_s *c)
{
    sfVector2i credits = sfMouse_getPositionRenderWindow(w);
    sfVector2f cre, cre_2;
    cre.x = (int) credits.x - 1500;
    cre.y = (int) credits.y - 1500;
    cre_2.x = (int) credits.x + 1500;
    cre_2.y = (int) credits.y - 1500;

    draw_pos_txt(c->defile, w);
    for (int i = 0 ; i != 40 ; i++) {
        sfSprite_setPosition(c->tete, cre);
        sfRenderWindow_drawSprite(w, c->tete, NULL);
        sfSprite_setPosition(c->tete, cre_2);
        sfRenderWindow_drawSprite(w, c->tete, NULL);
        cre.x += 100;
        cre.y += 100;
        cre_2.x -= 100;
        cre_2.y += 100;
    }
    draw_credits_2(c, w);
}

void event_credits(sfRenderWindow *w, all *all)
{
    sfEvent e;

    while (sfRenderWindow_pollEvent(w, &e)) {
        if (e.type == sfEvtClosed)
            sfRenderWindow_close(w);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            all->back = 1;
        if (e.type == sfEvtMouseButtonPressed) {
            sfVector2i m = sfMouse_getPositionRenderWindow(w);
            if ((m.x >= 0 && m.x <= 410) && (m.y >= 900 && m.y <= 1000))
                all->back = 1;
        }
    }
}

void credits(sfRenderWindow *w, credits_s *c, menu *menu, all *all)
{
    sfMusic_pause(menu->music);
    sfMusic_play(c->music);
    c->defile->pos = (sfVector2f) {500, 100};
    while (sfRenderWindow_isOpen(w) && all->back == 0) {
        sfRenderWindow_clear(w, sfBlack);
        draw_credits(w, c);
        event_credits(w, all);
        sfRenderWindow_display(w);
    }
    all->back -= 1;
    sfMusic_pause(c->music);
    sfMusic_play(menu->music);
    sfClock_restart(menu->wait);
}