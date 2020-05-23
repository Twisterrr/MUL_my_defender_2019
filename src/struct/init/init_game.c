/*
** EPITECH PROJECT, 2020
** defend
** File description:
** init_button
*/

#include "my.h"
#include "struct.h"

t_li *init_tower_list(game *game)
{
    t_li *t = malloc(sizeof(*t));
    t->price_sell = create_txt(20, game->font, sfYellow, "10");
    t->price_up = create_txt(20, game->font, sfYellow, "10");
    t->sprite_sell = create_sprite("Ressources/game/map/coins.png");
    t->sprite_up = create_sprite("Ressources/game/map/arrow.png");
    sfSprite_scale(t->sprite_up, (sfVector2f) {0.05, 0.05});
    sfSprite_scale(t->sprite_sell, (sfVector2f) {0.6, 0.6});
    t->rect_up = (sfIntRect) {0, 0, 600, 600};
    t->rect_sell = (sfIntRect) {0, 0, 120, 120};
    t->range = sfRectangleShape_create();
    sfRectangleShape_setFillColor(t->range, sfTransparent);
    sfRectangleShape_setOutlineThickness(t->range, 2);
    sfRectangleShape_setOutlineColor(t->range, sfRed);
    t->first = NULL;
    return (t);
}

void init_game_two(game *g)
{
    g->int_time_wave = init_pos_txt((sfVector2f) {90, 40}, \
    create_txt(60, g->font, sfRed, "45"));
    g->h = 0;
    g->click_tower = 0;
    g->clock_wave = sfClock_create();
    g->music = create_music("Ressources/Music/game.ogg", sfTrue, sfFalse);
    sfMusic_setVolume(g->music, 100);
    g->clock_h = sfClock_create();
    g->move = sfClock_create();
    g->dif_w = init_dif_window(g);
    g->win_lose = init_win_lose();
}

game *init_game(void)
{
    game *g = malloc(sizeof(*g));
    g->dif = 0;
    g->font = sfFont_createFromFile("Ressources/Font/Medieval2.ttf");
    g->level1 = init_level("./legend/.map_1");
    g->level2 = init_level("./legend/.map_2");
    g->level3 = init_level("./legend/.map_3");
    g->choose_one = malloc(sizeof(*g->choose_one));
    g->tile = init_tile();
    g->send_wave = 0;
    g->my_p = init_pause();
    g->hud = init_hud();
    g->c = init_clicked_on();
    g->t_li = init_tower_list(g);
    g->wait = sfClock_create();
    init_game_two(g);
    return (g);
}