/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** back_setting
*/

#include "my_rpg.h"

picture_utility_t def_back_for_settings(void)
{
    picture_utility_t tmp;
    char *name = "asset/utility/back_pause.png";
    sfVector2f pos;
    sfVector2f size;

    pos.x = 60;
    pos.y = 0;
    size.x = 1800;
    size.y = 1000;
    tmp.texture = sfTexture_createFromFile(name, NULL);
    tmp.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(tmp.pict, tmp.texture, sfTrue);
    sfRectangleShape_setSize(tmp.pict, size);
    sfRectangleShape_setPosition(tmp.pict, pos);
    return tmp;
}

button_t def_setting_with_text(sfTexture *texture, sfFont *font)
{
    button_t sprite;

    sprite.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(sprite.pict, texture, sfTrue);
    sprite.text = sfText_create();
    sfText_setFont(sprite.text, font);
    return sprite;
}

picture_utility_t def_back_of_setting(sfTexture *texture)
{
    picture_utility_t sprite;

    sprite.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(sprite.pict, texture, sfTrue);
    return sprite;
}
