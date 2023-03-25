/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** settings
*/

#include "my_rpg.h"

void push_button(sfRectangleShape *sprite, sfRenderWindow *window)
{
    sfRectangleShape_setFillColor(sprite, sfBlack);
    sfRectangleShape_setOutlineColor(sprite, sfTransparent);
    sfRenderWindow_drawRectangleShape(window, sprite, NULL);
    sfRenderWindow_display(window);
    sfRectangleShape_setFillColor(sprite, sfWhite);
}

void change_settings(sfRenderWindow *win, game_setting_t *setting)
{
    settings_elem_t sprite = def_all_sprite_in_settings(setting);

    while (settings_event(win, setting, sprite) == 0) {
        display_sprites_settings(sprite, win);
        sfRenderWindow_display(win);
    }
    destroy_setting(sprite);
}
