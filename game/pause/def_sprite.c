/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** def_sprite
*/

#include "game.h"

button_t def_element_with_text(sfTexture *texture, sfFont *font)
{
    button_t sprite;

    sprite.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(sprite.pict, texture, sfTrue);
    sprite.text = sfText_create();
    sfText_setFont(sprite.text, font);
    return sprite;
}

picture_utility_t def_simple_elem(char *texture)
{
    picture_utility_t sprite;

    sprite.texture = sfTexture_createFromFile(texture, NULL);
    sprite.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(sprite.pict, sprite.texture, sfTrue);
    return sprite;
}

sprite_info_t init_info(sfVector2f position, sfVector2f size,
sprite_info_t info)
{
    info.size.x = size.x;
    info.size.y = size.y;
    info.position.x = position.x;
    info.position.y = position.y;
    return info;
}

static void init_all_sprite(game_pause_t sprite, sfVector2f center)
{
    sprite_info_t info;

    info = init_info((sfVector2f){566, 22}, (sfVector2f){780, 960}, info);
    init_sprite(sprite.back_menu.pict, center, info);
    info = init_info((sfVector2f){650, 550}, (sfVector2f){600, 100}, info);
    init_button(sprite.quit, center, info, "QUIT");
    info = init_info((sfVector2f){650, 350}, (sfVector2f){600, 100}, info);
    init_button(sprite.resume, center, info, "RESUME");
    info = init_info((sfVector2f){1720, 0}, (sfVector2f){200, 200}, info);
    sfRectangleShape_setOutlineThickness(sprite.back_setting.pict, 3);
    init_sprite(sprite.back_setting.pict, center, info);
    info = init_info((sfVector2f){1720, 0}, (sfVector2f){200, 200}, info);
    init_sprite(sprite.setting.pict, center, info);
}

game_pause_t def_sprite_of_game_pause(sfVector2f center)
{
    game_pause_t sprite;

    sprite.font = sfFont_createFromFile("asset/utility/Avara.ttf");
    sprite.button = sfTexture_createFromFile("asset/utility/Button.png", NULL);
    sprite.quit = def_element_with_text(sprite.button, sprite.font);
    sprite.resume = def_element_with_text(sprite.button, sprite.font);
    sprite.back_menu = def_simple_elem("asset/utility/back_pause.png");
    sprite.back_setting = def_simple_elem("asset/utility/TextBoxSquare.png");
    sprite.setting = def_simple_elem("asset/utility/gear.png");
    init_all_sprite(sprite, center);
    return sprite;
}
