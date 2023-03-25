/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-mydefender-adam.balfet
** File description:
** menu_destroy
*/

#include "my_rpg.h"

void menu_destroy(sfRenderWindow *window, menu_t elem)
{
    sfTexture_destroy(elem.button);
    sfFont_destroy(elem.text_font);
    sfTexture_destroy(elem.back_menu.texture);
    sfTexture_destroy(elem.setting.texture);
    sfRectangleShape_destroy(elem.info_button);
    sfRectangleShape_destroy(elem.back_menu.pict);
    sfRectangleShape_destroy(elem.play_button);
    sfRectangleShape_destroy(elem.quit_button);
    sfRectangleShape_destroy(elem.setting.pict);
    sfText_destroy(elem.info_title);
    sfText_destroy(elem.play_title);
    sfText_destroy(elem.quit_title);
    sfTexture_destroy(elem.back_setting.texture);
    sfRectangleShape_destroy(elem.back_setting.pict);
    free(elem.setting_value);
    sfRenderWindow_close(window);
}

void menu_destroy_to_start(sfRenderWindow *window, menu_t elem)
{
    sfTexture_destroy(elem.button);
    sfFont_destroy(elem.text_font);
    sfTexture_destroy(elem.back_menu.texture);
    sfTexture_destroy(elem.setting.texture);
    sfRectangleShape_destroy(elem.info_button);
    sfRectangleShape_destroy(elem.back_menu.pict);
    sfRectangleShape_destroy(elem.play_button);
    sfRectangleShape_destroy(elem.quit_button);
    sfRectangleShape_destroy(elem.setting.pict);
    sfText_destroy(elem.info_title);
    sfText_destroy(elem.play_title);
    sfText_destroy(elem.quit_title);
    sfTexture_destroy(elem.back_setting.texture);
    sfRectangleShape_destroy(elem.back_setting.pict);
    free(elem.setting_value);
}
