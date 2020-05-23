/*
** EPITECH PROJECT, 2020
** defend
** File description:
** init_button
*/

#include "my.h"
#include "struct.h"

credits_s *init_credits(void)
{
    credits_s *c = malloc(sizeof(*c));
    c->font = sfFont_createFromFile("Ressources/Font/Medieval.ttf");
    c->back = init_button((sfVector2f) {0, 900}, (sfIntRect) \
    {370, 465, 532, 100}, sfBlack, "    Back");
    c->defile = init_pos_txt((sfVector2f)\
    {500, 100}, create_txt(70, c->font, sfWhite, \
    "\t\tArtistic director : \
    \n\t\t\tClement Berard \n\n\t\tThe brain gameplay :\
    \n\t\t\tRaphael Giordano\n\n\t\tDevelopper :\n\t\t\tClement Berard \
    \n\t\t\tRaphael Giordano\n\n\t\tAwards :\n\t\t\tBest Game of the year\
    \n\t\t\tBetter than Witcher 3"));
    c->tete = create_sprite("Ressources/Images/Util/tete.png");
    c->mov_txt = sfClock_create();
    c->music = create_music("Ressources/Music/credits.ogg", sfTrue, sfFalse);
    sfMusic_setVolume(c->music, 100);
    return (c);
}