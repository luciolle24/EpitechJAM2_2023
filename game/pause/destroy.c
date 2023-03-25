/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** destroy
*/

#include "game.h"

static void destroy_button(button_t button)
{
    sfText_destroy(button.text);
    sfRectangleShape_destroy(button.pict);
}

static void destroy_picture(picture_utility_t picture)
{
    sfTexture_destroy(picture.texture);
    sfRectangleShape_destroy(picture.pict);
}

void destroy_game_pause(game_pause_t sprite)
{
    sfTexture_destroy(sprite.button);
    sfFont_destroy(sprite.font);
    destroy_button(sprite.quit);
    destroy_button(sprite.resume);
    destroy_picture(sprite.back_menu);
    destroy_picture(sprite.back_setting);
    destroy_picture(sprite.setting);
}
