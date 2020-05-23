/*
** EPITECH PROJECT, 2020
** MUL_my_defender_2019
** File description:
** init_win_lose
*/

#include "struct.h"
#include "my.h"

wlo *init_win_lose(void)
{
    wlo *wlo = malloc(sizeof(*wlo));
    wlo->font = sfFont_createFromFile("Ressources/Font/Medieval2.ttf");
    wlo->win = create_sprite("Ressources/Images/Fond/win.jpg");
    wlo->lose = create_sprite("Ressources/Images/Fond/lose.jpg");
    sfSprite_scale(wlo->lose, (sfVector2f) {2.3, 2.3});
    sfSprite_scale(wlo->win, (sfVector2f) {4, 4.6});
    wlo->clock = sfClock_create();
    wlo->ret = init_pos_txt((sfVector2f) {500, 900}, create_txt \
    (80, wlo->font, sfRed, "Press M to go back to the menu !"));
    wlo->men = init_pos_txt((sfVector2f) {500, 900}, create_txt \
    (80, wlo->font, sfRed, "Press M to go back to the menu !"));
    return (wlo);
}