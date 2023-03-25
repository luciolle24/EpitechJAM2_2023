/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** genertae_river
*/

#include "my_rpg.h"

static void travel_rec(char **map, sfVector2i pos_1, sfVector2i pos_2, \
vector2ul_t size);
static sfVector2i get_start_pos(size_t width, size_t height);
static sfVector2i get_end_pos(size_t width, size_t height);

void add_river(char **map, size_t width, size_t height)
{
    sfVector2i start_pos = {2, height - 3};
    sfVector2i end_pos = {width - 4, 3};
    vector2ul_t size = {width, height};

    travel_rec(map, start_pos, end_pos, size);
}

static void travel_rec(char **map, sfVector2i pos_1, sfVector2i pos_2, \
vector2ul_t size)
{
    int rnd;

    map[pos_1.y][pos_1.x] = 'o';
    map[pos_1.y][pos_1.x + 1] = 'o';
    map[pos_1.y - 1][pos_1.x] = 'o';
    map[pos_1.y - 1][pos_1.x + 1] = 'o';
    if (pos_1.x == pos_2.x && pos_1.y == pos_2.y)
        return;
    rnd = rand() % 100;
    if (rnd < 50)
        pos_1.x += (pos_1.x < pos_2.x) ? 1 : -1;
    else
        pos_1.y += (pos_1.y < pos_2.y) ? 1 : -1;
    pos_1.x = (pos_1.x > size.x - 2) ? size.x - 2 : pos_1.x;
    pos_1.y = (pos_1.y > size.y - 2) ? size.y - 2 : pos_1.y;
    travel_rec(map, pos_2, pos_1, size);
}

static sfVector2i get_start_pos(size_t width, size_t height)
{
    sfVector2i start_pos = {0};

    start_pos.x = rand() % (width / 10) + 1;
    start_pos.y = height - rand() % (height / 10) - 2;
    return (start_pos);
}

static sfVector2i get_end_pos(size_t width, size_t height)
{
    sfVector2i end_pos = {0};

    end_pos.x = width - rand() % (width / 10) - 2;
    end_pos.y = rand() % (height / 10) + 1;
    return (end_pos);
}
