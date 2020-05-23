/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

void init_tile_two(tile *tile)
{
    tile->tree_2 = (sfIntRect) {597, 340, 40, 50};
    tile->tree_3 = (sfIntRect) {636, 340, 50, 50};
    tile->hut = (sfIntRect) {575, 25, 50, 40};
    tile->stone = (sfIntRect) {550, 419, 25, 25};
    tile->sand = (sfIntRect) {602, 395, 50, 20};
}

tile *init_tile(void)
{
    tile *tile = malloc(sizeof(*tile));
    tile->sprite = create_sprite("Ressources/game/map/tileset.png");
    tile->grass = (sfIntRect) {251, 325, 50, 50};
    tile->path_x = (sfIntRect) {251, 380, 50, 50};
    tile->path_y = (sfIntRect) {196, 270, 50, 50};
    tile->top_left = (sfIntRect) {31, 215, 50, 50};
    tile->top_right = (sfIntRect) {141, 215, 50, 50};
    tile->bot_left = (sfIntRect) {31, 324, 50, 50};
    tile->bot_right = (sfIntRect) {141, 326, 50, 50};
    tile->castle = (sfIntRect) {584, 249, 79, 86};
    tile->cross = (sfIntRect) {306, 325, 50, 50};
    tile->tree_1 = (sfIntRect) {546, 336, 50, 50};
    init_tile_two(tile);
    return (tile);
}