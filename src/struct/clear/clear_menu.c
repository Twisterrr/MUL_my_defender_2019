/*
** EPITECH PROJECT, 2020
** defender
** File description:
** clear_menu
*/

#include "my.h"
#include "struct.h"

menu *clear_menu(menu *menu)
{
    sfSprite_destroy(menu->fond);
    sfMusic_stop(menu->music);
    sfSound_destroy(menu->sound_button);
    sfSoundBuffer_destroy(menu->sound_buffer);
    sfFont_destroy(menu->font);
    sfMusic_destroy(menu->music);
    menu = NULL;
    return (NULL);
}