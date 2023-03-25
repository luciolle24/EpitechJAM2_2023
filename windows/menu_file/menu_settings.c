/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** menu_settings
*/

#include "my_rpg.h"

sfRectangleShape *create_setting_button(sfTexture *texture)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();

    pos.x = 1700;
    pos.y = 15;
    size.x = 200;
    size.y = 200;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return sprite;
}

sfRectangleShape *create_setting_back(sfTexture *texture)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();

    pos.x = 1720;
    pos.y = -10;
    size.x = 290;
    size.y = 290;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return sprite;
}

int check_press_sett(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos)
{
    if (m_pos.x >= 1700 * per.x && m_pos.x <= 1905 * per.x)
        return (m_pos.y >= 0 * per.y && m_pos.y <= 270 * per.y) ? 1 : 0;
}
