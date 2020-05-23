/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_help
*/

#include "my.h"
#include "struct.h"

void init_help_two(help_s *h)
{
    h->improvment = init_pos_txt((sfVector2f) {1110, 440}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": To improves the towers."));
    h->coin = init_pos_txt((sfVector2f) {1120, 580}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": To sell the towers."));
    h->timer = init_pos_txt((sfVector2f) {1120, 130}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": Time before the next wave."));
    h->monster = init_pos_txt((sfVector2f) {315, 750}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": Number of monsters present on the map."));
    h->space = init_pos_txt((sfVector2f) {315, 590}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": To go to another wave of monsters(in game)."));
}

help_s *init_help(void)
{
    help_s *h = malloc(sizeof(*h));
    h->font = sfFont_createFromFile("Ressources/Font/Medieval2.ttf");
    h->back = init_button((sfVector2f) {0, 900}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "    Back");
    h->fond = create_sprite("Ressources/Images/Fond/help.png");
    h->escape = init_pos_txt((sfVector2f) {300, 450}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": Press espace in game to pause the session."));
    h->grass_h = init_pos_txt((sfVector2f) {300, 280}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": Location for the towers. Press H to see them."));
    h->mouse = init_pos_txt((sfVector2f) {1110, 280}, \
    create_txt(35, h->font, sfColor_fromRGB(255, 255, 0), \
    ": Left click to select the tours and to enter the tours menu\n \
    for their improvement. But also to exit of this menu."));
    init_help_two(h);
    return (h);
}