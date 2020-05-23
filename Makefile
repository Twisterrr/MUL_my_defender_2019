##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile of the Defender.
##

NAME	=	my_defender

CC		=	gcc -o

SRC	=	src/main.c 											\
		src/game/game.c										\
		src/game/reset_game.c								\
		src/game/in_game/event_game.c						\
		src/game/in_game/pause.c						    \
		src/game/in_game/draw/draw_monster.c				\
		src/game/in_game/draw/draw_map.c					\
		src/game/in_game/draw/draw_map_two.c 				\
		src/game/in_game/draw/draw_play_ress.c 				\
		src/game/in_game/draw/draw_hud.c					\
		src/game/in_game/draw/draw_tower.c					\
		src/game/in_game/draw/draw_tower_two.c 				\
		src/game/in_game/monster/monster.c					\
		src/game/in_game/monster/create_wave.c              \
		src/game/in_game/monster/create_wave_two.c           \
		src/game/in_game/monster/mouv_monster.c             \
		src/game/in_game/monster/utils_mouv_monsters.c 		\
		src/game/in_game/pressed/pressed_towerbar.c			\
		src/game/in_game/pressed/pressed_tower.c			\
		src/game/in_game/tower/put_tower.c					\
		src/game/in_game/tower/tower_attack.c				\
		src/game/in_game/tower/tower_sellup.c				\
		src/game/in_game/tower/up_tower.c					\
		src/game/win_lose/lose.c 							\
		src/game/win_lose/win.c								\
		src/game/choose_dif/choose_difficulty.c				\
		src/game/choose_dif/draw_dif.c						\
		src/game/choose_dif/hover_dif.c						\
		src/game/choose_dif/event_dif.c						\
		src/game/choose_dif/pressed/pressed_back_dif.c		\
		src/game/choose_dif/pressed/pressed_dif.c			\
		src/menu/part_one/menu.c							\
		src/menu/part_one/event_menu.c						\
		src/menu/part_one/draw/draw_menu.c					\
		src/menu/part_one/draw/hover_menu.c					\
		src/menu/part_one/draw/draw_button_menu.c			\
		src/menu/part_one/pressed/pressed_help.c			\
		src/menu/part_one/pressed/pressed_option.c			\
		src/menu/part_one/pressed/pressed_play.c			\
		src/menu/part_one/pressed/pressed_quit.c			\
		src/menu/part_one/pressed/pressed_credits.c			\
		src/menu/part_two/draw/draw_button_menu_next.c		\
		src/menu/part_two/draw/draw_menu_next.c				\
		src/menu/part_two/draw/hover_menu_next.c			\
		src/menu/part_two/pressed/pressed_back_next.c		\
		src/menu/part_two/pressed/pressed_lvl.c				\
		src/menu/part_two/event_menu_next.c					\
		src/menu/part_two/menu_next.c						\
		src/cur_hel_di/cursor/draw_cursor.c					\
		src/cur_hel_di/credits/credits.c					\
		src/cur_hel_di/help/help.c							\
		src/struct/clear/clear_all.c						\
		src/struct/clear/clear_menu.c						\
		src/struct/clear/clear_all_li.c						\
		src/struct/init/init_all.c							\
		src/struct/init/init_cursor.c 						\
		src/struct/init/init_game.c 						\
		src/struct/init/init_option.c						\
		src/struct/init/init_help.c							\
		src/struct/init/init_menu.c							\
		src/struct/init/init_pause.c 						\
		src/struct/init/init_menu_next.c					\
		src/struct/init/init_button.c						\
		src/struct/init/init_pos_txt.c						\
		src/struct/init/init_credits.c						\
		src/struct/init/init_ply_ress.c 					\
		src/struct/init/init_dif_window.c					\
		src/struct/init/init_win_lose.c 					\
		src/struct/init/init_level.c						\
		src/struct/init/init_tile.c							\
		src/struct/init/init_wave.c							\
		src/struct/init/init_monster.c						\
		src/struct/init/init_hud.c							\
		src/struct/init/init_clicked_on.c					\
		src/struct/init/init_tower.c						\
		src/struct/init/init_tower_type.c					\
		src/option/option.c									\
		src/option/event_option.c							\
		src/option/draw/draw_option.c						\
		src/option/draw/hover_option.c						\
		src/option/pressed/pressed_back.c					\
		src/option/pressed/pressed_frame.c					\
		src/option/pressed/pressed_sound.c					\
		src/option/pressed/pressed_res.c					\
		lib/csfml/create_music.c							\
		lib/csfml/create_window.c							\
		lib/csfml/create_sprite.c							\
		lib/csfml/create_txt.c								\
		lib/csfml/draw_button.c								\
		lib/csfml/draw_pos_txt.c							\
		lib/general/my_getnbr.c 							\
		lib/general/int_to_str.c							\
		lib/general/my_putstr.c 							\
		lib/general/my_putchar.c 							\
		lib/general/my_getnbr_n.c							\
		lib/general/len_tab.c								\
		lib/general/count_length_li.c						\
		lib/general/my_strlen.c								\

OBJ    =    $(SRC:.c=.o)

CFLAGS    +=    -Wall -Wextra -I./include

all:    $(NAME)

$(NAME):    $(OBJ)
	gcc -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio

clean:
	rm -f $(OBJ)
	rm -f $(NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
