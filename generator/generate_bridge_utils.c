/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** generate_bridge_utils
*/

#include "my_rpg.h"

static int get_vertical_size(char **map, size_t width, size_t height, \
sfVector2i pos);
static int get_horizontal_size(char **map, size_t width, size_t height, \
sfVector2i pos);

int bridge_get_orientation(char **map, size_t width, size_t height, \
sfVector2i pos)
{
    int vertical_size = get_vertical_size(map, width, height, pos);
    int horizontal_size = get_horizontal_size(map, width, height, pos);

    return (vertical_size < horizontal_size);
}

static int get_vertical_size(char **map, size_t width, size_t height, \
sfVector2i pos)
{
    sfVector2i tmp_pos = pos;
    int size = 0;
    int offset = 1;

    for (int i = 0; i < 2; i++) {
        while (map[tmp_pos.y][tmp_pos.x] == 'o') {
            tmp_pos.y += offset;
            size++;
        }
        tmp_pos = pos;
        offset *= -1;
    }
    return (size);
}

static int get_horizontal_size(char **map, size_t width, size_t height, \
sfVector2i pos)
{
    sfVector2i tmp_pos = pos;
    int size = 0;
    int offset = 1;

    for (int i = 0; i<  2; i++) {
        while (map[tmp_pos.y][tmp_pos.x] == 'o') {
            tmp_pos.x += offset;
            size++;
        }
        tmp_pos = pos;
        offset *= -1;
    }
    return (size);
}
