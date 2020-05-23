/*
** EPITECH PROJECT, 2020
** defender
** File description:
** init_menu
*/

#include "my.h"
#include "struct.h"

menu_next *init_menu_next(int loaded, char *file)
{
    menu_next *next = malloc(sizeof(*next));
    next->level1 = init_button((sfVector2f) {730, 300}, (sfIntRect) \
    {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "   Level 1");
    next->level2 = init_button((sfVector2f) {730, 450}, (sfIntRect) \
    {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "   Level 2");
    if (loaded == 0) {
        next->loaded = init_button((sfVector2f) {730, 600}, (sfIntRect) \
        {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "   Level 3");
    } else
        next->loaded = init_button((sfVector2f) {730, 600}, (sfIntRect) \
        {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), file);
    next->back = init_button((sfVector2f) {730, 750}, (sfIntRect) \
    {370, 465, 532, 100}, sfColor_fromRGB(0, 0, 0), "     Back");
    return (next);
}