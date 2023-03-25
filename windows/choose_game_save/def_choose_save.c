/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** def_choose_save
*/

#include "my_rpg.h"

static button_t def_element_with_text(sfTexture *texture, sfFont *font)
{
    button_t sprite;

    sprite.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(sprite.pict, texture, sfTrue);
    sprite.text = sfText_create();
    sfText_setFont(sprite.text, font);
    return sprite;
}

static picture_utility_t def_back_of_save(sfTexture *texture)
{
    picture_utility_t sprite;

    sprite.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(sprite.pict, texture, sfTrue);
    return sprite;
}

static void init_all_sprite(choose_save_t elem)
{
    sfRectangleShape_setOutlineThickness(elem.new_save_1.pict, 3);
    sfRectangleShape_setOutlineThickness(elem.new_save_2.pict, 3);
    sfRectangleShape_setOutlineThickness(elem.new_save_3.pict, 3);
    sfRectangleShape_setOutlineThickness(elem.quit_button.pict, 3);
    init_first_save(elem);
    init_second_save(elem);
    init_third_save(elem);
    init_quit(elem);
}

choose_save_t def_all_sprite_in_choose_save(void)
{
    choose_save_t elem;

    elem.simple_back = def_simple_background();
    elem.font = sfFont_createFromFile("asset/utility/Avara.ttf");
    elem.button = sfTexture_createFromFile("asset/utility/Button.png", NULL);
    elem.back = sfTexture_createFromFile("asset/utility/back_pause.png", NULL);
    elem.back_save_1 = def_back_of_save(elem.back);
    elem.back_save_2 = def_back_of_save(elem.back);
    elem.back_save_3 = def_back_of_save(elem.back);
    elem.done_save_1 = def_element_with_text(elem.button, elem.font);
    elem.done_save_2 = def_element_with_text(elem.button, elem.font);
    elem.done_save_3 = def_element_with_text(elem.button, elem.font);
    elem.new_save_1 = def_element_with_text(elem.button, elem.font);
    elem.new_save_2 = def_element_with_text(elem.button, elem.font);
    elem.new_save_3 = def_element_with_text(elem.button, elem.font);
    elem.quit_button = def_element_with_text(elem.button, elem.font);
    init_all_sprite(elem);
    return elem;
}
