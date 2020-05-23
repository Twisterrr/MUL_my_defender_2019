/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void draw_sell_up_two(sfRenderWindow *w, t_li *t, sfVector2f pos)
{
    sfRenderWindow_drawText(w, t->price_sell, NULL);
    sfRenderWindow_drawSprite(w, t->sprite_sell, NULL);
    sfText_setPosition(t->price_sell, (sfVector2f) {pos.x - 25, \
    pos.y + 50});
    sfSprite_setPosition(t->sprite_sell, (sfVector2f) {pos.x - 60, \
    pos.y + 40});
}

void draw_sell_up(sfRenderWindow *w, tower *elem, t_li *t, sfVector2f pos)
{
    char *str = NULL;
    sfSprite_setTextureRect(t->sprite_sell, t->rect_sell);
    sfSprite_setTextureRect(t->sprite_up, t->rect_up);
    sfRectangleShape_setPosition(t->range, (sfVector2f) \
    {pos.x - (float) (elem->range * 40), pos.y - (float) (elem->range * 38)});
    sfRectangleShape_setSize(t->range, \
    (sfVector2f) {(float) (elem->range * 49) * 2, \
    (float) (elem->range * 49) * 2});
    sfRenderWindow_drawRectangleShape(w, t->range, NULL);
    if (elem->level != 3) {
        sfText_setPosition(t->price_up, (sfVector2f) {pos.x + 75, \
        pos.y + 50});
        sfSprite_setPosition(t->sprite_up, (sfVector2f) {pos.x + 75, \
        pos.y + 75});
        sfRenderWindow_drawText(w, t->price_up, NULL);
        sfRenderWindow_drawSprite(w, t->sprite_up, NULL);
    }
    sfText_setString(t->price_sell, int_to_str(elem->cost / 3, str));
    sfText_setString(t->price_up, int_to_str(elem->cost, str));
    draw_sell_up_two(w, t, pos);
}

void draw_cursor_tower(clicked *c, sfIntRect rect, sfVector2f m, \
                                                sfRenderWindow *w)
{
    sfSprite_setTextureRect(c->tower, rect);
    sfSprite_setPosition(c->tower, m);
    sfSprite_setColor(c->tower, sfRed);
    sfRenderWindow_drawSprite(w, c->tower, NULL);
    sfRectangleShape_setPosition(c->range, (sfVector2f) \
    {m.x - (float) (c->int_range * 40), m.y - (float) (c->int_range * 38)});
    sfRectangleShape_setSize(c->range, \
    (sfVector2f) {(float) (c->int_range * 49) * 2, \
    (float) (c->int_range * 49) * 2});
    sfRenderWindow_drawRectangleShape(w, c->range, NULL);
}

void draw_tower_two(game *game, sfRenderWindow *w)
{
    if (game->c->state == 1) {
        sfVector2i m = sfMouse_getPositionRenderWindow(w);
        if (game->c->type == BOMB_TOWER) {
            game->c->int_range = 6;
            draw_cursor_tower(game->c, game->c->rect_t1, \
                    (sfVector2f) {(float) m.x - 45, (float) m.y - 60}, w);
        }
        if (game->c->type == SNIPER_TOWER) {
            game->c->int_range = 10;
            draw_cursor_tower(game->c, game->c->rect_t2, \
                    (sfVector2f) {(float) m.x - 45, (float) m.y - 60}, w);
        }
        if (game->c->type == COLD_TOWER) {
            game->c->int_range = 5;
            draw_cursor_tower(game->c, game->c->rect_t3, \
                    (sfVector2f) {(float) m.x - 45, (float) m.y - 60}, w);
        }
        draw_tower_three(game, w, m);
    }
}

void draw_tower(game *game, sfRenderWindow *w)
{
    tower *elem = game->t_li->first;
    sfVector2f pos;

    while (elem != NULL) {
        pos = (sfVector2f) {(elem->tab_pos.x * 49) - 15, \
                            (elem->tab_pos.y * 49) - 60};
        sfSprite_setPosition(elem->sprite, pos);
        sfSprite_setTextureRect(elem->sprite, elem->rect);
        sfRenderWindow_drawSprite(w, elem->sprite, NULL);
        if (elem->click_on == 1)
            draw_sell_up(w, elem, game->t_li, pos);
        elem = elem->next;
    }
    draw_tower_two(game, w);
}