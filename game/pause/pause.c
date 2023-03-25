/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** pause
*/

#include "game.h"

int game_pause(sfRenderWindow *window, game_setting_t *settings,
sfView *view)
{
    game_pause_t sprites = def_sprite_of_game_pause(sfView_getCenter(view));
    int condition = 0;

    while (condition == 0) {
        display_game_pause(window, sprites);
        sfRenderWindow_display(window);
        condition = game_pause_event(window, settings, view, sprites);
    }
    destroy_game_pause(sprites);
    if (condition == 2)
        return 1;
    return 0;
}