/*
** EPITECH PROJECT, 2021
** menu_play
** File description:
** menu_play
*/

#include "my_rpg.h"

sfRectangleShape *create_play_button(sfTexture *texture)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();

    pos.x = 650;
    pos.y = 415;
    size.x = 600;
    size.y = 100;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return sprite;
}

sfText *create_play_title(sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = 890;
    pos.y = 430;
    sfText_setString(text, "PLAY");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    return text;
}

int check_press_play(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos)
{
    if (m_pos.x >= 650 * per.x && m_pos.x <= 1260 * per.x)
        return (m_pos.y >= 465 * per.y && m_pos.y <= 565 * per.y) ? 1 : 0;
}
