/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

void second_init_menu(menu *menu)
{
    menu->credit = init_pos_txt((sfVector2f) {20, 920}, \
    create_txt(80, menu->font, sfWhite, "Credits"));
    menu->sound_buffer = sfSoundBuffer_createFromFile( \
    "Ressources/Sound/button_press.ogg");
    menu->wait = sfClock_create();
    menu->sound_button = sfSound_create();
    sfSound_setVolume(menu->sound_button, 100);
    sfSound_setBuffer(menu->sound_button, menu->sound_buffer);
}

menu *init_menu(int loaded, char *file)
{
    menu *menu = malloc(sizeof(*menu));
    menu->music = create_music("Ressources/Music/menu.ogg", sfTrue, sfTrue);
    sfMusic_setVolume(menu->music, 100);
    menu->next = init_menu_next(loaded, file);
    menu->fond = create_sprite("Ressources/Images/Fond/menu.jpg");
    menu->font = sfFont_createFromFile("Ressources/Font/Medieval.ttf");
    menu->titre = init_pos_txt((sfVector2f) {640, 65}, \
    create_txt(100, menu->font, sfColor_fromRGB(215, 85, 74), \
    "King's Mercy !"));
    menu->b_play = init_button((sfVector2f) {730, 300}, (sfIntRect) \
    {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "     Play");
    menu->b_quit = init_button((sfVector2f) {730, 500}, (sfIntRect) \
    {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "     Quit");
    menu->b_opt = init_button((sfVector2f) {730, 700}, (sfIntRect) \
    {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "    Option");
    second_init_menu(menu);
    return (menu);
}