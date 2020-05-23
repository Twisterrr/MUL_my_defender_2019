/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

li_monster *init_wave(int volume)
{
    li_monster *li = malloc(sizeof(*li));
    li->buffer = sfSoundBuffer_createFromFile("Ressources/Sound/death.ogg");
    li->death = sfSound_create();
    sfSound_setBuffer(li->death, li->buffer);
    sfSound_setVolume(li->death, volume);
    li->first = NULL;
    li->last = NULL;
    li->length = 0;
    li->next_wave = NULL;
    li->prev_wave = NULL;
    li->one = sfClock_create();
    return (li);
}