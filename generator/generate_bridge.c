/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** generate_bridge
*/

#include "my_rpg.h"

static void add_one_bridge(char **map, size_t width, size_t height);
static void add_vertical(char **map, sfVector2i pos);
static void add_horizontal(char **map, sfVector2i pos);
static sfVector2i get_random_pos(char **map, size_t width, size_t height);

void add_bridge(char **map, size_t width, size_t height)
{
    for (int i = 0; i < 3; i++)
        add_one_bridge(map, width, height);
}

static void add_one_bridge(char **map, size_t width, size_t height)
{
    sfVector2i pos = get_random_pos(map, width, height);

    if (bridge_get_orientation(map, width, height, pos))
        add_vertical(map, pos);
    else
        add_horizontal(map, pos);
    map[pos.y][pos.x] = 'p';
}

static void add_vertical(char **map, sfVector2i pos)
{
    sfVector2i tmp_pos = pos;
    int offset = 1;

    for (int i = 0; i < 2; i++) {
        while (map[tmp_pos.y][tmp_pos.x] == 'o') {
            map[tmp_pos.y][tmp_pos.x] = 'p';
            tmp_pos.y += offset;
        }
        tmp_pos = pos;
        map[pos.y][pos.x] = 'o';
        offset = -1;
    }
}

static void add_horizontal(char **map, sfVector2i pos)
{
    sfVector2i tmp_pos = pos;
    int offset = 1;

    for (int i = 0; i < 2; i++) {
        while (map[tmp_pos.y][tmp_pos.x] == 'o') {
            map[tmp_pos.y][tmp_pos.x] = 'p';
            tmp_pos.x += offset;
        }
        tmp_pos = pos;
        map[pos.y][pos.x] = 'o';
        offset = -1;
    }
}

static sfVector2i get_random_pos(char **map, size_t width, size_t height)
{
    sfVector2i pos = {0, 0};

    do {
        pos.x = rand() % width;
        pos.y = rand() % height;
    } while (map[pos.y][pos.x] != 'o');
    return (pos);
}
