/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** my_rpg
*/

#ifndef MY_RPG_H_
    #define MY_RPG_H_
    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <math.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include "structs.h"
    #include "my.h"

// *****************************************
// *               GENERATOR               *
// *****************************************
// \brief generate a grid map
char **generate_map(size_t width, size_t height);
// \brief add all elements in map
char **apply_map(char **map, size_t width, size_t height);
// \brief put the map on terminal
void put_map_char(char **map);
// \brief destroy the map
void destroy_map(char **map);
// \brief add river to map
void add_river(char **map, size_t width, size_t height);
// \breif split the map to 2 parts
void split_map(char **map, size_t width, size_t height);
// \brief remove all '1' and '2'
void restore_map(char **map, size_t width, size_t height);
// \brief add forst to map
void add_forest(char **map, size_t width, size_t height);
// \brief add cities to map
void add_cities(char **map, size_t width, size_t height);
// \brief add bridge to map
void add_bridge(char **map, size_t width, size_t height);
// \brief get the orientation of bridge
int bridge_get_orientation(char **map, size_t width, size_t height, \
sfVector2i pos);

// *****************************************
// *                 UTILS                 *
// *****************************************

// \brief add data to list from start
list_t *add_data_to_list_start(list_t *list, void *data);
// \brief add data to list from end
list_t *add_data_to_list_end(list_t *list, void *data);
// \brief destroy the list
void destroy_list(list_t *list, void (*func_to_destroy)(void *data));

// *****************************************
// *               MENU_FILE               *
// *****************************************

// \brief start the menu
void menu(void);
// \brief def the menu's struct
menu_t def_elem(void);
// \brief create the text that we put on the play button
sfText *create_play_title(sfFont *font);
// \brief create the text that we put on the quit button
sfText *create_quit_title(sfFont *font);
// \brief create the text that we put on the info button
sfText *create_info_title(sfFont *font);
// \brief create the image of the info back for the text
sfRectangleShape *create_back_info(sfTexture *texture);
picture_utility_t create_back_for_the_pause_text(void);
// \brief create the image of the info back
picture_utility_t create_back(void);
// \brief create the image of the menu that we put behind every button
sfRectangleShape *back_menu(sfTexture *texture);
// \brief create the image that we put behind the quit text
sfRectangleShape *create_quit_button(sfTexture *texture);
// \brief create the image that we put behind the info text
sfRectangleShape *create_info_button(sfTexture *texture);
// \brief create the image that we put behind the play text
sfRectangleShape *create_play_button(sfTexture *texture);
// \brief create the gear picture for settings
sfRectangleShape *create_setting_button(sfTexture *texture);
// \brief display the info
void display_game_info(sfRenderWindow *window);
// \brief get the percentage of the window display size
sfVector2f get_percentage(sfRenderWindow *window);
// \brief free every element to be okay with valgrind
void menu_destroy(sfRenderWindow *window, menu_t elem);
// \brief resize every click zone of the button
sfVector2f resize_menu(menu_t elem, sfRenderWindow *window);
// \brief check a zone with the percentage to say if it's press or not
int check_press_info(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos);
// \brief check a zone with the percentage to say if it's press or not
int check_press_quit(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos);
// \brief check a zone with the percentage to say if it's press or not
int check_press_play(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos);
// \brief check a zone with the percentage to say if it's press or not
int check_press_sett(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos);
// \brief free a feew element to start the rpg
void menu_destroy_to_start(sfRenderWindow *window, menu_t elem);
// \brief this is the event for the menu loop
sfVector2f check_event(sfRenderWindow *win, menu_t elem, sfVector2f perc);
// \brief just destroy the menu display
void destroy_menu_display(picture_utility_t back_i, picture_utility_t back);
// \brief create  the back of the settings gear
sfRectangleShape *create_setting_back(sfTexture *texture);


// *****************************************
// *                EVENTS                 *
// *****************************************
// \brief check all events
void check_events(void);


// *****************************************
// *          CHOOSE GAME FILE             *
// *****************************************
// \brief check all events
int choose_file_event(sfRenderWindow *win, menu_t elem, choose_save_t sprites);
// \brief def all of the element of the choose game
int check_if_selected_save_3(sfVector2i mouse_pos);
int check_if_selected_save_2(sfVector2i mouse_pos);
int check_if_selected_save_1(sfVector2i mouse_pos);
int check_if_selected_esc_save(sfVector2i mouse_pos);
choose_save_t def_all_sprite_in_choose_save(void);
void init_first_save(choose_save_t elem);
void init_second_save(choose_save_t elem);
void init_third_save(choose_save_t elem);
void init_quit(choose_save_t elem);
void destroy_choose_save(choose_save_t elem);
void choose_file_to_play(sfRenderWindow *win, menu_t elem);
picture_utility_t def_simple_background(void);

// *****************************************
// *            SETTINGS FILE              *
// *****************************************

void push_button(sfRectangleShape *sprite, sfRenderWindow *window);

// \brief
int settings_event(sfRenderWindow *win, game_setting_t *setting,
settings_elem_t sprite);
void change_settings(sfRenderWindow *win, game_setting_t *setting);
settings_elem_t def_all_sprite_in_settings(game_setting_t *setting);
void init_move_up(settings_elem_t elem, game_setting_t *setting);
void init_move_left(settings_elem_t elem, game_setting_t *setting);
void init_move_right(settings_elem_t elem, game_setting_t *setting);
void init_move_down(settings_elem_t elem, game_setting_t *setting);
void init_interract(settings_elem_t elem, game_setting_t *setting);
void init_attack(settings_elem_t elem, game_setting_t *setting);
void init_quit_settings(settings_elem_t elem);
void destroy_setting(settings_elem_t sprite);
char *letter_to_string(char letter);
void display_sprites_settings(settings_elem_t sprites, sfRenderWindow *win);
int change_the_key(sfText *text, sfRenderWindow *win);
sfCircleShape *def_slider_ball(void);
sfRectangleShape *def_slider_bar(void);
picture_utility_t def_back_for_settings(void);
button_t def_setting_with_text(sfTexture *texture, sfFont *font);
picture_utility_t def_back_of_setting(sfTexture *texture);
void init_music_and_sound(button_t sprit, sfVector2f pos, char *name);
int check_move_up_selected(sfVector2i mouse_pos);
int check_move_down_selected(sfVector2i mouse_pos);
int check_move_left_selected(sfVector2i mouse_pos);
int check_move_right_selected(sfVector2i mouse_pos);
int check_interract_selected(sfVector2i mouse_pos);
int check_attack_selected(sfVector2i mouse_pos);
int get_key_binding(sfRenderWindow *win);

void check_if_a_key_is_selected(sfVector2i mouse_pos, game_setting_t *setting,
sfRenderWindow *win, settings_elem_t elem);

void check_if_a_key_is_selected_2(sfVector2i mouse_pos,
game_setting_t *setting, sfRenderWindow *win, settings_elem_t elem);

void init_music_slider(sfRectangleShape *bar, sfCircleShape *ball,
int percentage);

void check_if_click_on_music_slider(sfRenderWindow *win,
game_setting_t *setting, settings_elem_t sprite, sfEvent event);

void check_if_click_on_sound_slider(sfRenderWindow *win,
game_setting_t *setting, settings_elem_t sprite, sfEvent event);

void init_sound_slider(sfRectangleShape *bar, sfCircleShape *ball,
int percentage);

#endif /* !MY_RPG_H_ */
