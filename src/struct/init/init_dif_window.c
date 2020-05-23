/*
** EPITECH PROJECT, 2020
** defend
** File description:
** init_button
*/

#include "my.h"
#include "struct.h"

dif_window *init_dif_window(game *game)
{
    dif_window *dif = malloc(sizeof(*dif));
    dif->fond = create_sprite("Ressources/Images/Fond/dif.png");
    dif->diff = create_sprite("Ressources/Images/Fond/diff.jpg");
    dif->easy = init_button((sfVector2f) {200, 100}, (sfIntRect) \
    {370, 465, 532, 100}, sfGreen, "   Normal");
    dif->normal = init_button((sfVector2f) {700, 100}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "  Nightmare");
    dif->hard = init_button((sfVector2f) {1200, 100}, (sfIntRect) \
    {370, 465, 532, 100}, sfRed, "   Infernal");
    dif->back = init_button((sfVector2f) {0, 900}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "    Back");
    dif->txt = init_pos_txt((sfVector2f) {300, 555}, \
    create_txt(50, game->font, sfRed, \
    "The difficulty option changes the speed and the stats of the enemies !"));
    return (dif);
}