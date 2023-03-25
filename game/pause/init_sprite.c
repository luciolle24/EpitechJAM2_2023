/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** init_sprite
*/

#include "game.h"

void init_sprite(sfRectangleShape *sprite, sfVector2f center,
sprite_info_t info)
{
    center.x -= 960;
    center.y -= 500;
    info.position.x += center.x;
    info.position.y += center.y;
    sfRectangleShape_setPosition(sprite, info.position);
    sfRectangleShape_setSize(sprite, info.size);
}

void init_sprite_text(sfText *text, sfVector2f center, sprite_info_t info,
const char *texte)
{
    int policy_size = 50;

    center.x -= 960;
    center.y -= 500;
    sfText_setString(text, texte);
    sfText_setCharacterSize(text, 50);
    info.position.x += center.x;
    info.position.y += center.y;
    info.position.x += (info.size.x / 2);
    info.position.y += (info.size.y / 2);
    info.position.x -= ((my_strlen(texte) / 2) - 1) * policy_size + 10;
    info.position.y -= policy_size - 20;
    sfText_setPosition(text, info.position);
}

void init_button(button_t button, sfVector2f center, sprite_info_t info,
const char *texte)
{
    sfRectangleShape_setOutlineThickness(button.pict, 3);
    init_sprite(button.pict, center, info);
    init_sprite_text(button.text, center, info, texte);
}
