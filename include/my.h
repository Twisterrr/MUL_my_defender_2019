/*
** EPITECH PROJECT, 2019
** MUL_my_defender
** File description:
** Header of the Defender.
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include "struct.h"

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

//// LIB ////

int my_getnbr(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
char *int_to_str(int nb, char *str);
sfMusic *create_music(char *name, int loop, int play);
sfRenderWindow *create_window(char *name, int height, int width, int style);
sfSprite *create_sprite(char *texture);
sfText *create_txt(int size, sfFont *font, sfColor color, char *string);
void draw_button(button *button, sfRenderWindow *w);
void draw_pos_txt(pos_txt *pos_txt, sfRenderWindow *w);
int my_getnbr_n(char const *src, int depart);
int count_length_li(li_monster *li);
int len_tab(char **tab);
int my_strlen(char *str);
int how_many(li_monster *li);

//// GAME ////

void my_game(all *all);
void event_game(sfRenderWindow *w, all *all);
void draw_map(sfRenderWindow *w, lvl *lvl, game *game, all *all);
void draw_simple_tile(sfIntRect rect, sfRenderWindow *w, game *game,
                                                    sfVector2f pos);
void switch_fonction_5(all *all, sfVector2f pos, int i, int a);

int is_num(char a);
void create_wave_three(char *my_wave, int *new_type, int *type, int *i);
void up(tower *t, game *game);
void tower_sellup(game *game, all *all);
void pressed_towerbar(all *all, clicked *c);
void pressed_tower(all *all, game *game);
void set_tower_unclicked(t_li *t);

void reset_game(game *game);
void put_tower(game *game, sfRenderWindow *w);
void tower_attack(game *game);

void draw_money(sfRenderWindow *w, ply_ress *coin, all *all);
void draw_life(sfRenderWindow *w, ply_ress *life, all *all);
void draw_hud(all *all, sfRenderWindow *w, hud *hud);
void draw_tower(game *game, sfRenderWindow *w);
void draw_tower_three(game *game, sfRenderWindow *w, sfVector2i m);
void draw_cursor_tower(clicked *c, sfIntRect rect, sfVector2f m, \
                                                sfRenderWindow *w);

void my_monster(all *all);
void draw_monster(li_monster *li, sfRenderWindow *w);
li_monster *create_wave(char *my_wave, li_monster *prev, \
                            sfVector2i spawn, int volume);
void go_left(monster *elem);
void go_left_two(monster *elem);
void go_up(monster *elem);
void go_up_two(monster *elem);
void go_down(monster *elem);
void go_down_two(monster *elem);
void go_right(monster *elem);
void go_right_two(monster *elem);
int how_many(li_monster *li);

void event_diff(all *all, int *ret);
void draw_diff(game *game, sfRenderWindow *w, cursor *cur);
int choose_difficulty(all *all);
void hover_diff(game *game, sfRenderWindow *w);
void pressed_diff(sfRenderWindow *w, int *ret);
void pressed_back_diff(sfRenderWindow *w, all *all);

//// MENU ////

void my_menu(all *all);
void event_menu(menu *menu, sfRenderWindow *w, all *all);
void draw_menu(menu *menu, sfRenderWindow *w, cursor *cur);
void draw_button_menu(menu *menu, sfRenderWindow *w);
sfVector2i find_spawn(char **map);

void pressed_help(menu *menu, sfRenderWindow *w, help_s *help, all *all);
void pressed_credits(menu *menu, sfRenderWindow *w, all *all);
void pressed_play(menu *menu, sfRenderWindow *w, all *all);
void pressed_quit(menu *menu, sfRenderWindow *w, all *all);
void pressed_quit_two(menu *menu, sfRenderWindow *w, all *all);
void pressed_option(menu *menu, sfRenderWindow *w, all *all);

void hover_menu(menu *menu, sfRenderWindow *w);

void my_menu_two(all *all);
void event_menu_next(menu *menu, sfRenderWindow *w, all *all);

void hover_menu_next(menu *menu, sfRenderWindow *w);
void draw_menu_next(menu *menu, sfRenderWindow *w, cursor *cur);
void draw_button_menu_next(menu *menu, sfRenderWindow *w);

void pressed_back_next(menu *menu, sfRenderWindow *w, all *all);
void pressed_lvl(menu *menu, sfRenderWindow *w, all *all);

//// CREDITS && HELP ////

void credits(sfRenderWindow *w, credits_s *c, menu *menu, all *all);
void help(sfRenderWindow *w, all *all, help_s *help);

//// CURSOR ////

void draw_cursor(cursor *cur, sfRenderWindow *w);
void move_cursor(cursor *cur, sfRenderWindow *w);

//// PAUSE ////

void draw_pause(sfRenderWindow *w, all *all);

//// OPTION ////

void option(all *all);
void draw_option(opt *opt, sfRenderWindow *w, cursor *cur);
void event_option(opt *opt, sfRenderWindow *w, all *all);

void pressed_back(opt *opt, sfRenderWindow *w, all *all);
void pressed_sound(opt *opt, sfRenderWindow *w, all *all);
void pressed_frame(opt *opt, sfRenderWindow *w, all *all);
void pressed_res(opt *opt, sfRenderWindow *w, all *all);

void hover_option(opt *opt, sfRenderWindow *w);

//// HOVER ////

void hover_two(button *but, int one, int two, sfColor c);
void hover_one(button *but, int one, int two, sfColor c);

/// Win_Lose ///
void win_game(all *all, sfRenderWindow *w);
void lose_game(all *all, sfRenderWindow *w);

//// STRUCT (INIT) ////

all *init_all(int loaded, char *file);
opt *init_option(void);
menu *init_menu(int loaded, char *file);
menu_next *init_menu_next(int loaded, char *file);
all *clear_all(all *all);
menu *clear_menu(menu *menu);
button *init_button(sfVector2f pos, sfIntRect rect, sfColor color, char *txt);
cursor *init_cursor(void);
pos_txt *init_pos_txt(sfVector2f pos, sfText *text);
credits_s *init_credits(void);
game *init_game(void);
dif_window *init_dif_window(game *game);
help_s *init_help(void);
tile *init_tile(void);
lvl *init_level(char *file);
pause_s *init_pause(void);
monster *init_monster(int type, sfVector2i tab_pos);
li_monster *init_wave(int volume);
ply_ress *init_ply_ress(sfIntRect rect, sfVector2f pos,
                                    char *texture, int value);
hud *init_hud(void);
clicked *init_clicked_on(void);
tower *init_tower(sfVector2f pos, int type, sfVector2i tab_pos);
wlo *init_win_lose(void);
void init_arrow(tower *t);
void init_bomb(tower *t);
void init_cold(tower *t);
void init_sniper(tower *t);
t_li *init_tower_list(game *game);

//// CLEAR ////

t_li *clear_t_li(t_li *t);
tower *clear_tower(tower *t);
li_monster *clear_li(li_monster *li);

#endif /* DEFENDER_H_ */
