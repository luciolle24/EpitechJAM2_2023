/*
** EPITECH PROJECT, 2022
** B-MUL-200-LYN-2-1-myrpg-lucine.balas
** File description:
** generate_cities
*/

#include "my_rpg.h"

static sfVector2i get_random_pos(char **map, char c, size_t width, \
size_t height);
static void add_city(char **map, sfVector2i pos, char c);

void add_cities(char **map, size_t width, size_t height)
{
    char c = (rand() & 1 == 1) ? '1' : '2';

    add_city(map, get_random_pos(map, '1', width, height), 'k');
    add_city(map, get_random_pos(map, '2', width, height), 'i');
    add_city(map, get_random_pos(map, c, width, height), 's');
}

static sfVector2i get_random_pos(char **map, char c, size_t width, \
size_t height)
{
    sfVector2i pos = {0, 0};

    do {
        pos.x = rand() % width;
        pos.y = rand() % height;
    } while (map[pos.y][pos.x] != c);
    return (pos);
}

static void add_city(char **map, sfVector2i pos, char c)
{
    map[pos.y][pos.x] = c;
}
