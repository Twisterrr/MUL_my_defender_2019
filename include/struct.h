/*
** EPITECH PROJECT, 2020
** MUL_my_defender
** File description:
** Struct header of the Defender.
*/

#ifndef STRUCT_H_
#define STRUCT_H_
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>

#define ALIVE 0
#define DEAD 1
#define STASIS 2
#define GOBELIN 1
#define CROC 2
#define BOSS 3
#define SNIPER_TOWER 0
#define COLD_TOWER 1
#define BOMB_TOWER 2
#define ARROW_TOWER 3

#define     RED "\033[1;31m"
#define   GREEN "\033[0;32m"
#define  YELLOW "\033[1;33m"
#define    BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define    CYAN "\033[1;36m"
#define   WHITE "\033[0;37m"
#define  NORMAL "\033[00m"
#define MONSTER(c) (c == CROC || c == BOSS || c == GOBELIN)

typedef struct tower
{
    int click_on;
    int type;
    int range;
    int damage;
    int level;
    int cost;
    int time_slowed;
    float firerate;
    sfSprite *sprite;
    sfSprite *shoot;
    sfIntRect rect;
    sfVector2i tab_pos;
    sfVector2f pos;
    sfClock *c_shoot;
    struct tower *next;
}tower;

typedef struct tower_list
{
    sfText *price_up;
    sfText *price_sell;
    sfIntRect rect_up;
    sfIntRect rect_sell;
    sfSprite *sprite_up;
    sfSprite *sprite_sell;
    sfRectangleShape *range;
    tower *first;
}t_li;

typedef struct monster
{
    int type;
    int state;
    int life;
    int full_life;
    int slowed;
    sfRectangleShape *showlife_black;
    sfRectangleShape *showlife_green;
    sfIntRect rect;
    sfSprite *sprite;
    sfVector2i tab_pos;
    sfVector2i old_pos;
    sfVector2f pos;
    sfVector2f new_pos;
    float speed;
    sfClock *mouv;
    struct monster *next;
}monster;

typedef struct li_monster
{
    monster *first;
    monster *last;
    sfClock *one;
    sfSoundBuffer *buffer;
    sfSound *death;
    struct li_monster *next_wave;
    struct li_monster *prev_wave;
    int length;
}li_monster;

typedef struct player_ressources
{
    sfSprite *sprite;
    sfClock *clo;
    sfVector2f pos;
    sfIntRect rect;
    int value;
}ply_ress;

typedef struct button
{
    sfSprite *sprite;
    sfFont *font;
    sfText *txt;
    sfVector2f pos;
    sfIntRect rect;
}button;

typedef struct pos_txt
{
    sfVector2f pos;
    sfText *txt;
}pos_txt;

typedef struct tileset
{
    sfSprite *sprite;
    sfIntRect grass;
    sfIntRect path_x;
    sfIntRect path_y;
    sfIntRect top_left;
    sfIntRect top_right;
    sfIntRect bot_left;
    sfIntRect bot_right;
    sfIntRect castle;
    sfIntRect cross;
    sfIntRect tree_1;
    sfIntRect tree_2;
    sfIntRect tree_3;
    sfIntRect hut;
    sfIntRect stone;
    sfIntRect sand;
}tile;

typedef struct difficulty_window
{
    sfSprite *fond;
    sfSprite *diff;
    button *easy;
    button *normal;
    button *hard;
    button *back;
    pos_txt *txt;
}dif_window;

typedef struct level
{
    char **map;
    char **wave;
}lvl;

typedef struct pause_t
{
    sfSprite *fond;
    sfFont *font;
    pos_txt *title;
    pos_txt *resume;
    pos_txt *quit;
    pos_txt *menu;
}pause_s;

typedef struct win_lose
{
    sfFont *font;
    sfSprite *win;
    sfSprite *lose;
    sfClock *clock;
    pos_txt *ret;
    pos_txt *men;
}wlo;

typedef struct hud_s
{
    sfFont *font;
    ply_ress *coin;
    ply_ress *life;
    pos_txt *s_life;
    pos_txt *s_coin;
    sfSprite *interface_towers;
    pos_txt *s_t1;
    pos_txt *i_t1;
    pos_txt *s_t2;
    pos_txt *i_t2;
    pos_txt *s_t3;
    pos_txt *i_t3;
    pos_txt *s_t4;
    pos_txt *i_t4;
    sfIntRect rect_t1;
    sfIntRect rect_t2;
    sfIntRect rect_t3;
    sfIntRect rect_t4;
    sfSprite *tower;
    sfSprite *monster_wave;
    sfSprite *timer;
    pos_txt *int_remaining;
    pos_txt *t1;
    pos_txt *t2;
    pos_txt *t3;
}hud;

typedef struct clicked_on
{
    int state;
    int type;
    int int_range;
    sfRectangleShape *range;
    sfIntRect rect_t1;
    sfIntRect rect_t2;
    sfIntRect rect_t3;
    sfIntRect rect_t4;
    sfSprite *tower;
}clicked;

typedef struct game
{
    int dif;
    int h;
    int send_wave;
    int click_tower;
    sfMusic *music;
    clicked *c;
    t_li *t_li;
    pos_txt *int_time_wave;
    pos_txt *s_time_wave;
    pause_s *my_p;
    sfClock *clock_wave;
    sfClock *clock_h;
    sfClock *move;
    sfClock *wait;
    li_monster *li;
    lvl *level1;
    lvl *level2;
    lvl *level3;
    lvl *choose_one;
    tile *tile;
    sfFont *font;
    dif_window *dif_w;
    hud *hud;
    wlo *win_lose;
}game;


typedef struct credits_s
{
    sfClock *mov_txt;
    sfFont *font;
    button *back;
    pos_txt *defile;
    sfSprite *tete;
    sfMusic *music;
}credits_s;

typedef struct help_s
{
    sfSprite *fond;
    sfFont *font;
    pos_txt *escape;
    pos_txt *grass_h;
    pos_txt *space;
    pos_txt *mouse;
    pos_txt *improvment;
    pos_txt *coin;
    pos_txt *timer;
    pos_txt *monster;
    button *back;
}help_s;

typedef struct menu_next
{
    button *level1;
    button *level2;
    button *loaded;
    button *back;
}menu_next;

typedef struct menu
{
    sfSprite *fond;
    sfFont *font;
    pos_txt *titre;
    pos_txt *credit;
    button *b_play;
    button *b_quit;
    button *b_opt;
    sfMusic *music;
    sfSound *sound_button;
    sfSoundBuffer *sound_buffer;
    menu_next *next;
    sfClock *wait;
}menu;

typedef struct cursor
{
    sfSprite *cursor;
    sfIntRect idle;
    sfIntRect press;
    sfClock *clock;
    int choose;
}cursor;

typedef struct option
{
    sfSprite *fond;
    sfFont *font;
    pos_txt *res;
    pos_txt *sound;
    pos_txt *int_sound;
    pos_txt *int_frame_limit;
    pos_txt *s_frame_limit;
    pos_txt *warning;
    button *high_res;
    button *low_res;
    button *up_sound;
    button *down_sound;
    button *up_frame_limit;
    button *down_frame_limit;
    button *back;
}opt;

typedef struct everything
{
    sfRenderWindow *w;
    credits_s *cre;
    sfTime time;
    int back;
    pause_s *my_p;
    help_s *help;
    game *game;
    int volume;
    unsigned int frame_limit;
    opt *opt;
    menu *menu;
    cursor *cur;
}all;

#endif /* !STRUCT */
