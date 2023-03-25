/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** select_button
*/

#include "game.h"

int check_if_select(sfVector2i m_pos, sfRectangleShape *sprite,
sfVector2f center)
{
    sfVector2f size_min = sfRectangleShape_getPosition(sprite);
    sfVector2f size_max = sfRectangleShape_getSize(sprite);

    center.x -= 960;
    center.y -= 560;
    size_min.x -= center.x;
    size_min.y -= center.y;
    size_max.x += size_min.x;
    size_max.y += size_min.y;
    if (m_pos.x >= size_min.x && m_pos.x <= size_max.x)
        return (m_pos.y >= size_min.y && m_pos.y <= size_max.y) ? 1 : 0;
}
