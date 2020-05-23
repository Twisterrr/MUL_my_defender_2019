/*
** EPITECH PROJECT, 2020
** defender
** File description:
** draw_menu
*/

#include "my.h"
#include "struct.h"

void draw_button_opt(opt *opt, sfRenderWindow *w)
{
    draw_button(opt->high_res, w);
    draw_button(opt->low_res, w);
    draw_button(opt->back, w);
    draw_button(opt->down_frame_limit, w);
    draw_button(opt->down_sound, w);
    draw_button(opt->up_frame_limit, w);
    draw_button(opt->up_sound, w);
}

void draw_option(opt *opt, sfRenderWindow *w, cursor * cur)
{
    sfRenderWindow_drawSprite(w, opt->fond, NULL);
    hover_option(opt, w);
    draw_pos_txt(opt->int_frame_limit, w);
    draw_pos_txt(opt->int_sound, w);
    draw_pos_txt(opt->res, w);
    draw_pos_txt(opt->s_frame_limit, w);
    draw_pos_txt(opt->sound, w);
    draw_pos_txt(opt->warning, w);
    draw_button_opt(opt, w);
    draw_cursor(cur, w);
}