/*
** EPITECH PROJECT, 2021
** menu_quit
** File description:
** menu_quit
*/

#include "my_rpg.h"

sfRectangleShape *create_quit_button(sfTexture *texture)
{
    sfVector2f pos;
    sfVector2f size;
    sfRectangleShape *sprite = sfRectangleShape_create();

    pos.x = 650;
    pos.y = 685;
    size.x = 600;
    size.y = 100;
    sfRectangleShape_setTexture(sprite, texture, sfTrue);
    sfRectangleShape_setPosition(sprite, pos);
    sfRectangleShape_setSize(sprite, size);
    return sprite;
}

sfText *create_quit_title(sfFont *font)
{
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x = 890;
    pos.y = 700;
    sfText_setString(text, "QUIT");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, pos);
    return text;
}

int check_press_quit(sfRenderWindow *window, sfVector2f per, sfVector2i m_pos)
{
    if (m_pos.x >= 650 * per.x && m_pos.x <= 1260 * per.x)
        return (m_pos.y >= 735 * per.y && m_pos.y <= 835 * per.y) ? 1 : 0;
}
