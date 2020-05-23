/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_help
*/

#include "my.h"
#include "struct.h"

void more_hud_2(hud *hud)
{
    hud->s_t1 = init_pos_txt((sfVector2f) {665, 920}, create_txt(20, \
    hud->font, sfWhite, "Bomb tower"));
    hud->s_t2 = init_pos_txt((sfVector2f) {815, 920}, create_txt(20, \
    hud->font, sfWhite, "Sniper tower"));
    hud->s_t3 = init_pos_txt((sfVector2f) {965, 920}, create_txt(20, \
    hud->font, sfWhite, "Cold tower"));
    hud->s_t4 = init_pos_txt((sfVector2f) {1115, 920}, create_txt(20, \
    hud->font, sfWhite, "Arrow Tower"));
    hud->i_t1 = init_pos_txt((sfVector2f) {665, 980}, create_txt(25, \
    hud->font, sfYellow, "250"));
    hud->i_t2 = init_pos_txt((sfVector2f) {815, 980}, create_txt(25, \
    hud->font, sfYellow, "200"));
    hud->i_t3 = init_pos_txt((sfVector2f) {965, 980}, create_txt(25, \
    hud->font, sfYellow, "150"));
    hud->i_t4 = init_pos_txt((sfVector2f) {1115, 980}, create_txt(25, \
    hud->font, sfYellow, "100"));
}

void more_hud(hud *hud)
{
    hud->timer = create_sprite("Ressources/game/map/timer.png");
    sfSprite_scale(hud->timer, (sfVector2f) {0.5, 0.5});
    hud->tower = create_sprite("Ressources/game/map/Towers.png");
    sfSprite_scale(hud->tower, (sfVector2f) {1.5, 1.5});
    hud->rect_t1 = (sfIntRect) {0, 182, 52, 74};
    hud->rect_t2 = (sfIntRect) {165, 266, 48, 70};
    hud->rect_t3 = (sfIntRect) {0, 108, 52, 70};
    hud->rect_t4 = (sfIntRect) {0, 266, 55, 75};
    more_hud_2(hud);
}

hud *init_hud(void)
{
    hud *hud = malloc(sizeof(*hud));
    hud->font = sfFont_createFromFile("Ressources/Font/Medieval2.ttf");
    hud->int_remaining = init_pos_txt((sfVector2f) {90, 95}, create_txt(60, \
    hud->font, sfRed, "0"));
    hud->monster_wave = create_sprite \
    ("Ressources/game/Monster/monster_wave.png");
    sfSprite_scale(hud->monster_wave, (sfVector2f) {0.4, 0.4});
    hud->interface_towers = create_sprite("Ressources/game/map/tower_bar.png");
    hud->coin = init_ply_ress((sfIntRect) {60, 55, 75, 58}, \
    (sfVector2f) {20, 900}, "Ressources/game/map/coins.png", 1000);
    hud->life = init_ply_ress((sfIntRect) {0, 31, 120, 85}, \
    (sfVector2f) {1720, 880}, "Ressources/game/map/heart.png", 20);
    hud->s_coin = init_pos_txt((sfVector2f) {150, 920}, create_txt(75, \
    hud->font, sfColor_fromRGB(255, 255, 0), "250"));
    hud->s_life = init_pos_txt((sfVector2f) {1680, 900}, create_txt(75, \
    hud->font, sfColor_fromRGB(247, 99, 99), "20"));
    more_hud(hud);
    return (hud);
}