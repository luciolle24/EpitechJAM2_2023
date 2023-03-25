/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** structs
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_
    #include "my_rpg.h"

// *****************************************
// *               UTILITY                 *
// *****************************************

typedef struct picture_utility {
    sfRectangleShape *pict;
    sfTexture *texture;
} picture_utility_t;

typedef struct list_s {
    struct list_s *next;
    struct list_s *old;
    void *data;
} list_t;

typedef struct vector2ul {
    size_t x;
    size_t y;
} vector2ul_t;

typedef struct button {
    sfText *text;
    sfRectangleShape *pict;
} button_t;

typedef struct sprite_info {
    sfVector2f size;
    sfVector2f position;
} sprite_info_t;

// *****************************************
// *                  NPC                  *
// *****************************************

typedef struct npc {
    struct npc *next;
    sprite_info_t info;
    picture_utility_t npc;
} npc_t;

// *****************************************
// *                 GAME                  *
// *****************************************

typedef struct image_s {
    char *name;
    sfImage *image;
    sfTexture *texture;
} image_t;

typedef struct character_s {
    sfRectangleShape *shape;
    list_t *textures;
    sfVector2f velocity;
    char **map;
    float timer;
    int prev_anim_time;
    int current_anim_index;
} character_t;

typedef struct player_texture_s {
    sfTexture *texture;
    const char *label;
} player_texture_t;

typedef struct core_game {
    list_t *images;
    sfView *view;
    list_t *characters;
    character_t *player;
    sfRectangleShape ***map_tiles;
    sfClock *clock;
    sfFont *font;
    npc_t *pnj;
} core_game_t;

// *****************************************
// *              GAME PAUSE               *
// *****************************************

typedef struct game_pause {
    sfFont *font;
    sfTexture *button;
    picture_utility_t back_menu;
    button_t quit;
    button_t resume;
    picture_utility_t back_setting;
    picture_utility_t setting;
} game_pause_t;

// *****************************************
// *               SETTINGS                *
// *****************************************

typedef struct game_setting {
    int move_up;
    int move_down;
    int move_right;
    int move_left;
    int attack;
    int interact;
    int music_volume;
    int sound_volume;
    int pronouns;
    char *language;
    char player_id;
} game_setting_t;

// *****************************************
// *              MENU STRUCT              *
// *****************************************

typedef struct menu {
    sfFont *text_font;
    sfTexture *button;
    game_setting_t *setting_value;
    sfRectangleShape *info_button;
    sfRectangleShape *quit_button;
    sfRectangleShape *play_button;
    picture_utility_t back_menu;
    picture_utility_t setting;
    picture_utility_t back_setting;
    sfText *info_title;
    sfText *play_title;
    sfText *quit_title;
} menu_t;

// *****************************************
// *         CHOOSE SAVE STRUCT            *
// *****************************************

typedef struct choose_save {
    sfFont *font;
    sfTexture *button;
    sfTexture *back;
    picture_utility_t simple_back;
    picture_utility_t back_save_1;
    picture_utility_t back_save_2;
    picture_utility_t back_save_3;
    button_t new_save_1;
    button_t new_save_2;
    button_t new_save_3;
    button_t done_save_1;
    button_t done_save_2;
    button_t done_save_3;
    button_t quit_button;
} choose_save_t;

// *****************************************
// *        SETTINGS IN THE MENU           *
// *****************************************

typedef struct settings_elem {
    sfFont *font;
    sfTexture *button;
    sfTexture *key_back;
    picture_utility_t simple_back;
    picture_utility_t back_settings;
    sfRectangleShape *music_bar;
    sfCircleShape *music_ball;
    sfRectangleShape *sound_bar;
    sfCircleShape *sound_ball;
    button_t music;
    button_t sound;
    button_t move_up;
    button_t move_down;
    button_t move_right;
    button_t move_left;
    button_t attack;
    button_t interact;
    button_t quit_button;
    button_t key_move_up;
    button_t key_move_down;
    button_t key_move_right;
    button_t key_move_left;
    button_t key_attack;
    button_t key_interact;
} settings_elem_t;

#endif /* !STRUCTS_H_ */
