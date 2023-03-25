/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** def_simple_background
*/

#include "my_rpg.h"

picture_utility_t def_simple_background(void)
{
    picture_utility_t tmp;
    char *name = "asset/utility/simple_background.png";
    sfVector2f pos;
    sfVector2f size;

    pos.x = 0;
    pos.y = 0;
    size.x = 1920;
    size.y = 1000;
    tmp.texture = sfTexture_createFromFile(name, NULL);
    tmp.pict = sfRectangleShape_create();
    sfRectangleShape_setTexture(tmp.pict, tmp.texture, sfTrue);
    sfRectangleShape_setSize(tmp.pict, size);
    sfRectangleShape_setPosition(tmp.pict, pos);
    return tmp;
}
