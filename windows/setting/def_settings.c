/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** def_settings
*/

#include "my_rpg.h"

static settings_elem_t init_all_sprite(settings_elem_t elem,
game_setting_t *setting)
{
    int tmp;

    tmp = setting->music_volume;
    init_music_slider(elem.music_bar, elem.music_ball, tmp);
    tmp = setting->sound_volume;
    init_sound_slider(elem.sound_bar, elem.sound_ball, tmp);
    init_music_and_sound(elem.music, (sfVector2f){1320, 125}, "MUSIC");
    init_music_and_sound(elem.sound, (sfVector2f){1320, 325}, "SOUND");
    init_move_up(elem, setting);
    init_move_down(elem, setting);
    init_move_left(elem, setting);
    init_move_right(elem, setting);
    init_attack(elem, setting);
    init_interract(elem, setting);
    init_quit_settings(elem);
    return elem;
}

static settings_elem_t def_settings_2(settings_elem_t elem,
game_setting_t *setting)
{
    elem.simple_back = def_simple_background();
    elem.back_settings = def_back_for_settings();
    elem.music = def_setting_with_text(elem.button, elem.font);
    elem.sound = def_setting_with_text(elem.button, elem.font);
    elem.music_ball = def_slider_ball();
    elem.music_bar = def_slider_bar();
    elem.sound_ball = def_slider_ball();
    elem.sound_bar = def_slider_bar();
    return init_all_sprite(elem, setting);
}

settings_elem_t def_all_sprite_in_settings(game_setting_t *setting)
{
    settings_elem_t elem;
    char *tmp = "asset/utility/TextBoxSquare.png";

    elem.font = sfFont_createFromFile("asset/utility/Avara.ttf");
    elem.button = sfTexture_createFromFile("asset/utility/Button.png", NULL);
    elem.key_back = sfTexture_createFromFile(tmp, NULL);
    elem.move_up = def_setting_with_text(elem.button, elem.font);
    elem.move_left = def_setting_with_text(elem.button, elem.font);
    elem.move_down = def_setting_with_text(elem.button, elem.font);
    elem.move_right = def_setting_with_text(elem.button, elem.font);
    elem.attack = def_setting_with_text(elem.button, elem.font);
    elem.interact = def_setting_with_text(elem.button, elem.font);
    elem.quit_button = def_setting_with_text(elem.button, elem.font);
    elem.key_move_up = def_setting_with_text(elem.key_back, elem.font);
    elem.key_move_left = def_setting_with_text(elem.key_back, elem.font);
    elem.key_move_down = def_setting_with_text(elem.key_back, elem.font);
    elem.key_move_right = def_setting_with_text(elem.key_back, elem.font);
    elem.key_attack = def_setting_with_text(elem.key_back, elem.font);
    elem.key_interact = def_setting_with_text(elem.key_back, elem.font);
    return def_settings_2(elem, setting);
}
