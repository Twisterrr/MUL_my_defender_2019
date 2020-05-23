/*
** EPITECH PROJECT, 2019
** duck_hunt
** File description:
** create_music
*/

#include "my.h"
#include "struct.h"

sfMusic *create_music(char *name, int loop, int play)
{
    sfMusic *m = sfMusic_createFromFile(name);
    sfMusic_setLoop(m, loop);
    if (play == sfTrue)
        sfMusic_play(m);
    return (m);
}