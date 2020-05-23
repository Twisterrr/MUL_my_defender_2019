/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

void second_init_opt(opt *opt)
{
    opt->high_res = init_button((sfVector2f) {850, 700}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "  1920x1080");
    opt->low_res = init_button((sfVector2f) {1350, 700}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "  1600x900");
    opt->up_sound = init_button((sfVector2f) {850, 550}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "   + VOL");
    opt->down_sound = init_button((sfVector2f) {1350, 550}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "   - VOL");
    opt->back = init_button((sfVector2f) {0, 900}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "    Back");
    opt->up_frame_limit = init_button((sfVector2f) {850, 250}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, " + FRAME");
    opt->down_frame_limit = init_button((sfVector2f) {1350, 250}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, " - FRAME");
}

opt *init_option(void)
{
    opt *opt = malloc(sizeof(*opt));
    opt->fond = create_sprite("Ressources/Images/Fond/option.jpg");
    opt->font = sfFont_createFromFile("Ressources/Font/Medieval.ttf");
    opt->int_frame_limit = init_pos_txt((sfVector2f) {670, 250}, \
    create_txt(75, opt->font, sfWhite, "64"));
    opt->warning = init_pos_txt((sfVector2f) {740, 800}, \
    create_txt(40, opt->font, sfRed, \
    "WARNING ! Resolution 1600x900 may affect your game experience."));
    opt->s_frame_limit = init_pos_txt((sfVector2f) {200, 250}, \
    create_txt(85, opt->font, sfWhite, "Frame limit :"));
    opt->sound = init_pos_txt((sfVector2f) {200, 550}, \
    create_txt(85, opt->font, sfWhite, "Volume :"));
    opt->int_sound = init_pos_txt((sfVector2f) {530, 550}, \
    create_txt(75, opt->font, sfWhite, "100"));
    opt->res = init_pos_txt((sfVector2f) {200, 700}, \
    create_txt(85, opt->font, sfWhite, "Resolution :"));
    second_init_opt(opt);
    return (opt);
}