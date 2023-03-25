/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "my_rpg.h"

// \breif start running the game
void run_game(sfRenderWindow *window, game_setting_t *settings, int id);
// \brief displayy the whole game
void display_game(sfRenderWindow * window, core_game_t game);
// \brief check all events for game
int check_game_events(sfRenderWindow *win, game_setting_t *settings,
core_game_t game);
// \brief init the game data
char **init_game_data(size_t width, size_t height);
// \brief get tiles for the map
sfRectangleShape ***get_map_tiles(list_t *images, char ***map);
// \brief init the images list
list_t *init_images(void);
// \breif destroy the image element
void destroy_image_list(void *data);
// \brief get the texture from a char
sfTexture *get_texture_from_char(char **map, list_t *images, size_t x, \
size_t y);
// \brief get the texture nbr
int get_texture_nbr(char **m, vector2ul_t p, char c);
// \brief get the texture nbr for bridge
int get_texture_bridge_nbr(char **m, vector2ul_t p, char c);
// \brief destroy map tiles
void destroy_map_tiles(sfRectangleShape ***map_tiles);
// \brief get the time elapsed
float *get_time_elapsed(void);
// \brief get the delta time
float *get_delta_time(void);
// \brief init all characters
list_t *init_characters(sfView *view, char **map);
// \update all characters
void update_characters(list_t *characters, sfRenderWindow *window, \
sfClock *clock, sfView *view);
// \brief init all monsters
void init_monsters(list_t **characters, char **map);
// \brief update all monsters
void update_monsters(list_t *characters, sfRenderWindow *window);

// *****************************************
// *                PLAYER                 *
// *****************************************
// \brief init the player datas
character_t *init_player(sfView *view);
// \brief destroy the player
void destroy_player(character_t *player);
// \brief update states and display the player
void update_player(character_t *player, sfRenderWindow *window, sfClock *clock,
sfView *view);
// \brief anim the player
void anim_player(character_t *player, float time_elapsed, char *label);
// \brief move the player
void move_player(character_t *player, float offset_x, float offset_y);
// \brief check the collider
int check_collider(character_t *player, sfVector2f offset);

// *****************************************
// *           GAME PAUSE FILE             *
// *****************************************

int check_if_esc_is_press(sfEvent event, game_setting_t *settings,
sfView *view, sfRenderWindow *window);
int game_pause(sfRenderWindow *window, game_setting_t *settings,
sfView *view);
game_pause_t def_sprite_of_game_pause(sfVector2f center);
void init_sprite(sfRectangleShape *sprite, sfVector2f center,
sprite_info_t info);
void init_sprite_text(sfText *text, sfVector2f center, sprite_info_t info,
const char *texte);
void display_game_pause(sfRenderWindow *window, game_pause_t sprites);
int game_pause_event(sfRenderWindow *window, game_setting_t *settings,
sfView *view, game_pause_t sprites);

//MODULAIRE

int check_if_select(sfVector2i m_pos, sfRectangleShape *sprite,
sfVector2f center);
sprite_info_t init_info(sfVector2f position, sfVector2f size,
sprite_info_t info);
void init_sprite_text(sfText *text, sfVector2f center, sprite_info_t info,
const char *texte);
void init_button(button_t button, sfVector2f center, sprite_info_t info,
const char *texte);
void init_sprite(sfRectangleShape *sprite, sfVector2f center,
sprite_info_t info);
picture_utility_t def_simple_elem(char *texture);
button_t def_element_with_text(sfTexture *texture, sfFont *font);
void destroy_game_pause(game_pause_t sprite);

// *****************************************
// *                 NPC                   *
// *****************************************

npc_t *def_all_npc(sfView *view);
void display_npc(npc_t *all_pnj, sfRenderWindow *window);
void check_if_a_npc_is_select(core_game_t game, character_t *player,
sfRenderWindow *window, game_setting_t *setting);

#endif /* !GAME_H_ */
