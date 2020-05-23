/*
** EPITECH PROJECT, 2020
** defender
** File description:
** option
*/

#include "my.h"
#include "struct.h"

void draw_tower_bar_2(sfRenderWindow *w, hud *hud)
{
    draw_pos_txt(hud->s_t1, w);
    draw_pos_txt(hud->s_t2, w);
    draw_pos_txt(hud->s_t3, w);
    draw_pos_txt(hud->s_t4, w);
    draw_pos_txt(hud->i_t1, w);
    draw_pos_txt(hud->i_t2, w);
    draw_pos_txt(hud->i_t3, w);
    draw_pos_txt(hud->i_t4, w);
}

void draw_tower_bar(sfRenderWindow *w, hud *hud)
{
    sfVector2f pos = {665, 900};
    sfSprite_setTextureRect(hud->tower, hud->rect_t1);
    sfSprite_setPosition(hud->tower, pos);
    sfRenderWindow_drawSprite(w, hud->tower, NULL);
    pos.x += 150;
    sfSprite_setTextureRect(hud->tower, hud->rect_t2);
    sfSprite_setPosition(hud->tower, pos);
    sfRenderWindow_drawSprite(w, hud->tower, NULL);
    pos.x += 150;
    sfSprite_setTextureRect(hud->tower, hud->rect_t3);
    sfSprite_setPosition(hud->tower, pos);
    sfRenderWindow_drawSprite(w, hud->tower, NULL);
    pos.x += 150;
    sfSprite_setTextureRect(hud->tower, hud->rect_t4);
    sfSprite_setPosition(hud->tower, pos);
    sfRenderWindow_drawSprite(w, hud->tower, NULL);
    draw_tower_bar_2(w, hud);
}

void draw_hud(all *all, sfRenderWindow *w, hud *hud)
{
    char *str = NULL;

    draw_money(all->w, all->game->hud->coin, all);
    draw_life(all->w, all->game->hud->life, all);
    sfSprite_setPosition(all->game->hud->interface_towers, \
    (sfVector2f) {570, 800});
    sfRenderWindow_drawSprite(all->w, all->game->hud->interface_towers, NULL);
    sfSprite_setPosition(hud->monster_wave, (sfVector2f) {10, 110});
    sfRenderWindow_drawSprite(all->w, hud->monster_wave, NULL);
    sfText_setString(hud->int_remaining->txt, \
    int_to_str(how_many(all->game->li), str));
    draw_pos_txt(hud->int_remaining, w);
    draw_tower_bar(w, hud);
}