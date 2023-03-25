/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** destroy
*/

#include "my_rpg.h"

static void destroy_setting_3(settings_elem_t sprite)
{
    sfRectangleShape_destroy(sprite.music.pict);
    sfText_destroy(sprite.music.text);
    sfRectangleShape_destroy(sprite.sound.pict);
    sfText_destroy(sprite.sound.text);
}

static void destroy_setting_2(settings_elem_t sprite)
{
    sfText_destroy(sprite.quit_button.text);
    sfTexture_destroy(sprite.key_back);
    sfRectangleShape_destroy(sprite.key_interact.pict);
    sfText_destroy(sprite.key_interact.text);
    sfRectangleShape_destroy(sprite.key_move_down.pict);
    sfText_destroy(sprite.key_move_down.text);
    sfRectangleShape_destroy(sprite.key_move_left.pict);
    sfText_destroy(sprite.key_move_left.text);
    sfRectangleShape_destroy(sprite.key_move_right.pict);
    sfText_destroy(sprite.key_move_right.text);
    sfRectangleShape_destroy(sprite.key_move_up.pict);
    sfText_destroy(sprite.key_move_up.text);
    sfRectangleShape_destroy(sprite.key_attack.pict);
    sfText_destroy(sprite.key_attack.text);
    sfRectangleShape_destroy(sprite.music_bar);
    sfCircleShape_destroy(sprite.music_ball);
    sfRectangleShape_destroy(sprite.sound_bar);
    sfCircleShape_destroy(sprite.sound_ball);
    destroy_setting_3(sprite);
}

void destroy_setting(settings_elem_t sprite)
{
    sfFont_destroy(sprite.font);
    sfTexture_destroy(sprite.button);
    sfTexture_destroy(sprite.back_settings.texture);
    sfRectangleShape_destroy(sprite.back_settings.pict);
    sfTexture_destroy(sprite.simple_back.texture);
    sfRectangleShape_destroy(sprite.simple_back.pict);
    sfRectangleShape_destroy(sprite.interact.pict);
    sfText_destroy(sprite.interact.text);
    sfRectangleShape_destroy(sprite.move_down.pict);
    sfText_destroy(sprite.move_down.text);
    sfRectangleShape_destroy(sprite.move_left.pict);
    sfText_destroy(sprite.move_left.text);
    sfRectangleShape_destroy(sprite.move_right.pict);
    sfText_destroy(sprite.move_right.text);
    sfRectangleShape_destroy(sprite.move_up.pict);
    sfText_destroy(sprite.move_up.text);
    sfRectangleShape_destroy(sprite.attack.pict);
    sfText_destroy(sprite.attack.text);
    sfRectangleShape_destroy(sprite.quit_button.pict);
    destroy_setting_2(sprite);
}
