/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_pause
*/

#include "my.h"
#include "struct.h"

pause_s *init_pause(void)
{
    pause_s *p = malloc(sizeof(*p));
    p->fond = create_sprite("Ressources/Images/Fond/pause.png");
    p->font = sfFont_createFromFile("Ressources/Font/Medieval2.ttf");
    p->title = init_pos_txt((sfVector2f) {725, 150}, \
    create_txt(100, p->font, sfBlack, "King's Mercy"));
    p->resume = init_pos_txt((sfVector2f) {850, 330}, \
    create_txt(65, p->font, sfBlack, "Resume"));
    p->menu = init_pos_txt((sfVector2f) {900, 545}, \
    create_txt(65, p->font, sfBlack, "Menu"));
    p->quit = init_pos_txt((sfVector2f) {900, 700}, \
    create_txt(65, p->font, sfBlack, "Quit"));
    return (p);
}