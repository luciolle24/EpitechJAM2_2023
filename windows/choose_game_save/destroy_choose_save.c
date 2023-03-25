/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** destroy_choose_save
*/

#include "my_rpg.h"

static void destroy_choose_save_2(choose_save_t elem)
{
    sfRectangleShape_destroy(elem.new_save_1.pict);
    sfText_destroy(elem.new_save_1.text);
    sfRectangleShape_destroy(elem.new_save_2.pict);
    sfText_destroy(elem.new_save_2.text);
    sfRectangleShape_destroy(elem.new_save_3.pict);
    sfText_destroy(elem.new_save_3.text);
    sfTexture_destroy(elem.simple_back.texture);
    sfRectangleShape_destroy(elem.simple_back.pict);
}

void destroy_choose_save(choose_save_t elem)
{
    sfFont_destroy(elem.font);
    sfTexture_destroy(elem.button);
    sfTexture_destroy(elem.back);
    sfRectangleShape_destroy(elem.back_save_1.pict);
    sfRectangleShape_destroy(elem.back_save_2.pict);
    sfRectangleShape_destroy(elem.back_save_3.pict);
    sfRectangleShape_destroy(elem.quit_button.pict);
    sfText_destroy(elem.quit_button.text);
    sfRectangleShape_destroy(elem.done_save_1.pict);
    sfText_destroy(elem.done_save_1.text);
    sfRectangleShape_destroy(elem.done_save_2.pict);
    sfText_destroy(elem.done_save_2.text);
    sfRectangleShape_destroy(elem.done_save_3.pict);
    sfText_destroy(elem.done_save_3.text);
    destroy_choose_save_2(elem);
}
