/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** check_collider
*/

#include "game.h"

static int check_is_collider(sfVector2f pos, float offset_x, float offset_y, \
char **map);
static char get_target_char(sfVector2f pos, float offset_x, float offset_y, \
char **map);

int check_collider(character_t *player, sfVector2f offset)
{
    sfVector2f pos = sfRectangleShape_getPosition(player->shape);
    sfVector2f size = sfRectangleShape_getSize(player->shape);

    pos.x += offset.x;
    pos.y += offset.y;
    if (pos.x < 0 || pos.y < 0)
        return (1);
    if (check_is_collider(pos, 0, size.y * 0.8, player->map))
        return (0);
    if (check_is_collider(pos, size.x, size.y * 0.8, player->map))
        return (0);
    if (check_is_collider(pos, size.x, size.y, player->map))
        return (0);
    if (check_is_collider(pos, 0, size.y, player->map))
        return (0);
    return (1);
}

static int check_is_collider(sfVector2f pos, float offset_x, float offset_y, \
char **map)
{
    char c = get_target_char(pos, offset_x, offset_y, map);

    if (c == 'x' || c == 'a')
        return (1);
    return (0);
}

static char get_target_char(sfVector2f pos, float offset_x, float offset_y, \
char **map)
{
    int x = (int)(pos.x + offset_x);
    int y = (int)(pos.y + offset_y);

    return (map[y / 200][x / 200]);
}
