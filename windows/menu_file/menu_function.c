/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-adam.balfet
** File description:
** menu_function
*/

#include "my_rpg.h"

static game_setting_t *def_basic_setting(void)
{
    game_setting_t *setting = malloc(sizeof(game_setting_t));

    setting->attack = 'a';
    setting->interact = 'e';
    setting->move_up = 'z';
    setting->move_left = 'q';
    setting->move_down = 's';
    setting->move_right = 'd';
    setting->music_volume = 50;
    setting->pronouns = 0;
    setting->sound_volume = 50;
    setting->player_id = '1';
    setting->language = "en";
    return setting;
}

static menu_t def_elem_2(menu_t elem)
{
    sfRectangleShape_setOutlineThickness(elem.info_button, 3);
    sfRectangleShape_setOutlineThickness(elem.play_button, 3);
    sfRectangleShape_setOutlineThickness(elem.quit_button, 3);
    sfRectangleShape_setOutlineThickness(elem.setting.pict, 3);
    elem.setting_value = def_basic_setting();
    return elem;
}

menu_t def_elem(void)
{
    menu_t elem;
    char *tmp_name = "asset/utility/MainMenu.png";

    elem.text_font = sfFont_createFromFile("asset/utility/Avara.ttf");
    elem.button = sfTexture_createFromFile("asset/utility/Button.png", NULL);
    elem.back_menu.texture = sfTexture_createFromFile(tmp_name, NULL);
    elem.back_menu.pict = back_menu(elem.back_menu.texture);
    elem.info_button = create_info_button(elem.button);
    elem.info_title = create_info_title(elem.text_font);
    elem.play_button = create_play_button(elem.button);
    elem.play_title = create_play_title(elem.text_font);
    elem.quit_button = create_quit_button(elem.button);
    elem.quit_title = create_quit_title(elem.text_font);
    tmp_name = "asset/utility/gear.png";
    elem.setting.texture = sfTexture_createFromFile(tmp_name, NULL);
    elem.setting.pict = create_setting_button(elem.setting.texture);
    tmp_name = "asset/utility/TextBoxSquare.png";
    elem.back_setting.texture = sfTexture_createFromFile(tmp_name, NULL);
    elem.back_setting.pict = create_setting_button(elem.back_setting.texture);
    return def_elem_2(elem);
}

sfVector2f get_percentage(sfRenderWindow *window)
{
    sfVector2u vector = sfRenderWindow_getSize(window);
    sfVector2f percentage;

    percentage.x = ((float)vector.x / 1900);
    percentage.y = ((float)vector.y / 1000);
    return percentage;
}
